// Westley Hennigh

// ThreadWorker.hpp : This is a Worker that utilizes a thread.

#pragma once

#include "ActiveObject.hpp"
#include "Worker.hpp"


class TaskProcessorThread : public SD::ActiveObject
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

class ThreadWorker : public Worker, public SD::ActiveObject
{
    // Construction / Destruction -------
public:
    ThreadWorker ();
    virtual ~ThreadWorker ();

    virtual void VInit ();


    // Job Manager -------
    virtual void DelegateTask ( Task* task );


    // Active Object Interface -------
public:
    virtual void InitThread  ();
    virtual void Run         ();
    virtual void FlushThread ();


    // Event Data
    // -------

};
