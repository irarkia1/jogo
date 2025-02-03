#ifndef PLAYERS_H
#define PLAYERS_H

//libs standard
#include <windows.h>

//libs create

class Players{
    public:
        void CriarPlayers(HWND hwnd, HDC hdc);
    
    private:
    const int playerMax = 2;

    protected:
    int speedMax;

};

class PlayersMove : public Players{
    private:
        //RECT rect;

    public:
        //var
        bool isDragging = false;

        POINT ptStart, ptEnd;

        //method
        void CaptureRegion(HWND hwnd, RECT rect, HDC hdcMem, HBITMAP hbmMem, HGDIOBJ hOldBmp);

        void PtSrt(LPARAM lParam);

        void DraggingMouse(HWND hwnd, LPARAM lParam);
        
        void PtEnd(LPARAM lParam, HWND hwnd, HDC hdcMem, HBITMAP hbmMem, HGDIOBJ hOldBmp);
    
};

#endif
