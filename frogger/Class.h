#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;



class frog {
private: //can only be seen/used by class members
	float xpos;
	float ypos;
	int lives;
	float xvel;
	float yvel;


public: //can be seen/used by anything in the program
	frog(); // constructor
	void draw(sf::RenderWindow& window); // & retruns the address of the pointer
	void jump(bool* keys); // * returns the value of the pointer
	float returnx() { return xpos; } // small enough to define here instead of .cpp file
	float returny() { return ypos; }
	void ded();
	int returnlives() { return lives; }
	void printinfo() { cout << "I am a frog and py position is" << xpos << "," << ypos << endl; }
};

