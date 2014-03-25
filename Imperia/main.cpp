#include <SFML\Graphics.hpp>
#include "game.h"

int main()
{
    //Create Event//
	sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
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
		//Step Event//

        window.clear();

		//Draw Event//
        window.draw(shape);
		//Draw Event//

        window.display();

    }
	//Game Loop

    return 0;
}