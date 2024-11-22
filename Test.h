#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<allegro5/allegro.h>

#include "ComplexAnimatedActor.h"
#include "ActorInput.h"
#include "GlobalInput.h"

#ifndef _TEST_
#define _TEST_

ComplexAnimatedActor* initialize_test();
ActorInput<ComplexAnimatedActor>* initialize_input(ComplexAnimatedActor* actor);
GlobalInput* initialize_global_input(bool& running);

#endif // !_TEST_