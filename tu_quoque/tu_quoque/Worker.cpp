// Westley Hennigh

// Worker.cpp

#include "Worker.hpp"
#include "JobManager.hpp"


Worker::Worker() : id(0)
{}


Worker::~Worker()
{}


void Worker::Init( JobManager* manager_ )
{
    job_id = -1;
    manager = manager_;

    // initialize the derived worker
    VInit();
}

