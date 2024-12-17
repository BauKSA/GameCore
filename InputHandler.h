#pragma once
#include<variant>

#include "AnimatedActor.h"
#include "ActorCommand.h"
#include "GlobalCommand.h"

#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_

class InputHandler {
private:
	std::shared_ptr<AnimatedActor> player;
	bool* running;
public:
	InputHandler(std::shared_ptr<AnimatedActor> _player, bool* _running) :
		player(_player), running(_running) {
	};

	void check(std::shared_ptr<Command> command);

	void execute(std::shared_ptr <Command> command, std::variant<std::shared_ptr<AnimatedActor>, bool*> actor_receiver) {
		std::visit([&](auto&& arg) { command->execute(*arg); }, actor_receiver);
	}
};

#endif // !_INPUTHANDLER_
