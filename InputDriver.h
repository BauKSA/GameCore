#pragma once
#include<vector>
#include<memory>

#include "Command.h"

#ifndef _INPUTDRIVER_
#define _INPUTDRIVER_

template <typename T>
struct KeyCommand {
	sf::Keyboard::Key button;
	bool pressed;
	std::shared_ptr<Command<T>> command;

	KeyCommand(sf::Keyboard::Key _button, bool _pressed, std::shared_ptr<Command<T>> _command) :
		button(_button), pressed(_pressed), command(_command) {
	};
};

template <typename T>
class InputDriver {
private:
	std::vector<KeyCommand<T>> commands;
public:
	InputDriver(std::vector<KeyCommand<T>> _commands) :
		commands(_commands) {
	}

	std::shared_ptr<Command<T>> handle(int button, bool pressed = true);
};

#include "inputDriver.hpp"

#endif // !_INPUTDRIVER_