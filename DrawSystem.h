#pragma once
#include "System.h"

#ifndef _DRAWSYSTEM_
#define _DRAWSYSTEM_

class DrawSystem : public System {
protected:
	void draw();
public:
	virtual void update();
};

#endif // !_DRAWSYSTEM_
