#include<allegro5/allegro.h>
#include<iostream>
#include<thread>

#include "InputSystem.h"

#define KEY_TIME 250

void InputSystem::start_listening() {
	if (!al_is_system_installed()) {
		std::cerr << "Error loading Allegro in actor " << actor->get_name() << std::endl;
		return;
	}

	if (!al_is_keyboard_installed() && !al_is_joystick_installed()) {
		std::cerr << "Error listening events in actor " << actor->get_name()
			<< ". Not keyboard or mouse installed" << std::endl;
		return;
	}

	queue = al_create_event_queue();
	if (!queue) {
		std::cerr << "Error loading event queue in actor " << actor->get_name() << std::endl;
	}

	al_register_event_source(queue, al_get_keyboard_event_source());

	listening = true;
}

void InputSystem::listen() {
    if (listening) {
		ALLEGRO_EVENT ev;
		check_key_queue();

		if (al_get_next_event(queue, &ev)) {
			if (ev.type != ALLEGRO_EVENT_KEY_DOWN) return;

			add_key_to_queue(ev.keyboard.keycode);
			dispatch(ev.keyboard.keycode);
		}
    }
}

void InputSystem::stop_listening() {
	al_destroy_event_queue(queue);
	listening = false;
}

void InputSystem::add_key_to_queue(int key) {
	last_keys.push(key);
	if (last_keys.size() > 5) last_keys.pop();

	pressed_key = key;
	last_key_pressed = Timer::now();
}

void InputSystem::check_key_queue() {
	int delta_time = Timer::difference(last_key_pressed);
	if (delta_time > KEY_TIME) reset_keys();
}

void InputSystem::dispatch(int key) {
	for (int i = 0; i < actions.size(); i++) {
		if (key == actions.at(i).key) {
			manager(actions.at(i).action, actor);
		}
	}
}