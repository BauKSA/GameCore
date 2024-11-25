#pragma once
#include "GenericCommand.h"

#ifndef _GLOBALCOMMAND_
#define _GLOBALCOMMAND_

class GlobalCommand : public GenericCommand {
public:
	virtual void execute(bool& running) override {};
};


#endif // !_GLOBALCOMMAND_
