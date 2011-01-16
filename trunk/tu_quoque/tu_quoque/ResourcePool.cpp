// Westley Hennigh

// ResourcePool.cpp

#include "ResourcePool.hpp"

#define NULL 0


ResourcePool::ResourcePool() : manager(NULL)
{}


void ResourcePool::Initialize( JobManager* manager_ )
{
    manager = manager_;
}


void ResourcePool::Release()
{

}