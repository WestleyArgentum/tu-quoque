// Westley Hennigh

// Worker.hpp : This is the base for all "workers" who process tasks.

#pragma once

struct Task;


class Worker
{
    // Job Manager -------
public:
    void Init ( unsigned id_ );
    void DelegateTask ( Task* task );

    int GetId () const  { return id; }
    void SetId ( int id_ )  { id = id_; }

    int job_id;

private:
    int id;
    // -------
};
