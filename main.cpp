#include<SFML/Graphics.hpp>
#include "birb.h"
#include "Flower.h"

int main() {

	//this next line is an array. Arrays are a lot like python lists.
	int birbColor[] = { 255, 200, 200 }; //set up an array of colors to make your birb PINK!
	int color[] = { 255, 255, 255 };
	int color1[] = { 255, 0, 0 };
	int color2[] = { 0,255, 0 };
	int color3[] = { 0,0, 255 };

	birb Alex(200, 200, birbColor); //instantiate 1 birb
	birb Alfred(300, 200, color);
	birb SeaBass(200, 300, color3);
	birb Eli(300, 300, color2);
	birb Cai(400, 200, color1);
	Flower Jeff(600, 600, color1);
	Flower Declan(500, 600, color);
	Flower Sebastian(400, 600, color2);
	Flower Martin(300, 600, color3);
	sf::RenderWindow window(sf::VideoMode(800, 800), "Happy Spring!"); //set up game window


	while (1) {//GAME LOOP OMG
		window.clear();
		Sebastian.draw(window);
		Martin.draw(window);
		Declan.draw(window);
		Jeff.draw(window);
		Jeff.ccolor(window);
		Declan.ccolor(window);
		Sebastian.ccolor(window);
		Martin.ccolor(window);
		Cai.draw(window);
		Eli.draw(window);
		Alfred.draw(window);
		Alex.draw(window);
		SeaBass.draw(window);
		Cai.fly(window);
		Eli.fly(window);
		Alfred.fly(window);
		SeaBass.fly(window);
		Alex.fly(window);
		window.display();
	}
}


