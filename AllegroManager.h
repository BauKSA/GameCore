#pragma once
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>

#ifndef _ALLEGROMANAGER_
#define _ALLEGROMANAGER_

struct AlElements {
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_TIMER* timer;
};

class AllegroManager {
private:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_TIMER* timer;
	ALLEGRO_BITMAP* screen;
	int monitor_width;
	int monitor_height;

	bool error;

	void init_addons();
	void install_inputs();
	void create_display();
	void start_timer();
	void create_queue();
public:
	AllegroManager() {
		display = nullptr;
		queue = nullptr;
		timer = nullptr;
		screen = nullptr;

		error = false;
		monitor_width = 0;
		monitor_height = 0;
	}

	void init();

	bool failed()const { return error; }
	AlElements get()const { return { display, queue, timer }; }
	void draw_to_display(ALLEGRO_BITMAP* screen);
};

#endif // !_ALLEGROMANAGER_
