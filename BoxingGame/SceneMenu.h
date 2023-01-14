#pragma once
#include "Global.h"

class SceneMenu
{
public:
    SceneMenu() {
        font = al_load_ttf_font("/font/pirulen", 12, 0);
        scenetotal = 6;
    }
    void menu_process(ALLEGRO_EVENT event)
    {
        if (event.type == ALLEGRO_EVENT_KEY_UP) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                judge_next_window = true;
            }
        }
        return;
    }

    int scene_selection();

    void menu_draw()
    {
        ALLEGRO_BITMAP* img = al_load_bitmap("SceneMenu.png"); //TODO：找一張可以當SceneMenu的圖當背景。
        assert(img != NULL);
        al_draw_bitmap(img, 0, 0, 0);
    }

    void menu_destroy(void)
    {
        al_destroy_font(font);
    }
private:
    ALLEGRO_FONT* font;
    int scenetotal; 
};