#pragma once
#include "GenericInput.h"

#ifndef _ACTORINPUT_
#define _ACTORINPUT_

template<typename ActorType>
class ActorInput : public GenericInput {
protected:
	ActorType* actor;
	std::function<void(std::string action, bool key_pressed, ActorType* actor)> manager;
	std::vector<Actions> actions;
public:
	ActorInput(ActorType* _actor, std::vector<Actions> _actions,
		std::function<void(std::string action, bool key_pressed, ActorType* actor)> _manager) :
		actor(_actor), manager(_manager), actions(_actions) {
	}

	void start_listening() override;
	void listen() override;
	void stop_listening() override;

	void dispatch(int key, bool key_pressed);
};

#include "actorInput.hpp"
#endif // !_ACTORINPUT_
