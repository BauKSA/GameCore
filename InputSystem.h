#pragma once
#include<queue>
#include<functional>

#include "Timer.h"
#include "BaseActor.h"

#ifndef _INPUTSYSTEM_
#define _INPUTSYSTEM_

struct Actions {
	int key;
	std::string action;
};

class InputSystem {
protected:
	BaseActor* actor;
	std::queue<int> last_keys;
	int pressed_key;
	bool listening;
	std::function<void(std::string)> manager;
	std::vector<Actions> actions;
	std::chrono::time_point<std::chrono::steady_clock> last_key_pressed;
public:
	InputSystem(BaseActor* _actor, std::vector<Actions> _actions, std::function<void(std::string)> _manager) :
		actor(_actor), manager(_manager), actions(_actions) {
		listening = false;
		pressed_key = -1;
		last_key_pressed = Timer::now();
	};

	void start_listening() { listening = true; }
	void stop_listening() { listening = false; }
	void reset_keys() { last_keys = std::queue<int>(); }

	void listen();
	void dispatch(int key);
	void add_key_to_queue(int key);
	void check_key_queue();
};

#endif // !_INPUTSYSTEM_
