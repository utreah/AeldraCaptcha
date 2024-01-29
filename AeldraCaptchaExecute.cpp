
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "proc.h"
#include <processthreadsapi.h>

int main()
{        
    std::cout << "NOTE: This software won't terminate all aeldra client(s) at the same time." << std::endl;
    std::cout << "Each client will be terminated after X minutes." << std::endl;
    std::cout << "For example, if you set sleepTime for 10, first client will be terminated as soon as you run this." << std::endl;
    std::cout << "And, next client will be terminated after 10 mins" << std::endl;
    std::cout << "DO NOT FORGET TO RUN IT AS ADMINSTRATOR! -Utreah" << std::endl;
    unsigned int sleepTime;
    std::cout << "Sleep Time to terminate the process(in minutes) : ";
    std::cin >> sleepTime;
    system("cls");
    while (true)
    {
        DWORD procId = getProcId(L"bin_aeldra_473.exe");
        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
        std::cout << "Process Id :" << procId<<std::endl;

        DWORD dwExit = 0;
        while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
        {
            TerminateProcess(hProcess, 0);
            std::cout << "Process has been terminated!" << std::endl;
            Sleep((sleepTime)*60000);
        }
    }
}

