// Westley Hennigh

// ThreadWorker.hpp : This is a Worker that utilizes a thread.

#pragma once

#include "ActiveObject.hpp"
#include "Worker.hpp"


class TaskProcessorThread : public ActiveObject
{
public:
    TaskProcessorThread ();
    virtual ~TaskProcessorThread ();

    // Active Object Interface -------
public:
    virtual void InitThread  ();
    virtual void Run         ();
    virtual void FlushThread ();

    // -------

};

// *******

class ThreadWorker : public Worker
{
    // Construction / Destruction -------
public:
    ThreadWorker ();
    virtual ~ThreadWorker ();

    virtual void VInit ();

    // Job Manager -------
    virtual void DelegateTask ( Task* task );


    // Thread -------
    TaskProcessorThread tp_thread;

    // -------


};
