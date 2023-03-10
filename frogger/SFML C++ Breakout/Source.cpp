#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Brick.h"
#include <iostream>
using namespace std;
//-------------------------------------------------------------------------------

//----------------------------------------------------------------------------

//instantiate some bricks
brick b1(100, 100);
brick b2(225, 100);
brick b3(350, 100);
brick b4(475, 100);
brick b5(600, 100);
brick b6(100, 150);
brick b7(225, 150);
brick b8(350, 150);
brick b9(475, 150);
brick b10(600, 150);

// instantiate ball
ball spoon(500,400);
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Breakout"); //set up screen
	sf::RectangleShape rect;


	while (window.isOpen())//GAME LOOP--------------------------------
	{
		//input section--------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		//physics section------------------------------

		//render section-------------------------------
		window.clear();

		//draw bricks
		b1.draw(window);
		b2.draw(window);
		b3.draw(window);
		b4.draw(window);
		b5.draw(window);
		b6.draw(window);
		b7.draw(window);
		b8.draw(window);
		b9.draw(window);
		b10.draw(window);


		spoon.draw(window);
		window.display(); //flip the buffer

	}//end game loop-------------------------------------------------

	return 0;
} //end main