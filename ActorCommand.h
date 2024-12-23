#pragma once
#include "Command.h"

#ifndef _ACTORCOMMAND_
#define _ACTORCOMMAND_

class ActorCommand : public Command {
public:
	virtual void execute(MovableActor& actor) override {};
};


#endif // !_ACTORCOMMAND_
