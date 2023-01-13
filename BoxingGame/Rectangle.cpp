#include "Rectangle.h"

bool Rectangle::mouseOverlap(int x, int y, Rectangle* rectangle)
{
    if (rectangle->x1 < x && x < rectangle->x2) {
        if (rectangle->y1 < y && y < rectangle->y2)
            return true;
    }

    return false;
}