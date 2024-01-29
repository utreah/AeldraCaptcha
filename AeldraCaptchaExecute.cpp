
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "proc.h"
#include <string>
#include <processthreadsapi.h>
#pragma warning(disable : 4996)
int main()
{        
    wchar_t procName[20] = L"bin_aeldra_xxx.exe";
    wchar_t binVersion[] = L"";
    std::wcin >> binVersion;
    wchar_t* bin;
    bin = wcsstr(procName, L"xxx");
    wcsncpy(bin, binVersion, sizeof(binVersion - 1));
    wcscat(procName, L".exe");
    std::wcout << procName << std::endl;;

    std::cout << "NOT: Bu yazılım tüm clientleri aynı anda kapatmaz." << std::endl;
    std::cout << "Clientler tek tek belirlediğiniz zamana göre kapanır." << std::endl;
    std::cout << "Örnek olarak, eğer bekleme süresini 10dk olarak ayarlarsanız ilk client programı çalıştırdığınız gibi." << std::endl;
    std::cout << "diğer client ise 10 dakika ardından kapanır." << std::endl;
    std::cout << "Yönetici olarak çalıştırmayı unutmayın. -Utreah" << std::endl;
    unsigned int sleepTime;
    std::cout << "Sleep Time to terminate the process(in minutes) : ";
    std::cin >> sleepTime;
    system("cls");
    while (true)
    {
        DWORD procId = getProcId(procName);
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

