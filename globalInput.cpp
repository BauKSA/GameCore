#pragma once
#include "GlobalInput.h"

void GlobalInput::start_listening() {
	if (!al_is_system_installed()) {
		std::cerr << "Error loading Allegro in Globoal Input" << std::endl;
		return;
	}

	if (!al_is_keyboard_installed() && !al_is_joystick_installed()) {
		std::cerr << "Error loading Allegro in Globoal Input"
			<< ". Not keyboard or mouse installed" << std::endl;
		return;
	}

	queue = al_create_event_queue();
	if (!queue) {
		std::cerr << "Error loading event queue in Globoal Input" << std::endl;
	}

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_joystick_event_source());

	listening = true;
}

void GlobalInput::listen() {
	if (listening) {
		ALLEGRO_EVENT ev;
		check_key_queue();

		if (al_get_next_event(queue, &ev)) {
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				add_key_to_queue(ev.keyboard.keycode);
				return dispatch(ev.keyboard.keycode, true);
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
				return dispatch(ev.keyboard.keycode, false);
			}
			else if (ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN) {
				add_key_to_queue(ev.joystick.button);
				return dispatch(ev.joystick.button, true);
			}
			else if (ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_UP) {
				return dispatch(ev.joystick.button, false);
			}

		}
	}
}

void GlobalInput::stop_listening() {
	al_destroy_event_queue(queue);
	listening = false;
}

void GlobalInput::dispatch(int key, bool key_pressed) {
	for (int i = 0; i < actions.size(); i++) {
		for (int k : actions.at(i).keys) {
			if (k == key) {
				manager(actions.at(i).action, key_pressed);
			}
		}
	}
}