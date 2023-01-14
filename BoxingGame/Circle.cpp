#include "Circle.h"
#include "Rectangle.h"
#include "Global.h"
using namespace std;
//圓形與長方形相交的判斷，主要是用在攻擊特效是否有打到敵人。
bool Circle::isOverlap(Circle *circle, Rectangle *rectangle)
{
		int minx, miny;
		//找出x方向與圓心x最接近的
		minx = min(abs(rectangle -> x1 - circle -> x), abs(rectangle -> x2 - circle -> x));
		//找出y方向與圓心y最接近的
		miny = min(abs(rectangle -> y1 - circle -> y), abs(rectangle -> y2 - circle -> y));
		if (minx * minx + miny * miny < circle -> r * circle -> r)
			return true;

    return false;
}
