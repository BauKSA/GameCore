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
public:
	TickSystem() {
		camera = nullptr;
	}

	void set_camera(BasicCamera* _camera);
	void update(float delta_time) override;
};

#endif // !_TICKSYSTEM_
