#include<cmath>

#include "GravityComponent.h"
#include "Utils.h"

void GravityComponent::tick(float delta_time, BaseActor& actor) {
	if (actor.get_gravity()) {
		actor.set_vspeed(actor.get_vspeed() - (GRAVITY * delta_time));
		actor.move(DOWN);
	}
}