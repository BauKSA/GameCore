#include<thread>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>

#include "Utils.h"

int main(int argc, char** argv) {
    //INICIALIZAMOS ALLEGRO
    if (!al_init()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //INICIALIZAMOS ADD_ONS
    if (!al_init_image_addon()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Image Add-ons", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //INICIALIZAMOS DISPLAY
    //al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!display) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Display", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    al_set_window_title(display, "GameCore");

    al_clear_to_color(al_map_rgb(200, 200, 200));

    //INICIALIZAMOS TIMER
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    al_start_timer(timer);
    float last_frame_time = al_get_time();

    //INICIALIZAMOS TECLADO
    if (!al_install_keyboard()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Keyboard", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Event Queue", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        al_uninstall_keyboard();
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    bool running = true;

    while (running) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }
    }

    // Destruir el display
    al_destroy_display(display);
    al_uninstall_keyboard();
    al_destroy_event_queue(event_queue);

    return 0;
}