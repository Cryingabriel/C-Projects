#include"Car.h"
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;

//draw the 'car'

void car::draw(sf::RenderWindow& window) {
	sf::RectangleShape vehicle(sf::Vector2f(100, 50));
	vehicle.setFillColor(sf::Color(250, green, blue));
	vehicle.setPosition(xpos, ypos);
	window.draw(vehicle);
}

//movement fuction: can move left or right
//resets position to the other side when it moves off screen
void car::move() {
	if (direction == LEFT) {
		if (xpos < -100)
			xpos = 1100;
		xpos -= .1;
	}
	else if (direction == RIGHT) {
		if (xpos > 1100)
			xpos = -100;
		xpos -= .1;
	}


}

bool car::collide(int x, int y) {
	if (x > xpos+100) {
		if (x < xpos) {
			cout << "DEAD" << endl;
			return true;
		}
		
	}
	else
		return false;
}