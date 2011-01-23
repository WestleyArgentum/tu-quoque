// Westley Hennigh

// Worker.cpp

#include "Worker.hpp"


Worker::Worker() : id(0)
{}


Worker::~Worker()
{}


void Worker::Init( unsigned id_ )
{
    id = id_;
    job_id = -1;

    // initialize the derived worker
    VInit();
}

