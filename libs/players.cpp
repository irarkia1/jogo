//libs create
#include "players.h"


void Players::CriarPlayers(HWND hwnd, HDC hdc){
    PAINTSTRUCT ps;
    //HDC hdc = hdc;

    HBRUSH hBrushBall = CreateSolidBrush(RGB(0,370, 0)); //verde player
    HPEN hPenBall = CreatePen(PS_SOLID, 3, RGB(0, 0, 0)); //BORDA 

    SelectObject(hdc, hBrushBall);
    SelectObject(hdc, hPenBall);

    for(int i = 0; i <= playerMax; i++){
        Ellipse(hdc, 120, 10, 160, 60);
    }

    DeleteObject(hBrushBall);
    DeleteObject(hPenBall);
    
    EndPaint(hwnd,&ps);
}