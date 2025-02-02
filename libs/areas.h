#ifndef AREAS_H
#define AREAS_H

//libs create
#include <windows.h>

class Areas{
        public:
            void DesenharAreas(HWND hwnd, HDC hdc);
        private:
            void PintarAreas(HDC hdc);


};

#endif
