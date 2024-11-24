#pragma once
#include "BaseActor.h"
#include "ComplexAnimatedActor.h"

#ifndef _GENERICCOMMAND_
#define _GENERICCOMMAND_

class GenericCommand {
public:
	virtual void execute() {};
	virtual void execute(BaseActor& actor) {};
	virtual void execute(ComplexAnimatedActor& actor) {};
	virtual void execute(bool& running) {};
};

#endif // !_GENERICCOMMAND_
