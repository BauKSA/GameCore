#pragma once
#include<variant>

#include "ComplexAnimatedActor.h"
#include "ActorCommand.h"
#include "GlobalCommand.h"

#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_

class InputHandler {
private:
	ComplexAnimatedActor* player;
	bool* running;
public:
	InputHandler(ComplexAnimatedActor* _player, bool* _running) :
		player(_player), running(_running) {
	};

	void check(GenericCommand* command);

	void execute(GenericCommand* command, std::variant<ComplexAnimatedActor*, bool*> actor_receiver) {
		std::visit([&](auto&& arg) { command->execute(*arg); }, actor_receiver);
	}
};

#endif // !_INPUTHANDLER_
