#include<iostream>

#include "InputHandler.h"

void InputHandler::check(GenericCommand* command) {
	if (dynamic_cast<ActorCommand*>(command)) return execute(command, player);
	else if (dynamic_cast<GlobalCommand*>(command)) return execute(command, running);
	else std::cout << "Command not found" << std::endl;
}