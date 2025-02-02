//libs standard

//Libs create
#include "areas.h"

void Areas::DesenharAreas(HWND hwnd, HDC hdc){
    PAINTSTRUCT ps;
    //HDC hdc = hdc;

    PintarAreas(hdc);
    EndPaint(hwnd, &ps);
}

void Areas::PintarAreas(HDC hdc){
    
    HBRUSH hBrushRed = CreateSolidBrush(RGB(255, 0, 0)); //vermelho
    HBRUSH hBrushGreen = CreateSolidBrush(RGB(0, 255, 0)); //verde
    HBRUSH hBrushBlack = CreateSolidBrush(RGB(0, 0, 0)); // Preto
    HBRUSH hBrushPurple = CreateSolidBrush(RGB(128, 0, 128)); //Roxo


    RECT rectRed ={0, 0, 100, 100};
    RECT rectGreen = {685, 0, 794, 100};
    RECT rectBlack = {0, 460, 100, 570};
    RECT rectPurple = {685, 460, 794, 570};
    //fundo da tela
    //RECT rectFundo = {0, 0, 800, 600};

    FillRect(hdc, &rectRed, hBrushRed);
    FillRect(hdc, &rectGreen, hBrushGreen);
    FillRect(hdc, &rectBlack, hBrushBlack);
    FillRect(hdc, &rectPurple, hBrushPurple);

    DeleteObject(hBrushRed);
    DeleteObject(hBrushGreen);
    DeleteObject(hBrushBlack);
    DeleteObject(hBrushPurple);
    
}
