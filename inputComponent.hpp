#pragma once
#include<iostream>
#include<thread>

#include "InputComponent.h"

constexpr auto KEY_TIME = 250;

template <typename T>
void InputComponent<T>::add_key_to_queue(int key) {
	last_keys.push(key);
	if (last_keys.size() > 5) last_keys.pop();

	pressed_key = key;
	last_key_pressed = Timer::now();
}

template <typename T>
void InputComponent<T>::check_key_queue() {
	float delta_time = Timer::difference(last_key_pressed);
	if (delta_time > KEY_TIME) reset_keys();
}

template <typename T>
void InputComponent<T>::start_listening() {
	listening = true;
}

template <typename T>
void InputComponent<T>::tick(float delta_time, T& actor) {
	if (!listening) return;

	std::shared_ptr<Command<T>> command = nullptr;
	check_key_queue();
	if (GameWindow::window().pollEvent(event))
		command = driver->handle(event.key.code, (event.type == sf::Event::KeyPressed));

	if (!command) return;

	command->execute(actor);

	return;
}

template <typename T>
void InputComponent<T>::stop_listening() {
	listening = false;
}