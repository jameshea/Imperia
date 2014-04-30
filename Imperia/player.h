#include <cmath>
#include <list>
#include "SFML\Graphics.hpp"
#include "game.h"

extern sf::Texture laser_texture;
extern sf::Clock refire;

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
	float speed;

	ship(float, float);
	void draw();
	void rotate(float);
	void move();
	void collision_border();

};


class laser{
	sf::Sprite sprite;
	//sf::Time timer1;
	//sf::Time timer2;
	
	//sf::Clock clock2;
	float x;
	float y;
	float rotation;
	float speed;
	int counter;

public:
	laser(float);
	~laser();
	sf::Clock live_time;
	void step();
	void draw();
	bool done();
	void destroy();
};

extern ship player1;

extern std::list <laser> laser_list;