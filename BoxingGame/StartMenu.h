#pragma once
#include "Global.h"

class StartMenu {
public:
    StartMenu() {
       font = al_load_ttf_font("/font/pirulen", 12, 0);
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

    void menu_draw()
    {
        ALLEGRO_BITMAP *img = al_load_bitmap("intro.png"); //我們要自己畫。
        assert(img != NULL);
        al_draw_bitmap(img, 0, 0, 0);
    }

    void menu_destroy(void)
    {
        al_destroy_font(font);
    }
private:
    ALLEGRO_FONT* font;
};


