// Westley Hennigh

// ResourcePool.cpp

#include "ResourcePool.hpp"

#define NULL 0


ResourcePool::ResourcePool() : manager(NULL)
{}


ResourcePool::~ResourcePool()
{}


void ResourcePool::Initialize( JobManager* manager_ )
{
    manager = manager_;

    // initialize the derived class
    VInitialize();
}


void ResourcePool::Release()
{
    VRelease();
}
