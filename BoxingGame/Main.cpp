#include "GameWindow.h"
#include "Global.h"
int main(int argc, char* argv[])
{
    GameWindow* BoxingGame = new GameWindow(); //Object of game

    BoxingGame->game_play(); //Start the game. 

    delete BoxingGame;
    return 0;
}

