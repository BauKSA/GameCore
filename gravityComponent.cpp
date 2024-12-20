#include<cmath>

#include "GravityComponent.h"
#include "Utils.h"

void GravityComponent::tick(float delta_time, MovableActor& actor) {
	if (actor.get_vspeed() == 0 && !actor.is_jumping()) return;
	actor.set_vspeed(actor.get_vspeed() - (GRAVITY * delta_time));
}