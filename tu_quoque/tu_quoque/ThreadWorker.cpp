// Westley Hennigh

// ThreadWorker.cpp

#include "ThreadWorker.hpp"
#include "JobManager.hpp"


// TaskProcessorThread ********************

TaskProcessorThread::TaskProcessorThread()
{}


TaskProcessorThread::~TaskProcessorThread()
{}


// Active Object Interface ----------------

void TaskProcessorThread::InitThread()
{}


void TaskProcessorThread::Run()
{}


void TaskProcessorThread::FlushThread()
{}


// ThreadWorker ***************************

// Construction / Destruction -------------

ThreadWorker::ThreadWorker()
{}


ThreadWorker::~ThreadWorker()
{
    Kill();
}


void ThreadWorker::VInit()
{
    Wake();
}


// Job Manager ----------------------------

void ThreadWorker::DelegateTask( Task* task )
{}


// Active Object Interface ----------------

void ThreadWorker::InitThread()
{

}


void ThreadWorker::Run()
{
    manager->RegisterWorker( this );

    while ( !isDying )
    {
        // Signal that this worker is available
        if ( manager->SignalWorkerAvailable( this ) )
        {
            // wait for a new job if we were not given one
            WaitForSingleObject( );
        }
    }

}


void ThreadWorker::FlushThread()
{

}

// ----------------------------------------
