#pragma once
#include<queue>
#include<vector>
#include<functional>

#include "Timer.h"
#include "BaseActor.h"

#ifndef _INPUTSYSTEM_
#define _INPUTSYSTEM_

struct Actions {
	std::vector<int> keys;
	std::string action;
};

class InputSystem {
protected:
	BaseActor* actor;
	std::queue<int> last_keys;
	int pressed_key;
	bool listening;
	std::function<void(std::string action, bool key_pressed, BaseActor* actor)> manager;
	std::vector<Actions> actions;
	std::chrono::time_point<std::chrono::steady_clock> last_key_pressed;

	ALLEGRO_EVENT_QUEUE* queue;
public:
	InputSystem(BaseActor* _actor, std::vector<Actions> _actions,
		std::function<void(std::string action, bool key_pressed, BaseActor* actor)> _manager) :
		actor(_actor), manager(_manager), actions(_actions) {
		listening = false;
		pressed_key = -1;
		last_key_pressed = Timer::now();
		queue = nullptr;
	};

	void reset_keys() { last_keys = std::queue<int>(); }

	void start_listening();
	void listen();
	void stop_listening();
	void dispatch(int key, bool key_pressed);
	void add_key_to_queue(int key);
	void check_key_queue();
};

#endif // !_INPUTSYSTEM_