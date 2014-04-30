#include <Windows.h>
#include <SFML\Graphics.hpp>
#include "game.h"
#include "meteors.h"
#include "player.h"
#include "vld.h"

int main()
{
	//Frame dependencies//
	sf::Clock frame;
	window_set_framelimit(60);
	//Frame dependencies//

    //File and resource loading//
	meteor_big1.loadFromFile("Resources/Sprites/Meteors/brown_big1.png");
	meteor_big2.loadFromFile("Resources/Sprites/Meteors/brown_big2.png");
	meteor_big3.loadFromFile("Resources/Sprites/Meteors/brown_big3.png");
	meteor_big4.loadFromFile("Resources/Sprites/Meteors/brown_big4.png");
	meteor_med1.loadFromFile("Resources/Sprites/Meteors/brown_med1.png");
	meteor_med2.loadFromFile("Resources/Sprites/Meteors/brown_med2.png");
	laser_texture.loadFromFile("Resources/Sprites/Effects/laser_blue.png");
	//File and resource loading//
	
	//Create Event//
	for (int i = 1; i <= 3; i++){
		meteorite met;
		meteor_list.push_front(met);
	}
	//Create Event//

	//Game Loop//
    while (window.isOpen())
    {
		frame.restart().asSeconds();

        //Check Events//
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		//Check Events//

		//Collision Event//
		//Collision Event//

		//Step Event//
			//Keyboard Events//
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				if (refire.getElapsedTime().asMilliseconds() >= 500){
					laser bullet;
					laser_list.push_front(bullet);
				}
			}
			//Keyboard Events//
		for (std::list<meteorite>::iterator it = meteor_list.begin(); it != meteor_list.end(); ++it){
			it->step();
		}
		for (std::list<laser>::iterator it = laser_list.begin(); it != laser_list.end(); ++it){
			it->step(it);
			if (it->live_time.getElapsedTime().asMilliseconds() >= 1000){
				it = laser_list.erase(it);
				break;
			}
		}
		//Step Event//

        window.clear();

		//Draw Event//
		for (std::list<meteorite>::iterator it = meteor_list.begin(); it != meteor_list.end(); ++it){
			it->draw();
		}
		for (std::list<laser>::iterator it = laser_list.begin(); it != laser_list.end(); ++it){
			it->draw();
		}

		player1.draw();
		//Draw Event//

        window.display();

        printf("%.2f \n", 1.0/frame.getElapsedTime().asSeconds());
    }
	//Game Loop

    return 0;
}