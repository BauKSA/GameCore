#pragma once
#include "ActorCommand.h"

#ifndef _MOVECOMMANDS_
#define _MOVECOMMANDS_

class MoveRightCommand : public ActorCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override;
};

class MoveLeftCommand : public ActorCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override;
};

class StandRightCommand : public ActorCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override;
};

class StandLeftCommand : public ActorCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override;
};

class JumpCommand : public ActorCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override;
};

#endif // !_MOVECOMMANDS_
