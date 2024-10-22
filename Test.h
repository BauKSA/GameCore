#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<allegro5/allegro.h>

#include "BaseActor.h"
#include "InputSystem.h"

#ifndef _TEST_
#define _TEST_

BaseActor* initialize_test();
InputSystem* initialize_input(BaseActor* actor);

#endif // !_TEST_