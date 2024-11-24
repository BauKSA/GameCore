#pragma once
#include "GenericCommand.h"

#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_

template <typename T>
class InputHandler {
public:
	static void execute(GenericCommand* command, T& actor) {
		command->execute(actor);
	}
};

#endif // !_INPUTHANDLER_
