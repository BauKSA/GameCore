#pragma once
#include<vector>
#include<memory>

#include "Command.h"

#ifndef _INPUTDRIVER_
#define _INPUTDRIVER_

struct KeyCommand {
	sf::Keyboard::Key button;
	bool pressed;
	std::shared_ptr<Command> command;

	KeyCommand(sf::Keyboard::Key _button, bool _pressed, std::shared_ptr<Command> _command) :
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

	std::shared_ptr<Command> handle(int button, bool pressed = true);
};

#endif // !_INPUTDRIVER_