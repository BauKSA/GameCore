#include "InputDriver.h"

GenericCommand* InputDriver::handle(int button, bool pressed) {
	GenericCommand* command = nullptr;
	for (size_t i = 0; i < commands.size(); i++) {
		if (commands.at(i).button == button
			&& commands.at(i).pressed == pressed) {
			if (commands.at(i).command == nullptr) std::cout << "Pero es nullptr!" << std::endl;
			command = commands.at(i).command;
		}
	}

	return command;
}