// Westley Hennigh

// ThreadPool.hpp : This is a Resource Pool that will manage ThreadWorkers.

#pragma once

#include <vector>

#include "ResourcePool.hpp"
#include "ThreadWorker.hpp"


class ThreadPool : public ResourcePool
{
    // Construction / Destruction -------
public:
    ThreadPool ( int num_threads_ );
    virtual ~ThreadPool ();

    virtual void VInitialize ();
    virtual void VRelease ();


    // Workers -------
private:
    typedef std::vector<ThreadWorker*> WorkerList;
    WorkerList workers;
    int num_threads;

    // -------

};
