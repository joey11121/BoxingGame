#include "SceneMenu.h"
int SceneMenu::scene_selection()
{
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    int choice = 0; //選到幾號
    while (true) {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_A) {
                choice = (choice + (scenetotal - 1)) % scenetotal;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_D) {
                choice = (choice + 1) % scenetotal;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                break;
            }
        }
    }
    al_destroy_event_queue(event_queue);
    return choice;
}