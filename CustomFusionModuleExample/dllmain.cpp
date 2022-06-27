// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <cstdio>
#include <iostream>


struct buildTypeInfo
{
    const wchar_t* buildTypeName;
    int buildFlags;
    const wchar_t* fileSelectorFilter;
    const wchar_t* fileSelectorTitle;
    const wchar_t* fileSelectorDefExt;
};

static buildTypeInfo buildTypes[3];

extern "C"
{

    __declspec(dllexport) int GetNumberOfBuildTypes()
    {
        return sizeof(buildTypes) / sizeof(buildTypes[0]);
    }
    __declspec(dllexport) wchar_t* __stdcall GetBuildTypeName(int a1)
    {
        return _wcsdup(buildTypes[a1].buildTypeName);

    }
    __declspec(dllexport) int __stdcall GetBuildType(int a1)
    {
        return a1+ buildTypes[a1].buildFlags;

    }
    __declspec(dllexport) int __stdcall GetBuildOptions(int a1)
    {
        return 1;
    }
    __declspec(dllexport) wchar_t* __stdcall GetFileSelectorFilter(int a1)
    {
        return _wcsdup(buildTypes[a1].fileSelectorFilter);

    }
    __declspec(dllexport) wchar_t* __stdcall GetFileSelectorTitle(int a1)
    {
        return _wcsdup(buildTypes[a1].fileSelectorTitle);

    }
    __declspec(dllexport) wchar_t* __stdcall GetFileSelectorDefExt(int a1)
    {
        return _wcsdup(buildTypes[a1].fileSelectorDefExt);

    }
    __declspec(dllexport) int __stdcall Build(wchar_t* outPath, wchar_t* ccnPath, int buildType, wchar_t* a4)
    {
        switch (buildType)
        {
        case 0:
            printf("build type 1 executed");
            break;
        case 1:
            printf("build type 2 executed");
            break;
        case 2:
            printf("build type 3 executed");

            break;
        }
            
        return 0;
    }
}

void main()
{
    AllocConsole();
    freopen("CONOUT$", "w", stdout);


    buildTypes[0].buildFlags = 0x30000000;
    buildTypes[0].buildTypeName = L"Build Type 1";
    buildTypes[0].fileSelectorDefExt = L".exe";
    buildTypes[0].fileSelectorFilter = L"Fusion game|*.exe";
    buildTypes[0].fileSelectorTitle = L"File Selector 1";

    buildTypes[1].buildFlags = 0x30000000;
    buildTypes[1].buildTypeName = L"Build Type 2";
    buildTypes[1].fileSelectorDefExt = L".exe";
    buildTypes[1].fileSelectorFilter = L"Fusion game|*.exe";
    buildTypes[1].fileSelectorTitle = L"File Selector 3";

    buildTypes[2].buildFlags = 0x30000000;
    buildTypes[2].buildTypeName = L"Build Type 3";
    buildTypes[2].fileSelectorDefExt = L".exe";
    buildTypes[2].fileSelectorFilter = L"Fusion game|*.exe";
    buildTypes[2].fileSelectorTitle = L"File Selector 3";



}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        main();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

