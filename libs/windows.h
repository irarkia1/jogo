#ifndef WINDOWS_H
#define WINDOWS_H

//libs create
#include <windows.h>
#include "areas.h"
#include "players.h"


class Windows{
    public:
         //method
            bool init(HINSTANCE hInstance, int nCmdShow); // criando a janela
            HWND GetHandle(); //aguardando o handle da janela

    private:
        //var
            HWND hwnd;
        //method
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        
        //vem la da area
        void DesenharAreas(HWND hwnd);
};
#endif