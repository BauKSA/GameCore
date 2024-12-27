#include<cmath>

#include "GravityComponent.h"
#include "Utils.h"

void GravityComponent::tick(float delta_time, MovableActor& actor) {
	if (actor.get_vspeed() == 0 && !actor.is_jumping()) return;
	float jumping_gravity = 2.5f;
	if(actor.is_falling()) actor.set_vspeed(actor.get_vspeed() - ((GRAVITY + jumping_gravity) * delta_time));
	else actor.set_vspeed(actor.get_vspeed() - (GRAVITY * delta_time));
}