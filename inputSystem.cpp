#include<allegro5/allegro.h>
#include<iostream>
#include<thread>

#include "InputSystem.h"

void InputSystem::listen() {
	if (!al_is_system_installed()) {
		std::cerr << "Error loading Allegro in actor " << actor->get_name() << std::endl;
		return;
	}

	if (!al_is_keyboard_installed() && !al_is_joystick_installed()) {
		std::cerr << "Error listening events in actor " << actor->get_name()
			<< ". Not keyboard or mouse installed" << std::endl;
		return;
	}

	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	if (!queue) {
		std::cerr << "Error loading event queue in actor " << actor->get_name() << std::endl;
	}

	al_register_event_source(queue, al_get_keyboard_event_source());

    ALLEGRO_EVENT ev;

    while (listening) {
		check_key_queue();

		if (al_get_next_event(queue, &ev)) {
			if (ev.type != ALLEGRO_EVENT_KEY_DOWN) continue;

			add_key_to_queue(ev.keyboard.keycode);
			dispatch(ev.keyboard.keycode);
		}
    }

    al_destroy_event_queue(queue);
}

void InputSystem::add_key_to_queue(int key) {
	last_keys.push(key);
	if (last_keys.size() > 5) last_keys.pop();

	pressed_key = key;
	last_key_pressed = Timer::now();
}

void InputSystem::check_key_queue() {
	std::cout << "combinación de teclas actual: ";
	std::queue<int> _last_keys = last_keys;
	while (_last_keys.size() > 0) {
		std::cout << _last_keys.front() << " ";
		_last_keys.pop();
	}

	std::cout << std::endl;

	int delta_time = Timer::difference(last_key_pressed);
	std::cout << std::endl << "Time from last key: " << delta_time << std::endl;
	if (delta_time > 500) reset_keys();
}

void InputSystem::dispatch(int key) {
	for (int i = 0; i < actions.size(); i++) {
		if (key == actions.at(i).key) {
			return manager(actions.at(i).action);
		}
	}
}