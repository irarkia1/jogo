#ifndef PLAYERS_H
#define PLAYERS_H

//libs standard

//libs create
#include <windows.h>

class Players{
    public:
        void CriarPlayers(HWND hwnd, HDC hdc);
    
    private:
    const int playerMax = 2;
};

#endif