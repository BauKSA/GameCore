#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<memory>

#include "AnimatedActor.h"
#include "InputComponent.h"
#include "InputDriver.h"
#include "TestCommands.h"

#ifndef _TEST_
#define _TEST_

std::shared_ptr<MovableActor> initialize_test();
std::vector<std::shared_ptr<Actor>> initialize_bricks();
std::shared_ptr<InputComponent<MovableActor>> initialize_input();

#endif // !_TEST_