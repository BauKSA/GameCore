#include "GenericSystem.h"

void GenericSystem::add_actor(std::shared_ptr<BaseActor> actor) {
	actors.push_back(actor);
}