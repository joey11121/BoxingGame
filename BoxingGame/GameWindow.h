#include "Global.h"
#include "Role.h"
#include "Scene.h"
#include "StartMenu.h"

void game_update();
int process_event();
void game_draw();
int game_run();
void game_destroy();

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_EXIT 6



class GameWindow {
public:
	GameWindow();
	~GameWindow();
	void game_play(); //Start playing the game.
	void game_init();
	void game_begin();//Start your game here, you can draw the basic item first like start menu.
					  //Start timer then you can run your game
	void game_reset(); 
	int game_run(); //Process the event in event queue
	int game_update();

	void show_err_msg(int msg);
	void game_destroy();

	// each drawing scene function
	void draw_running_map();

	// process of updated event
	int process_event();
	// detect if mouse hovers over a rectangle
	bool mouse_hover(int, int, int, int);

	Role* create_role();

private:

};