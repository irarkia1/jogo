//libs creat
#include "windows.h"

bool Windows::init(HINSTANCE hInstance, int nCmdShow){
        const wchar_t CLASS_NAME[] = L"Teste janela";

        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(WNDCLASSEXW);
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = CLASS_NAME;


    // if(!RegisterClassExW(&wc)){
    //     //MessageBox(NULL, L"Falhar ao criar janela", L"Erro", MB_ICONERROR);
    //      MessageBox(NULL, L"Falha ao registrar a classe da janela", L"Erro", MB_OK | MB_ICONERROR);
    //     return 0;
    // }
    RegisterClassExW(&wc);

    hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"ACREDITO SER JANELA",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800,500,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if(!hwnd){
        return false;
    }

    ShowWindow(hwnd, nCmdShow);
    return true;
}

HWND Windows::GetHandle(){
    return hwnd;
}

LRESULT CALLBACK Windows::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg){
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}