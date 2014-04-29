#include <list>
#include <SFML\Graphics.hpp>
#include "game.h"

#ifndef METEORS_H
#define METEORS_H

extern sf::Texture meteor_big1;
extern sf::Texture meteor_big2;
extern sf::Texture meteor_big3;
extern sf::Texture meteor_big4;
extern sf::Texture meteor_med1;
extern sf::Texture meteor_med2;

class meteorite{
	sf::Sprite sprite;
	float spin;
	float speed;
	float direction;
	
public:
	meteorite();
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

extern std::list<meteorite> meteor_list;

#endif