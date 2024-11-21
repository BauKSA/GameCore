#include "TickSystem.h"

void TickSystem::update(float delta_time) {
	//al_clear_to_color(al_map_rgb(255, 255, 255));
	for (size_t i = 0; i < components.size(); i++) {
		components.at(i)->tick(delta_time);
	}

	for (size_t i = 0; i < actors.size(); i++) {
		if (!actors.at(i)) continue;
		actors.at(i)->tick(delta_time);
		actors.at(i)->draw();
	}

	if (camera) camera->set_actor_position();

	al_flip_display();
}

void TickSystem::add_component(GenericComponent* component) {
	components.push_back(component);
}

void TickSystem::set_camera(BasicCamera* _camera) {
	camera = _camera;
}