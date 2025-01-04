#include "Test.h"
#include "JoystickMapping.h"

std::vector<std::shared_ptr<Actor>> initialize_bricks() {
	std::string sprite = "./test-brick.png";
	std::vector<std::shared_ptr<Actor>> bricks{};

	for (size_t i = 0; i < 16; i++) {
		if (i == 12) continue;
		std::string name = "brick-" + std::to_string(i);
		std::shared_ptr<Actor> brick = std::make_shared<Actor>(name, 32 * i, 125);
		brick->initialize(sprite);
		bricks.push_back(brick);
	}

	std::string name = "brick-b";
	std::shared_ptr<Actor> brick = std::make_shared<Actor>(name, (32 * 5) + 0.01, 93);
	brick->initialize(sprite);
	bricks.push_back(brick);

	std::shared_ptr<Actor> brick_c = std::make_shared<Actor>(name, (32 * 4) + 0.01, 93);
	brick_c->initialize(sprite);
	bricks.push_back(brick_c);

	std::shared_ptr<Actor> brick_d = std::make_shared<Actor>(name, (32 * 8) + 0.01, 83);
	brick_d->initialize(sprite);
	bricks.push_back(brick_d);

	std::shared_ptr<Actor> brick_e = std::make_shared<Actor>(name, (32 * 12) + 0.01, 115);
	brick_e->initialize(sprite);
	bricks.push_back(brick_e);

	return bricks;
}

std::shared_ptr<MovableActor> initialize_test() {
	AnimationPaths _default;
	_default.name = "default";
	_default.paths = {
		"./test0.png",
		"./test1.png",
		"./test2.png",
		"./test3.png",
		"./test4.png",
	};

	AnimationPaths left;
	left.name = "left";
	left.paths = {
		"./test4.png",
		"./test.png",
	};

	AnimationPaths right;
	right.name = "right";
	right.paths = {
		"./test2.png",
		"./test.png",
	};

	std::shared_ptr<MovableActor> actor = std::make_shared<MovableActor>("player", 50, 0, 3.5f);
	actor->initialize({ _default, left, right });
	actor->enable_physics();

	return actor;
}

std::shared_ptr<InputComponent<MovableActor>> initialize_input() {
	std::shared_ptr<MoveRight> move_right = std::make_shared<MoveRight>();
	std::shared_ptr<StandRight> stand_right = std::make_shared<StandRight>();
	std::shared_ptr<MoveLeft> move_left = std::make_shared<MoveLeft>();
	std::shared_ptr<StandLeft> stand_left = std::make_shared<StandLeft>();

	KeyCommand<MovableActor> right(sf::Keyboard::D, true, move_right);
	KeyCommand<MovableActor> left(sf::Keyboard::A, true, move_left);
	KeyCommand<MovableActor> sright(sf::Keyboard::D, false, stand_right);
	KeyCommand<MovableActor> sleft(sf::Keyboard::A, false, stand_left);

	//KeyCommand<MovableActor> close(sf::Keyboard::Escape, true, _close);
	//KeyCommand<MovableActor> jump(sf::Keyboard::K, true, _jump);
	//KeyCommand<MovableActor> stop_jump(sf::Keyboard::K, false, _stop_jump);

	std::vector<KeyCommand<MovableActor>> commands{ right, left, sright, sleft };

	std::shared_ptr<InputDriver<MovableActor>> driver = std::make_shared<InputDriver<MovableActor>>(commands);
	std::shared_ptr<InputComponent<MovableActor>> test_input = std::make_shared<InputComponent<MovableActor>>(std::move(driver));

	return test_input;
}