#include "Test.h"

BaseActor* initialize_test() {
	BaseActor* actor = new BaseActor("test_actor", 10, 10, "./test.png", 15);

	return actor;
}

static std::vector<Actions> set_actions() {
	std::vector<Actions> actions;
	Actions up = Actions{ ALLEGRO_KEY_W, "up" };
	Actions down = Actions{ ALLEGRO_KEY_S, "down" };
	Actions right = Actions{ ALLEGRO_KEY_D, "right" };
	Actions left = Actions{ ALLEGRO_KEY_A, "left" };

	actions.push_back(up);
	actions.push_back(down);
	actions.push_back(right);
	actions.push_back(left);

	return actions;
}

InputSystem* initialize_input(BaseActor* actor) {
	std::vector<Actions> actions = set_actions();
	InputSystem* actor_input = new InputSystem(actor, actions, [](std::string action, BaseActor* actor) {
		if (action == "right") {
			std::cout << "MOVEMOS AL PJ A LA DERECHA" << std::endl;
			actor->move(RIGHT);
		}
	});

	return actor_input;
}