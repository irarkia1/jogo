//libs creat
#include "windows.h"
//libs standard
#include <iostream>



bool Windows::init(HINSTANCE hInstance, int nCmdShow){
        const wchar_t CLASS_NAME[] = L"Teste janela";

        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(WNDCLASSEXW);
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_CROSS);
        wc.lpszClassName = CLASS_NAME;


    if(!RegisterClassExW(&wc)){
         MessageBoxW(NULL, L"Falha ao registrar a classe da janela", L"Erro", MB_OK | MB_ICONERROR);
        return 0;
    }
    

    hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"ACREDITO SER JANELA",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800,600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    //Tirando a opcao de redmencionar a tela
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~WS_SIZEBOX;
    SetWindowLong(hwnd, GWL_STYLE, style);
    
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
    
    static HDC hdcMem;
    static HBITMAP hbmMem;
    static HGDIOBJ hOldBmp;
    
    switch (uMsg){
        //ESTAMOS CRIANDO OS PLAYERS
        case WM_PAINT:{
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            Areas areas;
            areas.DesenharAreas(hwnd, hdc); 
    
            Players players;
            players.CriarPlayers(hwnd, hdc);
            
            EndPaint(hwnd, &ps);
            break;
        }
        //ESTAMOS FORNCANDO A COR DE FUNDO
        case WM_CREATE:{
            SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(255, 255, 255)));  // Definir fundo branco
            break;
        }
        //controle do mouse  : coleta start X e Y
        case WM_LBUTTONDOWN:{
            PlayersMove playersMove;
            playersMove.PtSrt(lParam);
            break;
        }
        //pegando as marcacoes do mouse
        case WM_MOUSEMOVE:{
            PlayersMove playersMove;
            playersMove.DraggingMouse(hwnd, lParam);
            break;
        }
        //Quando solta o mouse : coleta End X e 
        case WM_LBUTTONUP:{
            PlayersMove playersMove;
            playersMove.PtEnd(lParam, hwnd, hdcMem, hbmMem, hOldBmp);
            break;
        }
        //liberar memoria 
        case WM_CLOSE:{
            PostQuitMessage(0);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}