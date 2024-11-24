#pragma once
#include "GenericCommand.h"

#ifndef _CLOSECOMMAND_
#define _CLOSECOMMAND_

class CloseCommand :public GenericCommand {
public:
	virtual void execute(bool& running) override {
		running = false;
	};
};

#endif // !_CLOSECOMMAND_
