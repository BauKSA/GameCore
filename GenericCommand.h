#pragma once
#include "BaseActor.h"
#include "AnimatedActor.h"

#ifndef _GENERICCOMMAND_
#define _GENERICCOMMAND_

class GenericCommand {
public:
	virtual void execute() {};
	virtual void execute(AnimatedActor& actor) {};
	virtual void execute(bool& running) {};
};

#endif // !_GENERICCOMMAND_
