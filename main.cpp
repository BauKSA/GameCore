#include<chrono>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>

#include "AllegroManager.h"
#include "Utils.h"
#include "BaseActor.h"
#include "Timer.h"
#include "TickSystem.h"
#include "BasicCamera.h"
#include "GravityComponent.h"

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

    GlobalInput* global_input = initialize_global_input(running);
    global_input->start_listening();

    //------------
    //TESTING INIT
    //------------
    ComplexAnimatedActor* test_player = initialize_test();
    ActorInput<ComplexAnimatedActor>* test_input = initialize_input(test_player);

    al_clear_to_color(al_map_rgb(255, 255, 255));
    test_player->draw();
    al_flip_display();

    test_input->start_listening();
    test_player->move(RIGHT);
    //------------
    //TESTING  END
    //------------

    //Camera
    BasicCamera* camera = new BasicCamera("default", test_player, 1);

    //Components
    GravityComponent* gravity_component = new GravityComponent();
    //gravity_component->add_actor(test_player);

    //Systems
    TickSystem* tick_system = new TickSystem();
    tick_system->add_actor(test_player);
    tick_system->add_component(gravity_component);
    tick_system->set_camera(camera);


    ALLEGRO_BITMAP* background = al_load_bitmap("./background-test.png");
    ALLEGRO_BITMAP* screen = al_create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (running) {
        al_set_target_bitmap(screen);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background, 0, 0, NULL);

        float current_time = al_get_time();
        float delta_time = current_time - last_frame_time;
        last_frame_time = current_time;

        test_input->listen();
        global_input->listen();
        tick_system->update(delta_time);

        alManager->draw_to_display(screen);
    }

    return 0;
}