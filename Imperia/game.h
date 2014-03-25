#include <SFML\Graphics.hpp>

#ifndef GAME_H
#define GAME_H

//Create a main window for SFML//
extern sf::RenderWindow window;
//Create a main window for SFML//

//Common window get functions//
sf::Vector2i window_get_position();
sf::Vector2u window_get_size();
//Common window get functions//

//Common window set functions//
bool window_set_framelimit(unsigned int);
void window_set_position(int, int);
void window_set_size(unsigned int, unsigned int);
void window_set_title(sf::String);
void window_set_vsync(bool);
void window_set_visible(bool);
//Common window set functions//

//Common game functions//
void mouse_visible(bool);
//Common game functions//
#endif