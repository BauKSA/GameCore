#pragma once
#include<queue>
#include<vector>
#include<functional>
#include<SFML/Graphics.hpp>

#include "GameWindow.h"
#include "Timer.h"
#include "MovableActor.h"
#include "InputDriver.h"

#ifndef _INPUTSYSTEM_
#define _INPUTSYSTEM_

class InputSystem {
protected:
	std::queue<int> last_keys;
	int pressed_key;
	bool listening;
	std::chrono::time_point<std::chrono::steady_clock> last_key_pressed;
	sf::Event event;
	std::unique_ptr<InputDriver> driver;

public:
	InputSystem(std::unique_ptr<InputDriver> _driver) :
		listening(false),
		pressed_key(-1),
		last_key_pressed(Timer::now()),
		driver(std::move(_driver)),
		event() {
	}

	void start_listening();
	void stop_listening();

	void reset_keys() { last_keys = std::queue<int>(); }

	std::shared_ptr<Command> listen();

	void add_key_to_queue(int key);
	void check_key_queue();
};

#endif // !_INPUTSYSTEM_