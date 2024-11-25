#include "JumpComponent.h"
#include "Utils.h"

void JumpComponent::tick(float delta_time) {
	for (size_t i = 0; i < actors.size(); i++) {
		if (actors.at(i)->get_vspeed() > 0) {
			actors.at(i)->disable_gravity();

			float vspeed = actors.at(i)->get_vspeed();
			vspeed -= GRAVITY * delta_time;

			actors.at(i)->set_vspeed(vspeed);
			actors.at(i)->move(UP);

			if (actors.at(i)->get_vspeed() <= 0) {
				actors.at(i)->set_vspeed(0);
				actors.at(i)->enable_gravity();
			}
		}
	}
}