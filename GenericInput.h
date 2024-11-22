#pragma once
#include<queue>
#include<vector>
#include<functional>

#include "Timer.h"
#include "BaseActor.h"

#ifndef _GENERICINPUT_
#define _GENERICINPUT_


struct Actions {
	std::vector<int> keys;
	std::string action;
};

class GenericInput {
protected:
	std::queue<int> last_keys;
	int pressed_key;
	bool listening;
	std::chrono::time_point<std::chrono::steady_clock> last_key_pressed;

	ALLEGRO_EVENT_QUEUE* queue;
public:
	GenericInput() : listening(false), pressed_key(-1), last_key_pressed(Timer::now()), queue(nullptr) {}

	void reset_keys() { last_keys = std::queue<int>(); }

	virtual void start_listening() {};
	virtual void listen() {};
	virtual void stop_listening() {};

	void add_key_to_queue(int key);
	void check_key_queue();
};

#endif // !_GENERICINPUT_