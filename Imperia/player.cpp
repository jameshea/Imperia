#include "player.h"


std::list <laser> laser_list;
sf::Texture laser_texture;

ship::ship(float pos_x, float pos_y){
	x = pos_x;
	y = pos_y;

	texture.loadFromFile("Resources/Sprites/Ships/ship_red.png");
	damage0.loadFromFile("Resources/Sprites/Effects/damage0.png");
	damage1.loadFromFile("Resources/Sprites/Effects/damage1.png");
	damage2.loadFromFile("Resources/Sprites/Effects/damage2.png");
	damage3.loadFromFile("Resources/Sprites/Effects/damage3.png");
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5);
	sprite.setOrigin(75/2, 112/2);
	sprite.setPosition(x, y);
	damage.setTexture(damage0);
	damage.setScale(0.5, 0.5);
	damage.setOrigin(75/2, 112/2);
	damage.setPosition(x, y);

	health = 100;
}

void ship::draw(){
	window.draw(sprite);
	window.draw(damage);
}

void ship::rotate(float angle){
	sprite.rotate(-angle);
	damage.rotate(-angle);
}

void ship::move(float speed){
	x += (speed*std::cosf(sprite.getRotation()*(3.14159/180)))/10;
	y += (speed*std::sinf(sprite.getRotation()*(3.14159/180)))/10;
	rotation = sprite.getRotation();
	sprite.setPosition(x, y);
	damage.setPosition(x, y);
		
	if (health > 75){
		damage.setTexture(damage0);
	}
	else if (health <= 75 && health > 50){
		damage.setTexture(damage1);
	}
	else if (health <= 50 && health > 25){
		damage.setTexture(damage2);
	}
	else if (health <= 25 && health > 0){
		damage.setTexture(damage3);
	}
	else{
		health = 100;
		x = rand() % 1024;
		y = rand() % 640;
	}
}

void ship::collision_border(){
	if (x < -50)
		x = 1074;
	if (x > 1074)
		x = -50;
	if (y < -50)
		y = 690;
	if (y > 690)
		y = -50;
}

ship player1(100, 100);



laser::laser(){
	sprite.setTexture(laser_texture);
	sprite.setOrigin(laser_texture.getSize().x/2,laser_texture.getSize().y/2);
	x = player1.x;
	y = player1.y;
	sprite.setPosition(x, y);
}

void step(){
	
	/*rotation = player1.rotation;
	sprite.setPosition(x, y);
	sprite.setRotation(rotation);
	clock1.restart();
	}*/
}

void draw(){
	//window.draw(sprite);
}