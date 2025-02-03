//libs create
#include "players.h"


void Players::CriarPlayers(HWND hwnd, HDC hdc){
    PAINTSTRUCT ps;
    //HDC hdc = hdc;

    HBRUSH hBrushBall = CreateSolidBrush(RGB(0,370, 0)); //verde player
    HPEN hPenBall = CreatePen(PS_SOLID, 3, RGB(0, 0, 0)); //BORDA 

    SelectObject(hdc, hBrushBall);
    SelectObject(hdc, hPenBall);

    Ellipse(hdc, 750, 10, 760, 20);

    DeleteObject(hBrushBall);
    DeleteObject(hPenBall);
    
    EndPaint(hwnd,&ps);
};

// Filho 01
void PlayersMove::PtSrt(LPARAM lParam){

    ptStart.x = LOWORD(lParam);
    ptStart.y = HIWORD(lParam);
    isDragging = true;
};

void PlayersMove::DraggingMouse(HWND hwnd, LPARAM lParam){
    if (isDragging) {
        HDC hdc = GetDC(hwnd);
        SetROP2(hdc, R2_NOT);
        Rectangle(hdc, ptStart.x, ptStart.y, LOWORD(lParam), HIWORD(lParam));
        ReleaseDC(hwnd, hdc);
    }
}

void PlayersMove::PtEnd(LPARAM lParam, HWND hwnd, HDC hdcMem, HBITMAP hbmMem, HGDIOBJ hOldBmp){
    ptEnd.x = LOWORD(lParam);
    ptEnd.y = HIWORD(lParam);
    isDragging = false;

    RECT rect = {ptStart.x, ptStart.y, ptEnd.x, ptEnd.y};
    CaptureRegion(hwnd, rect,hdcMem, hbmMem, hOldBmp);
}

void PlayersMove::CaptureRegion(HWND hwnd, RECT rect, HDC hdcMem, HBITMAP hbmMem, HGDIOBJ hOldBmp){
    HDC hdcScreen = GetDC(NULL);
    hdcMem = CreateCompatibleDC(hdcScreen); 
    HBITMAP hbmScreen = CreateCompatibleBitmap(hdcScreen, rect.right - rect.left, rect.bottom - rect.top);

    SelectObject(hdcMem, hbmScreen);
    BitBlt(hdcMem, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hdcScreen, rect.left, rect.top, SRCCOPY);

    //SALVAR IMAGEM
    OpenClipboard(hwnd);
    EmptyClipboard();
    SetClipboardData(CF_BITMAP, hbmScreen);
    CloseClipboard();

    DeleteObject(hbmScreen);
    DeleteDC(hdcMem);
    ReleaseDC(NULL, hdcScreen);
}