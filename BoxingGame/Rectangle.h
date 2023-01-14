#ifndef RECT_H_INCLUDED
#define RECT_H_INCLUDED
#include "Global.h"

class Rectangle {
public:
    Rectangle() {}

    Rectangle(int x1, int y1, int x2, int y2)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        height = y2 - y1;
        width = x2 - x1;
    }
    //在menu的時候，看click的當下是選到哪一個人物或場景，x y為滑鼠的座標。
    static bool mouseOverlap(int x, int y, Rectangle* rectangle);
    
    int height, width, x1, x2, y1, y2;

};



#endif // RECT_H_INCLUDED
#pragma once
