#include "Global.h"
#include "StartMenu.h"

void menu_init() {
    font = al_load_ttf_font("./font/pirulen.ttf", 12, 0);
}

void menu_process(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_UP) {
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
            judge_next_window = true;
        }
    }
}

void menu_draw(void)
{
    img = al_load_bitmap("intro.png");
    assert(img != NULL);

    al_draw_bitmap(img, 0, 0, 0);
}

void menu_destroy(void)
{
    al_destroy_font(font);
}