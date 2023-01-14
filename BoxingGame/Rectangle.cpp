#include "Rectangle.h"

//在menu的時候，看click的當下是選到哪一個人物或場景，x y為滑鼠的座標。
bool Rectangle::mouseOverlap(int x, int y, Rectangle* rectangle)
{
    if (rectangle->x1 < x && x < rectangle->x2) {
        if (rectangle->y1 < y && y < rectangle->y2)
            return true;
    }

    return false;
}