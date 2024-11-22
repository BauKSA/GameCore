#pragma once
#include "GenericInput.h"

#ifndef _GLOBALINPUT_
#define _GLOBALINPUT_

class GlobalInput : public GenericInput {
protected:
	std::function<void(std::string action, bool key_pressed)> manager;
	std::vector<Actions> actions;
public:
	GlobalInput(std::vector<Actions> _actions,
		std::function<void(std::string action, bool key_pressed)> _manager) :
		manager(_manager), actions(_actions) {
	}

	void start_listening() override;
	void listen() override;
	void stop_listening() override;

	void dispatch(int key, bool key_pressed);
};

#endif // !_GLOBALINPUT_