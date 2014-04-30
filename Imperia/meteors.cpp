#include "meteors.h"

sf::Texture meteor_big1;
sf::Texture meteor_big2;
sf::Texture meteor_big3;
sf::Texture meteor_big4;
sf::Texture meteor_med1;
sf::Texture meteor_med2;

std::list<meteorite> meteor_list;

meteorite::meteorite(){
	int var1 = 0;

	x = rand() % 1024;
	y = rand() % 640;
	spin = 1 /(rand()%100+0.001);
	speed = spin * 10;
	direction = rand() % 360;

		sprite.setOrigin(meteor_big1.getSize().x/2,meteor_big1.getSize().y/2);
		radius = meteor_big1.getSize().x/2;
		health = 100;

	static_health = health;

	sprite.setTexture(meteor_big1);
	sprite.setScale(1, 1);
	sprite.setPosition(x, y);
}

void meteorite::step(){
	sprite.rotate(spin);

	x += (speed*std::cosf(direction*(3.14159/180)))/10;
	y += (speed*std::sinf(direction*(3.14159/180)))/10;
	sprite.setPosition(x, y);

	if (health <= 0){
		x = rand() % 1024;
		y = rand() % 640;
		health = static_health;
	}

	if (x < 0-radius)
		x = 1024 + radius;
	else if (x > 1024+radius)
		x = 0 - radius;

	if (y < 0-radius)
		y = 640 + radius;
	else if (y > 640+radius)
		y = 0 - radius;



	//if ((player1.x > x-radius)&&(player1.x < x+radius)&&(player1.y > y-radius)&&(player1.y < y+radius)){
		//player1.health -= radius;
		//x = rand() % 1024;
		//y = rand() % 640;
	//}
				
}

void meteorite::collision_border(){
	if (x < -100)
		direction += 180;
	if (x > 1124)
		direction += 180;
	if (y < -100)
		direction += 180;
	if (y > 740)
		direction += 180;
}

void meteorite::draw(){
	window.draw(sprite);
}