#include <SFML\Graphics.hpp>

#include "game.h"

#ifndef METEORS_H
#define METEORS_H

class meteorite{
	sf::Texture texture;
	sf::Sprite sprite;
	float spin;
	float speed;
	float direction;
	
public:
	float x;
	float y;
	int radius;
	int health;
	int static_health;

	void create();
	void step();
	void collision_border();
	void draw();
};

#endif