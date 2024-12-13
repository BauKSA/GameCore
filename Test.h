#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<allegro5/allegro.h>
#include<memory>

#include "AnimatedActor.h"
#include "InputSystem.h"
#include "InputDriver.h"
#include "MoveCommands.h"
#include "CloseCommand.h"

#ifndef _TEST_
#define _TEST_

std::shared_ptr<AnimatedActor> initialize_test();
std::vector<std::shared_ptr<BaseActor>> initialize_bricks();
std::unique_ptr<InputSystem> initialize_input();

#endif // !_TEST_