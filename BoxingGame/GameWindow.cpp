#include "GameWindow.h"


bool draw = false;
int window = 1; //window : 1 -> start menu, 2 -> role menu, 3 -> scene menu, 4 -> fighting, 5 -> KO, 6 -> Celebration!  
int rolechoice[2]; //The index for the role choice of the 2 players.
int scenechoice;
const char* title = "Final Project Group 66";

ALLEGRO_SAMPLE_INSTANCE* MenuSampleInstance = NULL, *DeathSampleInstance = NULL;
ALLEGRO_SAMPLE* MenuSample = NULL, *DeathSample = NULL;

// ALLEGRO Variables
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_SAMPLE* song = NULL;
ALLEGRO_SAMPLE_INSTANCE* sample_instance;


void GameWindow::game_play() {
    int msg = 0;

    game_init();
    game_begin();

    while (msg != GAME_TERMINATE) {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("Game Over\n");
    }

    game_destroy();
    return;
}

void game_init() {
    printf("Game Initializing...\n");
    al_init();
    // init audio
    al_install_audio();
    al_init_acodec_addon();
    // Create display
    display = al_create_display(win_width, win_height);
    // create event queue
    event_queue = al_create_event_queue();
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon
    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event
    // Register event
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    fps = al_create_timer(1.0 / FPS);
    al_register_event_source(event_queue, al_get_timer_event_source(fps));
    // initialize the icon on the display
    ALLEGRO_BITMAP* icon = al_load_bitmap("./image/icon.jpg"); //
    al_set_display_icon(display, icon);
}

void game_begin() {
    // Load sound
    //the start menu, role menu, scene menu sound; 
    MenuSample = al_load_sample("./sound/start.wav");
    al_reserve_samples(20);
    MenuSampleInstance = al_create_sample_instance(MenuSample);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance, 1);
    al_play_sample_instance(sample_instance);
    al_start_timer(fps);
    ALLEGRO_EVENT event;
    StartMenu a;
    judge_next_window = false;
    a.menu_draw();
    while (!judge_next_window) {
        a.menu_process(event); 
    }
    game_update(); 
    a.menu_destroy();
    RoleMenu b;
    judge_next_window = false;
    b.menu_draw();
    for (int i = 0; i < 1; i++) {
        rolechoice[i] = b.role_selection(i);
    }
    game_update();
    b.menu_destroy();
    SceneMenu c;
    judge_next_window = false;
    c.menu_draw();
    scenechoice = c.scene_selection();
    game_update();
    c.menu_destroy();
    judge_next_window = false;
}
void game_update() {
    if (judge_next_window) {
        if (window == 1) {
            // not back menu anymore, therefore destroy i;
            judge_next_window = false;
            window = 2;
        }
        if (window == 2) {
            // not back menu anymore, therefore destroy it
            // initialize next scene
            judge_next_window = false;
            window = 3;
        }
        if (window == 3) {
            // not back menu anymore, therefore destroy it
            menu_destroy();
            // initialize next scene
            judge_next_window = false;
            window = 2;
        }

        if (window == 4) {
            // not back menu anymore, therefore destroy it
            menu_destroy();
            // initialize next scene
            game_scene_init();
            judge_next_window = false;
            window = 2;
        }
        if (window == 5) {
            // not back menu anymore, therefore destroy it
            menu_destroy();
            // initialize next scene
            game_scene_init();
            judge_next_window = false;
            window = 2;
        }
    }
}

int GameWindow::process_event()
{
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);

    // process the event of other component
    else if (g_nWindow == 2) {
        charater_process(event);
        monster_process(event);
    }
    else if (g_nWindow == 3) {
        g_nWindow3Count++;
        if (g_nWindow3Count > MAX_COUNTOF_WINDOW3) {
            return GAME_TERMINATE;
        }
    }
    else if (g_nWindow == 4) {
        g_nWindow4Count++;
        if (g_nWindow4Count > MAX_COUNTOF_WINDOW4) {
            return GAME_WIN;
        }
    }

    // Shutdown our program
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_TERMINATE;
    }
    else if (event.type == ALLEGRO_EVENT_TIMER) {
        if (event.timer.source == fps) {
            g_bDraw = true;
        }
    }
    if (g_bDraw) {
        game_update();
    }
    return 0;
}
int process_event() {
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    // process the event of other component
    if (window == 1) {
        menu_process(event);
    }
    else if (window == 2) {
        test.process(event);
    }

    // Shutdown our program
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        return GAME_TERMINATE;
    else if (event.type == ALLEGRO_EVENT_TIMER)
        if (event.timer.source == fps)
            draw = true;
    if (draw) game_update();
    return 0;
}
void game_draw() {
    if (window == 1) {
        menu_draw();
    }
    else if (window == 2) {
        game_scene_draw();
    }
    al_flip_display();
}
int game_run() {
    int error = 0;
    if (draw) {
        game_draw();
        draw = false;
    }
    if (!al_is_event_queue_empty(event_queue)) {
        error = process_event();
    }
    return error;
}

void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    game_scene_destroy();
}
