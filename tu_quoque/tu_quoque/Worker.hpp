// Westley Hennigh

// Worker.hpp : This is the base for all "workers" who process tasks.

#pragma once

struct Task;
class JobManager;


class Worker
{
public:
    Worker ();
    virtual ~Worker ();

    virtual void VInit () = 0;  // Derived class initialization
    void Init ( JobManager* manager_ );  // Base class init is called by Pool

    // DelegateTask does the necessary work to get a task going.
    // It will be called by the manager.
    virtual void DelegateTask ( Task* task ) = 0;

public:
    int id;  // This workers unique identifier
    int job_id;  // This workers current task
    JobManager* manager;  // This workers manager

};
