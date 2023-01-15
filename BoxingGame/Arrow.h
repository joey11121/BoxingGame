#pragma once
#include "Global.h"
//Use the arrow to indicate the player choice. Blue for player 1 and red for player 2;
class Arrow
{
private:
	int start_x, now_y, now_x, dx; //dx is the distance of moving arrow. 
	ALLEGRO_BITMAP* arrowfig; 
public:
	Arrow() {}
	~Arrow();
	void Arrow_init(int x, int y, int _dx, const char* filename);
	void move_xpos(int);
	void arrow_draw();
	void arrow_destroy();
};

