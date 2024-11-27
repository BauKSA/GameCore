#include "Test.h"
#include "JoystickMapping.h"

std::vector<BaseActor*> initialize_bricks() {
	std::vector<BaseActor*> bricks{};
	for (size_t i = 0; i < 8; i++) {
		std::string name = "brick-" + std::to_string(i);
		BaseActor* brick = new BaseActor(name, 32 * i, 125);
		brick->initialize_sprite("./test-brick.png");
		bricks.push_back(brick);
	}

	std::string name = "brick-b";
	BaseActor* brick = new BaseActor(name, (32 * 5) + 0.01, 93);
	brick->initialize_sprite("./test-brick.png");
	bricks.push_back(brick);

	return bricks;
}

ComplexAnimatedActor* initialize_test() {
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

	ComplexAnimatedActor* actor = new ComplexAnimatedActor("test_actor", 50, 0, 2.125);
	actor->initialize_sprite({ _default, left, right });

	return actor;
}

InputSystem* initialize_input() {
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
	InputSystem* test_input = new InputSystem(driver);

	return test_input;
}