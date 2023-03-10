#include "Brick.h"
#include<SFML/Graphics.hpp>
brick::brick(int x, int y) {
	xpos = x;
	ypos = y;

}

void brick::draw(sf::RenderWindow& window) {
	rect.setSize(sf::Vector2f(100, 20));
	rect.setFillColor((sf::Color(0, 200, 0)));
	rect.setPosition(xpos, ypos);
	window.draw(rect);
}