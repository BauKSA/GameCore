#include<iostream>

#include "BasicCamera.h"
#include "Utils.h"

#define MARGIN 200

void BasicCamera::set_actor_position() {
	x = actor->get_x() - MARGIN;
	y = actor->get_y() - MARGIN;

	if (x < 0) x = 0;
	if (x + SCREEN_WIDTH > WORLD_WIDTH) x = WORLD_WIDTH - SCREEN_WIDTH;

	if (y < 0) y = 0;
	if (y + SCREEN_HEIGHT > WORLD_HEIGHT) y = WORLD_HEIGHT - SCREEN_HEIGHT;

	update_xy_to_screen();
}

void BasicCamera::update_xy_to_screen() {
	apply();
}

void BasicCamera::apply() {
	ALLEGRO_TRANSFORM transform;
	al_identity_transform(&transform);

	float display_width = SCREEN_WIDTH;
	float display_height = SCREEN_HEIGHT;

	al_scale_transform(&transform, zoom, zoom);
	al_translate_transform(&transform, -x, -y);
	al_use_transform(&transform);

	draw_margins();
}

void BasicCamera::draw_margins() const {
	al_draw_rectangle(
		x,
		y,
		x + SCREEN_WIDTH,
		y + SCREEN_HEIGHT,
		al_map_rgb(255, 0, 0),
		2.0
	);
}