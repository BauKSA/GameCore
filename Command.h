#pragma once
#include "MovableActor.h"
#include "AnimatedActor.h"

#ifndef _COMMAND_
#define _COMMAND_

template <typename T>
class Command {
public:
	virtual ~Command() = default;
	virtual void execute(T& actor) = 0;
};

#endif // !_COMMAND_
