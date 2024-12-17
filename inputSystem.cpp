#pragma once
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
	float delta_time = Timer::difference(last_key_pressed);
	if (delta_time > KEY_TIME) reset_keys();
}

void InputSystem::start_listening() {
	listening = true;
}

std::shared_ptr<Command> InputSystem::listen() {
	if (!listening) return nullptr;

	check_key_queue();
	if (GameWindow::window().pollEvent(event)) {
		return driver->handle(event.key.code, (event.type == sf::Event::KeyPressed));
	}

	return nullptr;
}


void InputSystem::stop_listening() {
	listening = false;
}