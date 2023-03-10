#include <iostream>
#include<SFML/Graphics.hpp>// make sure that your in x64 solution platform
using namespace std;

int main()
{
    //game set up----------------------------------------------------------------------
    sf::RenderWindow renderWindow(sf::VideoMode(800, 800), "Simple Jumper"); //set up screen
    sf::Event event; //set up event queue
    sf::Clock clock; //set up the clock (needed for game timing)
    const float FPS = 60.0f; //FPS
    renderWindow.setFramerateLimit(FPS); //set FPS

    //player setup----------------------------------------------------------------------
    sf::RectangleShape player(sf::Vector2f(30, 30));//size of player (30x30 square)
    player.setFillColor(sf::Color::White);
    float xpos = 25;
    float ypos = 25;
    player.setPosition(xpos, ypos); //set position: this is where the top left corner will be
    //player velocity
    float vx = .0;
    float vy = .0;
    bool isOnGround = false; //needed to apply gravity
    bool keys[] = { false, false, false, false };

    //platform 1 set up----------------------------------------------------------------------
    sf::RectangleShape platform1(sf::Vector2f(100, 30)); //size of platform (100 x 30 rectangle)
    platform1.setFillColor(sf::Color::Red);
    platform1.setPosition(100, 700);

    //TODO: Add more platforms here!

    sf::RectangleShape platform2(sf::Vector2f(100, 30)); //size of platform (100 x 30 rectangle)
    platform2.setFillColor(sf::Color::Yellow);
    platform2.setPosition(200, 600);// position of the platform

    // third platform
    sf::RectangleShape platform3(sf::Vector2f(100, 30)); //size of platform (100 x 30 rectangle)
    platform3.setFillColor(sf::Color::Blue);
    platform3.setPosition(300, 500);

    // fourth platform
    sf::RectangleShape platform4(sf::Vector2f(100, 30)); //size of platform (100 x 30 rectangle)
    platform4.setFillColor(sf::Color::Green);
    platform4.setPosition(400, 700);

    //################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
    while (renderWindow.isOpen()) {//keep window open until user shuts it down 

        while (renderWindow.pollEvent(event)) { //input section-----------------------

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) keys[2] = true;
            else keys[2] = false;


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) keys[0] = true;
            else keys[0] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) keys[1] = true;
            else keys[1] = false;

            //TODO: add left movement here

        }//end event loop---------------------------------------------------------------

        //physics-----------------------------------------------------------------------

        //jumping
        if (keys[2] == true)
            if (isOnGround == true) {
                vy = -15;
                isOnGround = false;
            }

        //right movement
        if (keys[0] == true) {
            vx = 8;
        }
        //Lef movement
        else if (keys[1] == true) {
            vx = -8;
        }
        else {
            vx = 0;
        }

        //TODO: alter the above code to handle left movement too!

        //GRAVITY
        if (ypos + 30 > 800) {//check if we've reached the bottom of the screen
            isOnGround = true;
            ypos = 800 - 30; //reset position so feet are on ground
        }
        else
            isOnGround = false;

        //apply gravity if not on ground
        if (isOnGround == false) {
            vy += 1; //notice we're ACCELERATING (set equal for steady falling pace)
            if (vy > 5) //set TERMINAL VELOCITY
                vy = 5;
        }

        //FRICTION-----------------------------------------------------------------------
        if (isOnGround == true)
            vx *= .85;
        else
            vx *= .95; //less friction in the air



        //Collide with platform 1-----------------------------------------------------
        if (ypos + 30 >= 700 && ypos <= 700 + 30 && xpos + 30 >= 100 and xpos <= 200) {
            isOnGround = true;
            ypos = 700 - 30; //counteract gravity
        }
        //TODO: add more collision checks with the other platforms you make
        if (ypos + 30 >= 600 && ypos <= 600 + 30 && xpos + 30 >= 200 and xpos <= 300) {
            isOnGround = true;
            ypos = 600 - 30; //counteract gravity
        }
        //third platform
        if (ypos + 30 >= 500 && ypos <= 500 + 30 && xpos + 30 >= 300 and xpos <= 400) {
            isOnGround = true;
            ypos = 500 - 30; //counteract gravity
        }
        if (ypos + 30 >= 700 && ypos <= 700 + 30 && xpos + 30 >= 400 and xpos <= 500) {
            isOnGround = true;
            ypos = 700 - 30; //counteract gravity
        }
        if (xpos + 30 >= 30)
        //actually move the player!---------------------------------------------------------
        xpos += vx;
        ypos += vy;
        player.setPosition(xpos, ypos);
        cout << "speed is" << vy << endl;
        //cout << "isOnGround is " << isOnGround << endl; //for testing purposes
        //cout << "player x and y are " << xpos << " , " << ypos << endl;

        clock.restart();
        //render section-----------------------------------------
        renderWindow.clear(); //wipes screen, without this things smear 
        renderWindow.draw(player); //you gotta draw each object
        renderWindow.draw(platform1); //you gotta draw each object
        renderWindow.draw(platform2);
        renderWindow.draw(platform3);
        renderWindow.draw(platform4);
        renderWindow.display(); //flips memory drawings onto screen

    }//######################## end game loop ###################################################################################

    cout << "goodbye!" << endl;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

