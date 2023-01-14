#include "RoleMenu.h"

int RoleMenu::role_selection(int rolenum)
{
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    int choice = 0; //選到幾號
    while (true) {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (rolenum == 0) {
                if (event.keyboard.keycode == ALLEGRO_KEY_A) {
                    choice = (choice + (roletotal - 1)) % roletotal;
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_D) {
                    choice = (choice + 1) % roletotal;
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                    break;
                }

            }
            if (rolenum == 1) {
                if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                    choice = (choice + (roletotal - 1)) % roletotal;
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                    choice = (choice + 1) % roletotal;
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                    judge_next_window = true;
                    break;
                }
            }
        }
    }
    al_destroy_event_queue(event_queue);
    return choice;
}