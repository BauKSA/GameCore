#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<allegro5/allegro.h>

#include "AnimatedActor.h"
#include "InputSystem.h"
#include "InputDriver.h"
#include "MoveCommands.h"
#include "CloseCommand.h"

#ifndef _TEST_
#define _TEST_

AnimatedActor* initialize_test();
std::vector<BaseActor*> initialize_bricks();
InputSystem* initialize_input();

#endif // !_TEST_