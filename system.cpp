#include "System.h"

void System::add_actor(std::shared_ptr<Actor> actor) {
	actors.push_back(actor);
}