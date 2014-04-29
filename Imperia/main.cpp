#include <SFML\Graphics.hpp>
#include "game.h"
#include "meteors.h"
#include "vld.h"

int main()
{
    //File and resource loading//
	meteor_big1.loadFromFile("Resources/Sprites/Meteors/brown_big1.png");
	meteor_big2.loadFromFile("Resources/Sprites/Meteors/brown_big2.png");
	meteor_big3.loadFromFile("Resources/Sprites/Meteors/brown_big3.png");
	meteor_big4.loadFromFile("Resources/Sprites/Meteors/brown_big4.png");
	meteor_med1.loadFromFile("Resources/Sprites/Meteors/brown_med1.png");
	meteor_med2.loadFromFile("Resources/Sprites/Meteors/brown_med2.png");
	//File and resource loading//
	
	//Create Event//
	sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	
	meteorite met1;
	met1.create();
	//Create Event//

	//Game Loop//
    while (window.isOpen())
    {
        //Pre-Step Event//
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		//Pre-Step Event//

		//Collision Event//
		//Collision Event//

		//Step Event//
		met1.step();
		//Step Event//

        window.clear();

		//Draw Event//
        window.draw(shape);
		met1.draw();
		//Draw Event//

        window.display();

    }
	//Game Loop

    return 0;
}