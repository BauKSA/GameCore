#pragma once
#include<allegro5/allegro.h>
#include<iostream>
#include<thread>

#include "InputSystem.h"

#define KEY_TIME 250

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

void InputSystem::start_listening() {
	if (!al_is_system_installed()) {
		std::cerr << "Error loading Allegro in InputSystem" << std::endl;
		return;
	}

	if (!al_is_keyboard_installed() && !al_is_joystick_installed()) {
		std::cerr << "Error listening events in InputSystem. Not keyboard or mouse installed" << std::endl;
		return;
	}

	queue = al_create_event_queue();
	if (!queue) {
		std::cerr << "Error loading event queue in InputSystem" << std::endl;
	}

	al_register_event_source(queue, al_get_joystick_event_source());

	listening = true;
}

GenericCommand* InputSystem::listen() {
	if (listening) {
		ALLEGRO_EVENT ev;
		check_key_queue();

		if (al_get_next_event(queue, &ev)) {
			if (ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN) {
				return driver->handle(ev.joystick.button);
			}
			else if (ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_UP) {
				return driver->handle(ev.joystick.button, false);
			}

		}
	}

	return nullptr;
}

void InputSystem::stop_listening() {
	al_destroy_event_queue(queue);
	listening = false;
}