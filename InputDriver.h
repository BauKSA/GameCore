#pragma once
#include<vector>

#include "GenericCommand.h"

#ifndef _INPUTDRIVER_
#define _INPUTDRIVER_

struct KeyCommand {
	int button;
	bool pressed;
	GenericCommand* command;

	KeyCommand(int _button, bool _pressed, GenericCommand* _command) :
		button(_button), pressed(_pressed), command(_command) {
	};
};

class InputDriver {
private:
	std::vector<KeyCommand> commands;
public:
	InputDriver(std::vector<KeyCommand> _commands) :
		commands(_commands) {
	}

	GenericCommand* handle(int button, bool pressed = true);
};

#endif // !_INPUTDRIVER_