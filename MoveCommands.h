#pragma once
#include "GenericCommand.h"

#ifndef _MOVECOMMANDS_
#define _MOVECOMMANDS_

class MoveRightCommand : public GenericCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override;
};

class MoveLeftCommand : public GenericCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override;
};

class StandRightCommand : public GenericCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override;
};

class StandLeftCommand : public GenericCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override;
};

#endif // !_MOVECOMMANDS_
