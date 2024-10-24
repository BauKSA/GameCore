#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<allegro5/allegro.h>

#include "AnimatedActor.h"
#include "InputSystem.h"

#ifndef _TEST_
#define _TEST_

AnimatedActor* initialize_test();
InputSystem* initialize_input(BaseActor* actor);

#endif // !_TEST_