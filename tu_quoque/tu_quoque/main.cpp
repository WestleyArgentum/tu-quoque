// Westley Hennigh

#include "Console.hpp"

#include <Windows.h>


int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int nCmdShow )
{
    CreateConsole();

    RemoveConsole();
    return 0;
}