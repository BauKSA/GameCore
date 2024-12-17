#pragma once
#include "MovableActor.h"
#include "AnimatedActor.h"

#ifndef _COMMAND_
#define _COMMAND_

class Command {
public:
	virtual void execute() {};
	virtual void execute(AnimatedActor& actor) {};
	virtual void execute(bool& running) {};
};

#endif // !_COMMAND_
