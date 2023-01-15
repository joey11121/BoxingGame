#include "Arrow.h"

void Arrow::Arrow_init(int x, int y, int _dx, const char* filename) {
	start_x = now_x = x;
	now_y = y;
	dx = _dx;
	arrowfig = al_load_bitmap(filename);
}
void Arrow::move_xpos(int i) {
	now_x = start_x + i * dx;
}; //When the player  choose the ith role or scene, move to i's x position. 
void Arrow::arrow_draw() {
	al_draw_bitmap(arrowfig, now_x, now_y, 0);
	al_flip_display();
}
void Arrow::arrow_destroy() {
	al_destroy_bitmap(arrowfig);
}