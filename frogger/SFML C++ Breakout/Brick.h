#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
class brick {
private:
	int xpos;
	int ypos;
	sf::RectangleShape rect;
public:
	brick(int x, int y); //constructor
	void draw(sf::RenderWindow& window);
};

