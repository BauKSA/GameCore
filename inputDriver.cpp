#include "InputDriver.h"

std::shared_ptr<Command> InputDriver::handle(int button, bool pressed) {
	for (size_t i = 0; i < commands.size(); i++) {
		if (commands.at(i).button == button
			&& commands.at(i).pressed == pressed) {
			std::cout << "[DEBUG] Command found: " << button << std::endl;
			return commands.at(i).command;
		}
	}

	return nullptr;
}