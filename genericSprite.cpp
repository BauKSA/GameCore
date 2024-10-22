#include<iostream>
#include "GenericSprite.h"

void GenericSprite::draw(int flags) {
	if (!sprite) {
		std::cerr << "Image charging failed for " << name << std::endl;
	}

	al_draw_bitmap(sprite, x, y, flags);
}