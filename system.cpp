#include "System.h"

void System::add_actor(std::shared_ptr<MovableActor> actor) {
	actors.push_back(actor);
}