// Westley Hennigh

// JobManager.hpp : 

/*
    "The difference between stupid and intelligent people — and this is true whether or not
    they are well-educated — is that intelligent people can handle subtlety. They are not
    baffled by ambiguous or even contradictory situations — in fact, they expect them and are
    apt to become suspicious when things seem overly straightforward."
        - Neal Stephenson (The Diamond Age)
*/

#pragma once

#include <queue>
#include <vector>
#include <hash_map>

#include "ResourcePool.hpp"
#include "Worker.hpp"
#include "HashCompare.hpp"
#include "Mutex.hpp"

#define MAX_TASKS 1000


struct Task
{
    unsigned id;
};


class JobManager
{
    // Construction / Destruction -------
    JobManager  ();
    ~JobManager ();


    // User Interface -------
    void Run ();

    void Test_FillWithRandomCrap ();


    // Task Management -------
private:
    void AddTask      ( Task* task_ );
    void CompleteTask ( unsigned id );
    void DelegateTask ( unsigned id, Worker* worker );
    void ResetTask    ( unsigned id );

    struct TaskInfo
    {
        // unique id for this task
        unsigned id;

        enum TIStatus : unsigned
        {
            TI_Idle = 1,
            TI_InProgress,
            TI_Complete
        };
        TIStatus status;

        // unique id of the worker who is in charge of the associated task
        unsigned worker_id;

        // the actual task
        Task* task;
    };

    TaskInfo tasks[ MAX_TASKS ];  // all the tasks for the current job
    int num_tasks;                // the total number of tasks
    int num_tasks_idle;           // used to efficiently hand out tasks to workers
    int num_tasks_remaining;      // used to efficiently determine when we are done
    int last_task;                // used to mark the last place we were in the task list
    Mutex mutex_tasks;

    // Worker Management -------
private:
    friend class Worker;
    void SignalWorkerAvailable   ( Worker* worker );
    void SignalWorkerUnavailable ( Worker* worker );

    std::priority_queue<Worker*> workers_available;


    // Resource Pool Management -------
public:
    void RegisterPool ( ResourcePool* pool );
    void RemovePool   ( ResourcePool* pool );

private:
    typedef std::vector<ResourcePool*> ResourcePoolList;
    ResourcePoolList resource_pools;
    // -------

};
