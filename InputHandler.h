#pragma once
#include<variant>

#include "AnimatedActor.h"
#include "ActorCommand.h"
#include "GlobalCommand.h"

#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_

class InputHandler {
private:
	AnimatedActor* player;
	bool* running;
public:
	InputHandler(AnimatedActor* _player, bool* _running) :
		player(_player), running(_running) {
	};

	void check(GenericCommand* command);

	void execute(GenericCommand* command, std::variant<AnimatedActor*, bool*> actor_receiver) {
		std::visit([&](auto&& arg) { command->execute(*arg); }, actor_receiver);
	}
};

#endif // !_INPUTHANDLER_
