#include "Test.h"
#include "JoystickMapping.h"

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

	ComplexAnimatedActor* actor = new ComplexAnimatedActor("test_actor", 50, SCREEN_HEIGHT - 100, .125);
	actor->initialize_sprite({ _default, left, right });

	return actor;
}

InputSystem* initialize_input() {
	MoveRightCommand* move_right = new MoveRightCommand();
	MoveLeftCommand* move_left = new MoveLeftCommand();
	StandRightCommand* stand_right = new StandRightCommand();
	StandLeftCommand* stand_left = new StandLeftCommand();
	CloseCommand* _close = new CloseCommand();

	KeyCommand right(JOY_BUTTON_RIGHT, true, move_right);
	KeyCommand left(JOY_BUTTON_LEFT, true, move_left);
	KeyCommand sright(JOY_BUTTON_RIGHT, false, stand_right);
	KeyCommand sleft(JOY_BUTTON_LEFT, false, stand_left);
	KeyCommand close(JOY_BUTTON_START, true, _close);

	std::vector<KeyCommand> commands{ right, left, sright, sleft, close };

	InputDriver* driver = new InputDriver(commands);
	InputSystem* test_input = new InputSystem(driver);

	return test_input;
}