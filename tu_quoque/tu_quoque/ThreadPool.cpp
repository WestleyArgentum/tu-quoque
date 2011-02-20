// Westley Hennigh

// ThreadPool.cpp

#include "ThreadPool.hpp"


ThreadPool::ThreadPool( int num_threads_ ) : num_threads(num_threads_)
{
    workers.reserve( num_threads_ );  // just for kicks
}


ThreadPool::~ThreadPool()
{}


void ThreadPool::VInitialize()
{
    // create a bunch of threads
    for ( int i = 0; i < num_threads; ++i )
    {
        workers.push_back( new ThreadWorker );
        workers.back()->Init( manager );
    }
}


void ThreadPool::VRelease()
{
    // disconnect and delete all the workers
    WorkerList::iterator it, end = workers.end();
    for ( it = workers.begin(); it != end; ++it )
        delete *it;

    workers.clear();
}
