// Westley Hennigh

#include <Windows.h>

#include "Console.hpp"
#include "JobManager.hpp"


int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int nCmdShow )
{
    CreateConsole();

    JobManager test_manager;
    test_manager.Init();

    ThreadPool test_pool( 3 );

    test_manager.Test_FillWithRandomCrap();

    test_manager.Run();

    RemoveConsole();
    return 0;
}