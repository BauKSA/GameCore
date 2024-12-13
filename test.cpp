#include "Test.h"
#include "JoystickMapping.h"

std::vector<std::shared_ptr<BaseActor>> initialize_bricks() {
	std::vector<std::shared_ptr<BaseActor>> bricks{};
	for (size_t i = 0; i < 8; i++) {
		std::string name = "brick-" + std::to_string(i);
		std::shared_ptr<BaseActor> brick = std::make_shared<BaseActor>(name, 32 * i, 125);
		brick->initialize_sprite("./test-brick.png");
		bricks.push_back(brick);
	}

	std::string name = "brick-b";
	std::shared_ptr<BaseActor> brick = std::make_shared<BaseActor>(name, (32 * 5) + 0.01, 93);
	brick->initialize_sprite("./test-brick.png");
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

	std::shared_ptr<AnimatedActor> actor = std::make_shared<AnimatedActor>("test_actor", 50, 0, 2.125);
	actor->initialize({ _default, left, right });

	return actor;
}

std::unique_ptr<InputSystem> initialize_input() {
	MoveRightCommand* move_right = new MoveRightCommand();
	MoveLeftCommand* move_left = new MoveLeftCommand();
	StandRightCommand* stand_right = new StandRightCommand();
	StandLeftCommand* stand_left = new StandLeftCommand();
	CloseCommand* _close = new CloseCommand();
	JumpCommand* _jump = new JumpCommand();

	KeyCommand right(JOY_BUTTON_RIGHT, true, move_right);
	KeyCommand left(JOY_BUTTON_LEFT, true, move_left);
	KeyCommand sright(JOY_BUTTON_RIGHT, false, stand_right);
	KeyCommand sleft(JOY_BUTTON_LEFT, false, stand_left);
	KeyCommand close(JOY_BUTTON_START, true, _close);
	KeyCommand jump(JOY_BUTTON_A, true, _jump);

	std::vector<KeyCommand> commands{ right, left, sright, sleft, close, jump };

	InputDriver* driver = new InputDriver(commands);
	std::unique_ptr<InputSystem> test_input = std::make_unique<InputSystem>(driver);

	return test_input;
}