#pragma once
#include<allegro5/allegro.h>
#include<iostream>
#include<thread>

#include "GenericInput.h"

#define KEY_TIME 250

void GenericInput::add_key_to_queue(int key) {
	last_keys.push(key);
	if (last_keys.size() > 5) last_keys.pop();

	pressed_key = key;
	last_key_pressed = Timer::now();
}

void GenericInput::check_key_queue() {
	int delta_time = Timer::difference(last_key_pressed);
	if (delta_time > KEY_TIME) reset_keys();
}