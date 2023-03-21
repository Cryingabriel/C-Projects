#include "Class.h"
#include "globals.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Car.h"
using namespace std;
int timer = 0;


int main() {

	//game variables and setup
	srand(time(NULL)); //seed rand
	bool keys[] = { false, false, false, false }; //used for user input

	//SFML boilerplate stuff
	sf::RenderWindow screen(sf::VideoMode(1000, 1000), "Frogger!");
	vector<car*> cars;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 1; j++) {
			cars.push_back(new car(i * 400 + 100, j * 200 + 500, LEFT));
			cars.push_back(new car(i * 300 + 200, j * 200 + 600, RIGHT));
		}
	frog player; //instantiate a frog!
	while (screen.isOpen()) { //gameloop####################################
		//input section-----------------------
		sf::Event event;
		while (screen.pollEvent(event)){//look for user input
			if (event.type == sf::Event::Closed) // check if the game window is closed
				screen.close();
			//UP
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				keys[UP] = true;
			}
			else keys[UP] = false;
			//DOWN
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				keys[DOWN] = true;
			}
			else keys[DOWN] = false;
			//Left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				keys[LEFT] = true;
			}
			else keys[LEFT] = false;
			//Right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				keys[RIGHT] = true;
			}
			else keys[RIGHT] = false;
		}
		//physics section------------------------------------
		
		timer++;
		if (timer > 4000) {
			player.jump(keys);
			timer = 0;
		}


		//render section-------------------------------------
		screen.clear();
		player.draw(screen);



		screen.display();
	}//end gameloop############################################################
	cout << "game over." << endl;
	return 0;
}