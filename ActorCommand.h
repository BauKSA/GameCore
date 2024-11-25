#pragma once
#include "GenericCommand.h"

#ifndef _ACTORCOMMAND_
#define _ACTORCOMMAND_

class ActorCommand : public GenericCommand {
public:
	virtual void execute(ComplexAnimatedActor& actor) override {};
};


#endif // !_ACTORCOMMAND_
