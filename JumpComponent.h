#pragma once
#include "GenericComponent.h"
#include "BaseActor.h"

#ifndef _JUMPCOMPONENT_
#define _JUMPCOMPONENT_

class JumpComponent : public GenericComponent {
protected:
	const float GRAVITY;
public:
	JumpComponent(float _GRAVITY = 9.8f) :
		GRAVITY(_GRAVITY) {
	}

	void tick(float delta_time, BaseActor& actor) override;
};

#endif // !_JUMPCOMPONENT_