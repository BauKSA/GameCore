#pragma once
#include<vector>

#ifndef _GENERICCOMPONENT_
#define _GENERICCOMPONENT_


template <typename T>
class Component {
public:
	Component() {};
	virtual void tick(float delta_time, T& actor) = 0;
};

#endif // !_GENERICCOMPONENT_