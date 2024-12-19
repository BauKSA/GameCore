#include<cmath>

#include "GravityComponent.h"
#include "Utils.h"

void GravityComponent::tick(float delta_time, MovableActor& actor) {
	if (actor.get_gravity()) {
		actor.set_vspeed(actor.get_vspeed() - (GRAVITY * delta_time));
		actor.set_movement(Directions::DOWN);
	}
}