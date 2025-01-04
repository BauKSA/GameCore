#pragma once
#include<queue>
#include<vector>
#include<functional>
#include<SFML/Graphics.hpp>

#include "GameWindow.h"
#include "Component.h"
#include "Timer.h"
#include "InputDriver.h"

#ifndef _INPUTCOMPONENT_
#define _INPUTCOMPONENT_

template <typename T>
class InputComponent : public Component<T> {
protected:
	std::queue<int> last_keys;
	int pressed_key;
	bool listening;
	std::chrono::time_point<std::chrono::steady_clock> last_key_pressed;
	sf::Event event;
	std::shared_ptr<InputDriver<T>> driver;

public:
	InputComponent(std::shared_ptr<InputDriver<T>> _driver) :
		listening(true),
		pressed_key(-1),
		last_key_pressed(Timer::now()),
		driver(std::move(_driver)),
		event() {
	}

	void start_listening();
	void stop_listening();

	void reset_keys() { last_keys = std::queue<int>(); }

	virtual void tick(float delta_time, T& actor) override;

	void add_key_to_queue(int key);
	void check_key_queue();
};

#include "InputComponent.hpp"

#endif // !_INPUTCOMPONENT_