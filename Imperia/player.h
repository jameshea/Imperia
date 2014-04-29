#include <cmath>
#include <list>
#include "SFML\Graphics.hpp"
#include "game.h"

extern sf::Texture laser_texture;

class ship{
	sf::Texture texture;
	sf::Texture damage0;
	sf::Texture damage1;
	sf::Texture damage2;
	sf::Texture damage3;
	sf::Sprite sprite;
	sf::Sprite damage;
	//float x;
	//float y;

public:
	float x;
	float y;
	float rotation;
	float health;

	ship(float, float);
	void draw();
	void rotate(float);
	void move(float);
	void collision_border();

};


class laser{
	sf::Sprite sprite;
	//sf::Time timer1;
	//sf::Time timer2;
	sf::Clock live_time;
	//sf::Clock clock2;
	float x;
	float y;
	float rotation;
	int counter;

public:
	laser();
	void step();
	void draw();

};

extern ship player1;

extern std::list <laser> laser_list;