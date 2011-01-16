// Westley Hennigh

// ResourcePool.hpp : This is the base for "pools" that will provide resources in the form
//                    of workers to the manager.

#pragma once

class JobManager;


class ResourcePool
{
public:
    ResourcePool ();

    // Job Manager -------
public:
    void Initialize ( JobManager* manager_ );  // called upon addition to a manager
    void Release    ();                        // called upon removal from a manager

private:
    JobManager* manager;
    // -------

};
