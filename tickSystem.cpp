#include "TickSystem.h"

void TickSystem::update(float delta_time) {
	al_clear_to_color(al_map_rgb(255, 255, 255));

	for (size_t i = 0; i < actors.size(); i++) {
		if (!actors.at(i)) continue;
		actors.at(i)->tick(delta_time);
		actors.at(i)->draw();
	}

	al_flip_display();
}