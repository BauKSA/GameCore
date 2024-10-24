#pragma once
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>

#ifndef _ALLEGROINITIALIZER_
#define _ALLEGROINITIALIZER_

struct AlElements {
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_TIMER* timer;
};

class AllegroInitializer {
private:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_TIMER* timer;

	bool error;

	void init_addons();
	void install_inputs();
	void create_display();
	void start_timer();
	void create_queue();
public:
	AllegroInitializer() {
		display = nullptr;
		queue = nullptr;
		timer = nullptr;

		error = false;
	}

	void init();

	bool failed()const { return error; }
	AlElements get()const { return { display, queue, timer }; }
};

#endif // !_ALLEGROINITIALIZER_
