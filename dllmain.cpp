
#include "Main.h"


FILE* pFile = nullptr;

void initialize()
{
    jsize count;
    if (JNI_GetCreatedJavaVMs(&mc.vm, 1, &count) != JNI_OK || count == 0)
    {
        return;
    }
    jint res = mc.vm->GetEnv((void**)&mc.env, JNI_VERSION_1_6);
    if (res == JNI_EDETACHED)
    {
        res = mc.vm->AttachCurrentThread((void**)&mc.env, nullptr);
    }
    if (res != JNI_OK)
    {
        return;
    }

    if (mc.env != nullptr)
    {
        run();
    }
    else
    {
        std::cout << "env = nullptr\n";
        Sleep(100);
    }

    mc.vm->DestroyJavaVM();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        AllocConsole();
        freopen_s(&pFile, "CONUT$", "w", stdout);
        initialize();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

