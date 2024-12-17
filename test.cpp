#include "Test.h"
#include "JoystickMapping.h"

std::vector<std::shared_ptr<MovableActor>> initialize_bricks() {
	std::string sprite = "./test-brick.png";
	std::vector<std::shared_ptr<MovableActor>> bricks{};

	for (size_t i = 0; i < 8; i++) {
		std::string name = "brick-" + std::to_string(i);
		std::shared_ptr<MovableActor> brick = std::make_shared<MovableActor>(name, 32 * i, 125);
		brick->initialize(sprite);
		bricks.push_back(brick);
	}

	std::string name = "brick-b";
	std::shared_ptr<MovableActor> brick = std::make_shared<MovableActor>(name, (32 * 5) + 0.01, 93);
	brick->initialize(sprite);
	bricks.push_back(brick);

	return bricks;
}

std::shared_ptr<AnimatedActor> initialize_test() {
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

	std::shared_ptr<AnimatedActor> actor = std::make_shared<AnimatedActor>("test_actor", 50, 0, 2.25f);
	actor->initialize({ _default, left, right });

	return actor;
}

std::unique_ptr<InputSystem> initialize_input() {
	std::shared_ptr<MoveRightCommand> move_right = std::make_shared<MoveRightCommand>();
	std::shared_ptr<MoveLeftCommand> move_left = std::make_shared<MoveLeftCommand>();
	std::shared_ptr<StandRightCommand> stand_right = std::make_shared<StandRightCommand>();
	std::shared_ptr<StandLeftCommand> stand_left = std::make_shared<StandLeftCommand>();
	std::shared_ptr<CloseCommand> _close = std::make_shared<CloseCommand>();
	std::shared_ptr<JumpCommand> _jump = std::make_shared<JumpCommand>();

	KeyCommand right(sf::Keyboard::D, true, move_right);
	KeyCommand left(sf::Keyboard::A, true, move_left);
	KeyCommand sright(sf::Keyboard::D, false, stand_right);
	KeyCommand sleft(sf::Keyboard::A, false, stand_left);
	KeyCommand close(sf::Keyboard::Escape, true, _close);
	KeyCommand jump(sf::Keyboard::K, true, _jump);

	std::vector<KeyCommand> commands{ right, left, sright, sleft, close, jump };

	std::unique_ptr<InputDriver> driver = std::make_unique<InputDriver>(commands);
	std::unique_ptr<InputSystem> test_input = std::make_unique<InputSystem>(std::move(driver));

	return test_input;
}