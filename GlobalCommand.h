#pragma once
#include "Command.h"

#ifndef _GLOBALCOMMAND_
#define _GLOBALCOMMAND_

class GlobalCommand : public Command {
public:
	virtual void execute(bool& running) override {};
};


#endif // !_GLOBALCOMMAND_
