#include "InputDriver.h"

GenericCommand* InputDriver::handle(int button, bool pressed) {
	GenericCommand* command = nullptr;
	for (size_t i = 0; i < commands.size(); i++) {
		if (commands.at(i).button == button
			&& commands.at(i).pressed == pressed) {
			command = commands.at(i).command;
		}
	}

	return command;
}