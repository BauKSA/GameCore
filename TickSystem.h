#pragma once
#include<vector>

#include "GenericSystem.h"
#include "BasicCamera.h"
#include "GenericComponent.h"

#ifndef _TICKSYSTEM_
#define _TICKSYSTEM_

class TickSystem : public GenericSystem {
protected:
	BasicCamera* camera;
	std::vector<GenericComponent*> components;
public:
	TickSystem() {
		camera = nullptr;
	}

	void add_component(GenericComponent* component);
	void set_camera(BasicCamera* _camera);
	void update(float delta_time) override;
};

#endif // !_TICKSYSTEM_
