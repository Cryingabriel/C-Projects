// Demonstrate primitve drawing in SFML
#include<iostream>
using namespace std;


#include <SFML/Graphics.hpp>

int main() {

    //game set up (you'll need these two lines in every game)
    sf::RenderWindow renderWindow(sf::VideoMode(600, 500), "Pong Paddle"); //set up screen
    sf::Event event; //set up event queue

    //paddle1 set up
    sf::RectangleShape paddle1(sf::Vector2f(10.0f, 100.0f));
    paddle1.setFillColor(sf::Color::Blue); //other colors: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php
    paddle1.setPosition(10.0f, 250.0f); //set position: this is where the top left corner will be
    //paddle2 set up
    sf::RectangleShape paddle2(sf::Vector2f(10.0f, 100.0f));
    paddle2.setFillColor(sf::Color::Blue);
    paddle2.setPosition(580.0f, 250.0f);
    //ball set up
    float ballx = 300;
    float bally = 250;
    float xvel = .01;
    float yvel = .01;
    sf::CircleShape ball(15);
    ball.setFillColor(sf::Color(200, 50, 50));
    ball.setPosition(300, 250);
    // player scores
    float point1 = 0;
    float point2 = 0;
    //################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
    while (renderWindow.isOpen()) {//keep window open until user shuts it down
        while (renderWindow.pollEvent(event)) { //look for events

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();

            //KEYBOARD INPUT (just one key to start
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //checks if "W" is pressed
                paddle1.move(0, -5); //move the rectangle 5 pixels UP on the y axis
                cout << "rectangle moving up" << endl; //for Mo's testing, you can take this out
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                paddle1.move(0, 5);
                cout << "Rectangle moviing down" << endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { //checks if "W" is pressed
                paddle2.move(0, -5); //move the rectangle 5 pixels UP on the y axis
                cout << "rectangle2 moving up" << endl; //for Mo's testing, you can take this out
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                paddle2.move(0, 5);
                cout << "Rectangle2 moviing down" << endl;
            }

        }
        //physics section
        ballx += xvel;
        bally += yvel;
        ball.setPosition(ballx, bally);
        //paddle collision
        if (ballx - 10 < paddle1.getPosition().x && bally > paddle1.getPosition().y && bally < paddle1.getPosition().y + 100) {
            cout << "paddle1 collision" << endl;
            //add sound effect here
            xvel *= -1;
        }
        if (ballx + 30 > paddle2.getPosition().x && bally > paddle2.getPosition().y && bally < paddle2.getPosition().y + 100) {
            cout << "paddle2 collision" << endl;
            //add effect here
            xvel *= -1;
        }
        if (paddle1.getPosition().y < 0 || paddle1.getPosition().y > 400) {
            paddle1.move(0, 0);
        }
        if (paddle2.getPosition().y < 0 || paddle2.getPosition().y > 400) {
            paddle2.move(0, 0);
        }
        // reflect off left and right walls
        if (ballx < 0 || ballx > 585) {
            xvel *= -1;
        }
        if (bally < 0 || bally > 485) {
            yvel *= -1;
        }
        if (ballx <= 0) {
            point2 += 1;
        }
        if(ballx >= 585) {
            point1 += 1;
        }
        //render section-----------------------------------------
        
        renderWindow.clear(); //wipes screen, without this things smear
        renderWindow.draw(paddle1); //you gotta drew each object
        renderWindow.draw(paddle2);
        renderWindow.draw(ball);
        renderWindow.display(); //flips memory drawings onto screen

    }//######################## end game loop ###################################################################################

    cout << "goodbye!" << endl;
} //end game