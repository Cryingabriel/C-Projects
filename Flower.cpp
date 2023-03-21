#include "Flower.h"

Flower::Flower(int x, int y, int c[3]) {
	xpos = x;
	ypos = y;
	color[0] = c[0]; //if our array was any longer I would have used a for loop here :)
	color[1] = c[1];
	color[2] = c[2];

}

void Flower::draw(sf::RenderWindow& window) {
	stem.setPosition(xpos + 10, ypos + 35);
	stem.setFillColor(sf::Color(200, 150, 0));
	stem.setSize(sf::Vector2f(15, 100));
	window.draw(stem); //first leg

	pedal.setRadius(20);
	pedal.setFillColor((sf::Color(color[0], color[1], color[2]))); //noticing accessing slots of an array is just like getting to slots of a list
	pedal.setPosition(xpos - 30, ypos - 30);
	window.draw(pedal);

	pedal1.setRadius(20);
	pedal1.setFillColor((sf::Color(color[0], color[1], color[2]))); //noticing accessing slots of an array is just like getting to slots of a list
	pedal1.setPosition(xpos + 25, ypos - 30);
	window.draw(pedal1);

	pedal4.setRadius(20);
	pedal4.setFillColor((sf::Color(255,255,0))); //noticing accessing slots of an array is just like getting to slots of a list
	pedal4.setPosition(xpos-3, ypos);
	window.draw(pedal4);

	pedal2.setRadius(20);
	pedal2.setFillColor((sf::Color(color[0], color[1], color[2]))); //noticing accessing slots of an array is just like getting to slots of a list
	pedal2.setPosition(xpos - 30, ypos + 30);
	window.draw(pedal2);

	pedal3.setRadius(20);
	pedal3.setFillColor((sf::Color(color[0], color[1], color[2]))); //noticing accessing slots of an array is just like getting to slots of a list
	pedal3.setPosition(xpos + 25, ypos + 30);
	window.draw(pedal3); 
}

void Flower::ccolor(sf::RenderWindow& window) {
	int num = rand() % 255;
	int num1 = rand() % 255;
	int num2 = rand() % 255;
	int num3 = rand() % 100;

	if (num3 < 5) {
		color[0] = num;
		color[1] = num1;
		color[2] = num2;
	}
	
}