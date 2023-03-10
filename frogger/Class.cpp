#include "Class.h"
#include "globals.h"
#include<SFML/Graphics.hpp>
#include<Windows.h>



//constructor: fills in all the needed class variables
frog::frog() {
	xpos = 500;
	ypos = 954;
	lives = 5;
	xvel = 0;
	yvel = 0;
}

// draw function draws small green square for frog
void frog::draw(sf::RenderWindow& window) {
	sf::RectangleShape Frogpic(sf::Vector2f(20, 20));
	Frogpic.setFillColor(sf::Color(50, 200, 50));
	Frogpic.setPosition(xpos, ypos);
	window.draw(Frogpic);
}

//movement function for frog (unfinished)
//this function takes a POINTER to ther array that holds the key presses
void frog::jump(bool* keys) {
	if (keys[UP] == true)
		yvel = -50;
	else if (keys[DOWN] == true)
		yvel = 50;
	else
		yvel = 0;
	ypos += yvel;
	if (keys[LEFT] == true)
		xvel = -50;
	else if (keys[RIGHT] == true)
		xvel = 50;
	else
		xvel = 0;
	xpos += xvel;
}

//this function kills the frog
void frog::ded() {
	//play explosion sound here
	Beep(500, 500); //temporary until we get sound effects!
	//maybe ass explosion animation eventually
	lives--;
	xpos = 500;
	ypos = 954;
}

