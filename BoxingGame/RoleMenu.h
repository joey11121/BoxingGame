#pragma once
#include "Global.h"

class RoleMenu
{
private:
    ALLEGRO_FONT* font;
    int roletotal; //一號選角或二號選角
public:
    RoleMenu() {
        font = al_load_ttf_font("/font/pirulen", 12, 0);
        roletotal = 2;
    }

    int role_selection(int rolenum);

    void menu_draw()
    {
        ALLEGRO_BITMAP* img = al_load_bitmap("RoleMenu.png"); //Todo: 找一張圖片可以當RoleMenu背景。
        assert(img != NULL);
        al_draw_bitmap(img, 0, 0, 0);
    }

    void menu_destroy(void)
    {
        al_destroy_font(font);
    }
};
