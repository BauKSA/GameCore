#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<allegro5/allegro.h>

#include "ComplexAnimatedActor.h"
#include "InputSystem.h"

#ifndef _TEST_
#define _TEST_

ComplexAnimatedActor* initialize_test();
InputSystem<ComplexAnimatedActor>* initialize_input(ComplexAnimatedActor* actor);

#endif // !_TEST_