#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class ball {
private:
	int xpo;
	int ypo;
	sf::CircleShape gall;
public:
	ball(int bx, int by); //constructor
	void draw(sf::RenderWindow& window);
};