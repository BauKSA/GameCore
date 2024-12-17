#include<iostream>

#include "InputHandler.h"

void InputHandler::check(std::shared_ptr<Command> command) {
	if (dynamic_cast<ActorCommand*>(command.get())) return execute(command, player);
	else if (dynamic_cast<GlobalCommand*>(command.get())) return execute(command, running);
	else std::cout << "Command not found" << std::endl;
}