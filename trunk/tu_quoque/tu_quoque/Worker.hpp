// Westley Hennigh

// Worker.hpp : This is the base for all "workers" who process tasks.

#pragma once

struct Task;


class Worker
{
    // Construction / Destruction -------
public:
    Worker ();
    virtual ~Worker ();

    virtual void VInit () = 0;


    // Job Manager -------
public:
    void Init ();
    virtual void DelegateTask ( Task* task ) = 0;

    int GetId () const  { return id; }
    void SetId ( int id_ )  { id = id_; }

    int job_id;

private:
    int id;
    // -------
};
