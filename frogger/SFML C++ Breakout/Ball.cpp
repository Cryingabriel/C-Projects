#include "Ball.h"
#include<SFML/Graphics.hpp>


ball::ball(int bx, int by) {
	xpo += bx;
	ypo += by;
	gall = sf::CircleShape(15);
}

void ball::draw(sf::RenderWindow& window) {
	gall.setFillColor((sf::Color(0, 200, 0)));
	gall.setPosition(xpo, ypo);
	window.draw(gall);
}