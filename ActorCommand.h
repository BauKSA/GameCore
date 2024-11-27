#pragma once
#include "GenericCommand.h"

#ifndef _ACTORCOMMAND_
#define _ACTORCOMMAND_

class ActorCommand : public GenericCommand {
public:
	virtual void execute(AnimatedActor& actor) override {};
};


#endif // !_ACTORCOMMAND_
