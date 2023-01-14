#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#define GAME_TERMINATE -1
#include <bits-stdc++.h> //我的電腦是bits-stdc++.h，你可能要改一下
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;
// note that you can't assign initial value here!
extern const float FPS;
extern const int WIDTH;
extern const int win_width = 640;
extern const int win_height = 480;
extern bool key_state[ALLEGRO_KEY_MAX];
extern bool judge_next_window;
extern int gamestatus; // Control the status of the game：0 start menu，1 Select role，2 Select scene，3 進入打鬥，4是結束
extern ALLEGRO_EVENT_QUEUE* event_queue;
extern ALLEGRO_TIMER* fps;
#endif
