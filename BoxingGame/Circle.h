#ifndef CIRC_H_INCLUDED
#define CIRC_H_INCLUDED
#include "Rectangle.h"
class Circle{
public:

    Circle(int x, int y, int r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    ~Circle();
    //如果攻擊的動畫是圓形，角色是長方形，那就要用圓形攻擊的圓形是否接觸到長方形來判定。
    static bool isOverlap(Circle*, Rectangle*);
private:
    int r; //半徑
    int x, y; //圓心座標
};



#endif // CIRC_H_INCLUDED
