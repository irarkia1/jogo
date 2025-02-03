//libs standar
#include <iostream>
#include <windows.h>

//libs create
#include "libs/windows.h"

int main(){

HINSTANCE hInstance = GetModuleHandle(NULL);
int nCmdShow = SW_SHOWDEFAULT;

Windows win;
if(!win.init(hInstance, nCmdShow)){
    return 0;
}

MSG msg = {};
while(GetMessage(&msg, NULL, 0, 0)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);

}

    return (int)msg.wParam;
}
