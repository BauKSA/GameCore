#pragma once
#include<queue>
#include<vector>
#include<functional>

#include "Timer.h"
#include "BaseActor.h"
#include "InputDriver.h"

#ifndef _INPUTSYSTEM_
#define _INPUTSYSTEM_

class InputSystem {
protected:
	std::queue<int> last_keys;
	int pressed_key;
	bool listening;
	std::chrono::time_point<std::chrono::steady_clock> last_key_pressed;
	ALLEGRO_EVENT_QUEUE* queue;
	InputDriver* driver;
public:
	InputSystem(InputDriver* _driver) :
		listening(false),
		pressed_key(-1),
		last_key_pressed(Timer::now()),
		queue(nullptr),
		driver(_driver) {
	}

	void start_listening();
	void stop_listening();

	void reset_keys() { last_keys = std::queue<int>(); }

	GenericCommand* listen();

	void add_key_to_queue(int key);
	void check_key_queue();
};

#endif // !_INPUTSYSTEM_