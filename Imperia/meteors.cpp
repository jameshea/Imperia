#include "meteors.h"


void meteorite::create(){
	int var1 = 0;

	x = rand() % 1024;
	y = rand() % 640;
	spin = 1 /(rand()%100+0.001);
	speed = spin * 10;
	direction = rand() % 360;

	var1 = rand() % 10;
	if (var1 == 0){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_big1.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 100;
	}
	if (var1 == 1){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_big2.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 100;
	}
	if (var1 == 2){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_big3.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 75;
	}
	if (var1 == 3){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_big4.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 75;
	}
	if (var1 == 4){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_med1.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 50;
	}
	if (var1 == 5){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_med2.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 50;
	}
	if (var1 == 6){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_small1.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 25;
	}
	if (var1 == 7){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_small2.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 25;
	}
	if (var1 == 8){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_tiny1.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 15;
	}
	if (var1 == 9){
		texture.loadFromFile("Resources/Sprites/Meteors/brown_tiny2.png");
		sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
		radius = texture.getSize().x/2;
		health = 15;
	}
	static_health = health;

	sprite.setTexture(texture);
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