#include "Dependencies.h"
#include "Test.h"

int main(int argc, char** argv) {
	AllegroManager* alManager = new AllegroManager;
	alManager->init();

	if (alManager->failed()) {
		delete alManager;
		return -1;
	}

	float last_frame_time = al_get_time();
	bool running = true;

	//------------
	//TESTING INIT
	//------------
	ComplexAnimatedActor* test_player = initialize_test();
	InputSystem* test_input = initialize_input();
	test_input->start_listening();

	al_clear_to_color(al_map_rgb(255, 255, 255));
	test_player->draw();
	al_flip_display();
	//------------
	//TESTING  END
	//------------

	//Camera
	BasicCamera* camera = new BasicCamera("default", test_player, 1);

	//Components
	GravityComponent* gravity = new GravityComponent();
	JumpComponent* jump = new JumpComponent();

	test_player->add_component(gravity);
	test_player->add_component(jump);

	//Systems
	TickSystem* tick_system = new TickSystem();
	tick_system->add_actor(test_player);
	tick_system->set_camera(camera);


	ALLEGRO_BITMAP* background = al_load_bitmap("./background-test.png");
	ALLEGRO_BITMAP* screen = al_create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);

	GenericCommand* command{};
	InputHandler* handler = new InputHandler(test_player, &running);

	while (running) {
		al_set_target_bitmap(screen);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(background, 0, 0, NULL);

		float current_time = al_get_time();
		float delta_time = current_time - last_frame_time;

		// Debug: detectar fluctuaciones altas o bajas en delta_time
		if (delta_time > 0.1f) {
			std::cerr << "[WARNING] delta_time alto detectado: " << delta_time << " segundos. Posible freeze o lag." << std::endl;
		}
		else if (delta_time < 0.0001f) {
			std::cerr << "[WARNING] delta_time extremadamente bajo: " << delta_time << " segundos. Posible error de cálculo." << std::endl;
		}

		delta_time = std::min(delta_time, 0.066f);
		last_frame_time = current_time;

		command = test_input->listen();
		if (command) handler->check(command);

		tick_system->update(delta_time);

		alManager->draw_to_display(screen);

		// Asegurar que el frame rate no exceda un máximo (ejemplo: 60 FPS)
		float frame_time = al_get_time() - current_time;
		if (frame_time < (1.0f / 60.0f)) {
			al_rest((1.0f / 60.0f) - frame_time);  // Pausa para limitar a 60 FPS
		}
	}

	test_input->stop_listening();

	return 0;
}