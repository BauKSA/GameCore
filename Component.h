#pragma once
#include<vector>

#ifndef _GENERICCOMPONENT_
#define _GENERICCOMPONENT_

class MovableActor;

class Component {
public:
	Component() {};
	virtual void tick(float delta_time, MovableActor& actor) {};
};

#endif // !_GENERICCOMPONENT_