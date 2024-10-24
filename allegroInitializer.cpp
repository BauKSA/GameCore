#include "AllegroInitializer.h"
#include "Utils.h"

void AllegroInitializer::init() {
    if (!al_init()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
        return;
    }

    init_addons();
    install_inputs();
    create_display();
    start_timer();
    create_queue();
}

void AllegroInitializer::init_addons() {
    if (!al_init_image_addon()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Image Add-ons", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
    }
}

void AllegroInitializer::install_inputs() {
    if (!al_install_keyboard()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Keyboard", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
    }

    if (!al_install_joystick()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Joystick", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
    }
}

void AllegroInitializer::create_display() {
    ALLEGRO_DISPLAY* _display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!_display) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Display", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
    }

    //al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_window_title(_display, "GameCore");
    display = _display;
}

void AllegroInitializer::start_timer() {
    ALLEGRO_TIMER* _timer = al_create_timer(1.0 / 60.0);
    al_start_timer(_timer);

    timer = _timer;
}

void AllegroInitializer::create_queue() {
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Event Queue", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_joystick_event_source());
    //al_register_event_source(event_queue, al_get_mouse_event_source());

    queue = event_queue;
}