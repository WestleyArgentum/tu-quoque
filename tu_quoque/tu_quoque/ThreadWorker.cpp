// Westley Hennigh

// ThreadWorker.cpp

#include "ThreadWorker.hpp"


// TaskProcessorThread ********************

TaskProcessorThread::TaskProcessorThread()
{}


TaskProcessorThread::~TaskProcessorThread()
{}


// Active Object Interface ----------------

void TaskProcessorThread::InitThread()
{}


void TaskProcessorThread::Run()
{}


void TaskProcessorThread::FlushThread()
{}


// ThreadWorker ***************************

// Construction / Destruction -------------

ThreadWorker::ThreadWorker()
{}


ThreadWorker::~ThreadWorker()
{
    tp_thread.Kill();
}


void ThreadWorker::VInit()
{
    tp_thread.Wake();
}


// Job Manager ----------------------------

void ThreadWorker::DelegateTask( Task* task )
{}

// ----------------------------------------
