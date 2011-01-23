// Westley Hennigh

// JobManager.cpp

#include "JobManager.hpp"
#include "DebugDia.hpp"


// Construction / Destruction -----------------

JobManager::JobManager()
{}


JobManager::~JobManager()
{}


void JobManager::Init()
{
    // set up tasks
    Reset();

    // set up pools and workers
    curr_worker_id = 1;
    for ( ResourcePoolList::iterator it = resource_pools.begin(); it != resource_pools.end(); ++it )
        (*it)->Initialize( this );
}


void JobManager::Reset()
{
    Lock lock ( mutex_tasks );

    num_tasks = 0;
    num_tasks_idle = 0;
    num_tasks_remaining = 0;
    last_task = 0;
}


// User Interface -----------------------------

void JobManager::Run()
{
    {
        Lock lock( mutex_tasks );

        // distribute tasks to all the workers to get the ball rolling
        while ( workers_available.size() && num_tasks_idle )
        {
            DelegateTask( last_task++, workers_available.top() );
            workers_available.pop();
        }
    }

    // wait until all the tasks signal
    WaitForMultipleObjects( num_tasks, task_events, TRUE, 0 );
}


void JobManager::Test_FillWithRandomCrap()
{
    for ( unsigned i = 0; i < 5; ++i )
    {
        Task* task = new Task();
        AddTask( task );
    }
}


// Task Management ----------------------------

void JobManager::AddTask( Task* task_ )
{
    Lock lock( mutex_tasks );
 
    TaskInfo& info = tasks[ num_tasks ];

    // set up the new task info
    info.id = num_tasks++;  // inc the number of tasks
    info.status = TaskInfo::TI_Idle;
    info.task = task_;

    // leave the worker_id be, it will not be used until there is
    // this task is given to a worker
}


void JobManager::CompleteTask( unsigned id )
{
    Lock lock( mutex_tasks );

    tasks[ id ].status = TaskInfo::TI_Complete;
    --num_tasks_remaining;
}


void JobManager::DelegateTask( unsigned id, Worker* worker )
{
    // NEED RECURSIVE LOCKS
    Lock lock( mutex_tasks );

    ErrorIf( tasks[ id ].status == TaskInfo::TI_InProgress, "Error: Trying to delegate task that is already in progress." );
    ErrorIf( tasks[ id ].status == TaskInfo::TI_Complete, "Error: Trying to delegate task that is already complete." );

    TaskInfo& task_info = tasks[ id ];

    task_info.status = TaskInfo::TI_InProgress;
    task_info.worker_id = worker->GetId();
    --num_tasks_idle;

    worker->DelegateTask( task_info.task );
}


void JobManager::ResetTask( unsigned id )
{
    Lock lock( mutex_tasks );

    ErrorIf( tasks[ id ].status == TaskInfo::TI_Idle, "Error: Trying to reset an idle task" );
    ErrorIf( tasks[ id ].status == TaskInfo::TI_Complete, "Error: Trying to reset a finished task" );

    ++num_tasks_idle;  // always inc idle tasks even if we re-delegate it immediately

    Worker* worker;
    while ( workers_available.size() )
    {
        worker = workers_available.top();
        workers_available.pop();

        if ( worker->GetId() != -1 )
        {
            DelegateTask( id, worker );
            return;
        }
    }

    tasks[ id ].status = TaskInfo::TI_Idle;
}


// Worker Management --------------------------

void JobManager::SignalWorkerAvailable( Worker* worker )
{
    ErrorIf( worker->GetId() < 1, "Error: Worker is invalid." );

    Lock lock( mutex_tasks );

    if ( num_tasks_idle )
    {
        // loop from the last place we found an idle task and look for another
        while ( tasks[ ++last_task %= num_tasks ].status != TaskInfo::TI_Idle )
        {}
        DelegateTask( last_task, worker );
    }
    else
        workers_available.push( worker );
}


void JobManager::SignalWorkerUnavailable( Worker* worker )
{
    if ( worker->job_id != -1 )      // reset the workers job if needed
        ResetTask( worker->job_id );
    else                             // otherwise set the workers id to invalid
        worker->SetId( -1 );
}


void JobManager::RegisterWorker( Worker* worker )
{
    worker->SetId( curr_worker_id++ );
}


// Resource Pool Management -------------------

void JobManager::RegisterPool( ResourcePool* pool )
{
    // save the pool then init it
    resource_pools.push_back( pool );
    pool->Initialize( this );
}


void JobManager::RemovePool( ResourcePool* pool )
{
    // find the pool and remove it
    ResourcePoolList::iterator it = std::find( resource_pools.begin(), resource_pools.end(), pool );
    ErrorIf ( it == resource_pools.end(), "Error: Pool being removed from manager was never added" );

    // release will cause all of this pools workers to signal that they are unavailable
    pool->Release();

    resource_pools.erase( it );
}

// --------------------------------------------
