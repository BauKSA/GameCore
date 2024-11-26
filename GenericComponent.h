#pragma once
#include<vector>

#ifndef _GENERICCOMPONENT_
#define _GENERICCOMPONENT_

class BaseActor;

class GenericComponent {
public:
	GenericComponent() {};
	virtual void tick(float delta_time, BaseActor& actor) {};
};

#endif // !_GENERICCOMPONENT_