#include "GenericComponent.h"

void GenericComponent::add_actor(BaseActor* actor) {
	actors.push_back(actor);
}