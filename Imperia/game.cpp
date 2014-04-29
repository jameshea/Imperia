#include "game.h"


//Create a main window for SFML//
sf::RenderWindow window(sf::VideoMode(1024, 640), "SFML works!");
//Create a main window for SFML//

//Common window get functions//
sf::Vector2i window_get_position(){
	return window.getPosition();
}
sf::Vector2u window_get_size(){
	return window.getSize();
}
//Common window get functions//

//Common window set functions//
bool window_set_framelimit(unsigned int limit){
	if (limit > 20){
		window.setFramerateLimit(limit);
		return 0;
	}
	else
	{
		return 1;
	}
}
void window_set_position(int x, int y){
	window.setPosition(sf::Vector2i(x, y));
}
void window_set_size(unsigned int height, unsigned int width){
	window.setSize(sf::Vector2u(height, width));
}
void window_set_title(sf::String title){
	window.setTitle(title);
}
void window_set_vsync(bool vsync){
	window.setVerticalSyncEnabled(vsync);
}
void window_set_visible(bool visible){
	window.setVisible(visible);
}
//Common window set functions//

//Common game functions//
void mouse_visible(bool visible){
	window.setMouseCursorVisible(visible);
}
//Common game functions//