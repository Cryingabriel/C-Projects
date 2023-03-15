#include<SFML/Graphics.hpp>
#include<iostream>
#include <random>
#include "globals.h"
using namespace std;

class car {
private:
	float xpos;
	float ypos;
	int green = rand() % 100 + 100;
	int blue = rand() % 100 + 100;
	int direction = RIGHT;
public:
	car(int x, int y, int d) {
		xpos = x;
		ypos = y;
		direction = d;
	}
	void draw(sf::RenderWindow& window);
	void move();
	bool collide(int x, int y);
	void printinfo() { cout << "I am a car and my position is " << xpos << "," << ypos << endl; }
};



