#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

DWORD getProcId(const wchar_t* procName);

