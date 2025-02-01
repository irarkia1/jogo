#ifndef AREAS_H
#define AREAS_H

//libs create
#include <windows.h>

class Areas{
        public:
            void DesenharAreas(HWND hwnd);
        private:
            void PintarAreas(HDC hdc);

};

#endif
