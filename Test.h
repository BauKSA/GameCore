#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<memory>

#include "AnimatedActor.h"
#include "InputSystem.h"
#include "InputDriver.h"
#include "MoveCommands.h"
#include "CloseCommand.h"

#ifndef _TEST_
#define _TEST_

std::shared_ptr<MovableActor> initialize_test();
std::vector<std::shared_ptr<Actor>> initialize_bricks();
std::unique_ptr<InputSystem> initialize_input();

#endif // !_TEST_