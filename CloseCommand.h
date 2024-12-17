#pragma once
#include "GlobalCommand.h"
#include "GameWindow.h"

#ifndef _CLOSECOMMAND_
#define _CLOSECOMMAND_

class CloseCommand :public GlobalCommand {
public:
	virtual void execute(bool& running) override {
		running = false;
		GameWindow::window().close();
	};
};

#endif // !_CLOSECOMMAND_
