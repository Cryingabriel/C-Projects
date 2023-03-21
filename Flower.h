#pragma once

#include<SFML/Graphics.hpp>


class Flower
{
private:
	int xpos;
	int ypos;
	int color[3];

	sf::CircleShape pedal;
	sf::CircleShape pedal1;
	sf::CircleShape pedal2;
	sf::CircleShape pedal3;
	sf::CircleShape pedal4;
	sf::RectangleShape stem;
public:
	Flower(int x, int y, int color[3]);
	void draw(sf::RenderWindow& window);
	void ccolor(sf::RenderWindow& window);
};

