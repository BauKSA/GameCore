#pragma once
#include "GlobalCommand.h"

#ifndef _CLOSECOMMAND_
#define _CLOSECOMMAND_

class CloseCommand :public GlobalCommand {
public:
	virtual void execute(bool& running) override {
		running = false;
	};
};

#endif // !_CLOSECOMMAND_
