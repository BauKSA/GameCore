#include "JumpComponent.h"
#include "Utils.h"

void JumpComponent::tick(float delta_time, BaseActor& actor) {
	if (actor.get_vspeed() > 0) {
		actor.disable_gravity();

		float vspeed = actor.get_vspeed();
		vspeed -= GRAVITY * delta_time;

		actor.set_vspeed(vspeed);
		actor.move(UP);

		if (actor.get_vspeed() <= 0) {
			actor.set_vspeed(0);
			actor.enable_gravity();
		}
	}
}