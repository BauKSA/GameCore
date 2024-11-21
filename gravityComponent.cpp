#include "GravityComponent.h"
#include "Utils.h"

void GravityComponent::tick(float delta_time) {
    for (size_t i = 0; i < actors.size(); i++) {
        actors.at(i)->set_vspeed(actors.at(i)->get_vspeed() + (actors.at(i)->get_vspeed() * delta_time));
        actors.at(i)->move(DOWN);
    }
}