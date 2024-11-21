#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "AllegroManager.h"
#include "Utils.h"

void AllegroManager::init() {
    if (!al_init()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
        return;
    }

    ALLEGRO_MONITOR_INFO info{};
    al_get_monitor_info(0, &info);

    const int width = info.x2 - info.x1;
    const int height = info.y2 - info.y1;

    monitor_width = width;
    monitor_height = height;


    init_addons();
    install_inputs();
    create_display();
    start_timer();
    create_queue();

    al_set_new_bitmap_flags(ALLEGRO_NO_PRESERVE_TEXTURE);
}

void AllegroManager::init_addons() {
    if (!al_init_image_addon()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Image Add-ons", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
    }
}

void AllegroManager::install_inputs() {
    if (!al_install_keyboard()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Keyboard", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
    }

    if (!al_install_joystick()) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Joystick", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
    }
}

void AllegroManager::create_display() {
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    ALLEGRO_DISPLAY* _display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!_display) {
        al_show_native_message_box(nullptr, "Error", "Error initializing", "Can't initialize Allegro Display", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        error = true;
    }

    al_set_window_title(_display, "GameCore");
    display = _display;

    al_set_target_bitmap(al_get_backbuffer(display));
}

void AllegroManager::start_timer() {
    ALLEGRO_TIMER* _timer = al_create_timer(1.0 / 60.0);
    al_start_timer(_timer);

    timer = _timer;
}

void AllegroManager::create_queue() {
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

void AllegroManager::draw_to_display(ALLEGRO_BITMAP* screen) {
    al_set_target_backbuffer(display);
    al_clear_to_color(al_map_rgb(0, 0, 0));

    const float scale_x = monitor_width / SCREEN_WIDTH;
    const float scale_y = monitor_height / SCREEN_HEIGHT;

    float scale = std::min(scale_x, scale_y);

    int scaled_width = static_cast<int>(SCREEN_WIDTH * scale);
    int scaled_height = static_cast<int>(SCREEN_HEIGHT * scale);

    int offset_x = (monitor_width - scaled_width) / 2;
    int offset_y = (monitor_height - scaled_height) / 2;

    al_draw_scaled_bitmap(
        screen,
        0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
        offset_x, offset_y,
        scaled_width, scaled_height,
        0
    );

    al_flip_display();
}