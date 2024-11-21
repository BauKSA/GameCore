#pragma once
#include "GenericComponent.h"
#include "BaseActor.h"

#ifndef _GRAVITYCOMPONENT_
#define _GRAVITYCOMPONENT_

class GravityComponent : public GenericComponent {
protected:
	const float GRAVITY;
	float initial_speed;
public:
	GravityComponent(float _GRAVITY = 9.8f) :
		GRAVITY(_GRAVITY) {
		initial_speed = 0.0f;
	}

	void tick(float delta_time) override;
};

#endif // !_GRAVITYCOMPONENT_
