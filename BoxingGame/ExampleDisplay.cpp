#include <stdio.h>
#include <allegro5/allegro.h>

const int win_width = 640;
const int win_height = 480;
int main(int argc, char** argv) {

	ALLEGRO_DISPLAY* display = NULL;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	display = al_create_display(win_width, win_height);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	//清除當前的顏色
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//al_flip_display 被称为交换这两个图像的缓冲区，缓冲区将我们的前一份图像显示给用户，
	//而后一份图像将成为一个渲染的借鉴。
	//若未能调用此函数将导致单调的空白图像渲染在显示屏幕上。
	al_flip_display();
	al_rest(10.0);
	al_destroy_display(display);
	return 0;
}
