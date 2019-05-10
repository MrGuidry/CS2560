// Frogger Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>   //using namespace sf 
#include <time.h> 
#include <iostream>
#include "Frogger Game.h"


//dimensions for window size and background 
const int num_vertBox = 17, num_horzBox = 14;
const int size = 64; //number of pixels 
const int w = size * num_horzBox;  //background number of pixels in width 
const int h = size * num_vertBox;    //background number of pixels in height 
const int numberOfLogs = 18;
const int numberOfCars = 18;

//Set initial direction to a value not dependent on a key press
int direction = -1;     



struct Part {
	int x, y;
};

class Car {
public:
	Part body[1];
	void move() {
		if (body[0].y % 2 == 0) {
			//Going Right && Check if goes out of bounds
			if (body[0].x == num_horzBox-1) {
				body[0].x = 0;
			}
			else {
				body[0].x++;
			}
		}
		else {
			//Going Left && check if goes out of bounds
			if (body[0].x == 0) {
				body[0].x = num_horzBox-1;
			}
			else {
				body[0].x--;
			}
		}
	}
};

class Log {
	int size = 3;
public:
	Part body[3];
	void move() {
		
		if (body[0].y % 2 == 0) {//Going Right && Check if goes out of bounds
			//Body
			for (int i = size - 1; i > 0; i--)
			{
				body[i].x = body[i - 1].x;
			}
			//Head
			if (body[0].x == num_horzBox-1) {
				body[0].x = 0;
			}
			else {
				body[0].x++;
			}
		}
		else {//Going Left && check if goes out of bounds
			
			//Body
			for (int i = size - 1; i > 0; i--)
			{
				body[i].x = body[i - 1].x;
			}
			//Head
			if (body[0].x == 0) {
				body[0].x = num_horzBox-1;
			}
			else {
				body[0].x--;
			}
		}
	}
	int getSize() { return size; }
};

class Frog {
public:
	bool won = false;
	bool gotHit = false;
	bool onLog = false;
	Part body[1];

	void resetPosition() {
		body[0].x = 7;
		body[0].y = 16;
	}

	void move() {
		//if user presses up
		if (direction == 0) {
			body[0].y -= 1;
		}
		//if user presses left 
		if (direction == 2) {
			body[0].x -= 1;
		}
		//if user presses right 
		if (direction == 3) {
			body[0].x += 1;
		}

		//Check Win condition 
		if (body[0].y == 0) {
			won = true;
		}

		//Boundary Detection
		//LEFT and RIGHT 
		if (body[0].x > num_horzBox - 1)
			body[0].x = 0;
		if (body[0].x < 0)
			body[0].x = num_horzBox - 1;

		//TOP and BOTTOM 
		if (body[0].y > num_vertBox - 1)
			body[0].y = num_vertBox - 1;
	}
};

int main()
{
	//Setting pseudorandom time, TODO:discuss true random vs pseudorandom  
	srand(time(0));

	//Window that we can play the game in  
	sf::RenderWindow window(sf::VideoMode(w, h), "Frogger");

	//Textures load an image into the GPU Memory 
	sf::Texture t1, t2, t3, t4, t5, t6, t7;
	t1.loadFromFile("image/Water_64x64.gif");		//Water
	t2.loadFromFile("image/Grass_64x64.png");		//Grass
	t3.loadFromFile("image/Street_64x64.png");		//Street
	t4.loadFromFile("image/Finish_64x64.jpg");		//Finish
	t5.loadFromFile("image/Log_64x64_u.jpg");		//Log
	t6.loadFromFile("image/car_left_64x64.png");	//Car left
	t7.loadFromFile("image/Frogger_64x64.png");		//Frogger


	//Sprite has physical dimmensions that can be set in  
	//coordinate system, setPosition(x,y), and drawn on screen 
	sf::Sprite sprite1(t1); 
	sf::Sprite sprite2(t2);
	sf::Sprite sprite3(t3);
	sf::Sprite sprite4(t4);
	sf::Sprite sprite5(t5);
	sf::Sprite sprite6(t6);
	sf::Sprite sprite7(t7);

	sf::Clock clock;
	float timer = 0.0f, delay = 0.35f;


	//CREATE ALL THE OBJECTS!!!!!!!!!!!!!!!
	Frog frog;
	Log logs[numberOfLogs];
	Car cars[numberOfCars];

	//Set positions for logs
	int index = 0;
	for (int i = 1; i < 7; i++) {
		for (int j = 3; j < num_horzBox; j += 4) {
			logs[index].body[2].x = j;
			logs[index].body[1].x = j-1;
			logs[index].body[0].x = j-2;

			logs[index].body[2].y = i;
			logs[index].body[1].y = i;
			logs[index].body[0].y = i;
			
			index++;
		}
	}

	//Set positions for cars
	index = 0;
	for (int i = 8; i < 16; i++) {
		if (i != 10 && i != 13) {
			for (int j = 3; j < num_horzBox; j += 4) {
				cars[index].body[0].x = j;
				cars[index].body[0].y = i;

				index++;
			}
		}
	}

	//Set position for frog
	frog.body[0].x = 7;
	frog.body[0].y = 16;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event e;

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//This is the minimize the carry over of user input for the direction during the movement phase
	
			//Control for Frogger by User 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction = 2;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction = 3;
		

		if (timer > delay)
		{
			timer = 0; //reset timer

			//Move Cars
			for (int i = 0; i < numberOfCars; i++) {
				cars[i].move();
			}

			//Move Frogger
			frog.move();
			direction = -1;

			//Checking if on log
			frog.onLog = false; //Resetting the boolean
			for (int i = 0; i < numberOfLogs; i++) {
				for (int j = 0; j < logs[i].getSize(); j++) {
					if (frog.body[0].x == logs[i].body[j].x && frog.body[0].y == logs[i].body[j].y) {
						frog.onLog = true;
					}
				}
			}

			//Move Logs
			for (int i = 0; i < numberOfLogs; i++) {
				logs[i].move();
			}

			//If frog is on a log 
			if (frog.onLog) {
				if (frog.body[0].y % 2 == 0) {
					frog.body[0].x++;
				}
				else {
					frog.body[0].x--;
				}
			}

			//Check if car hit frog
			for (int i = 0; i < numberOfCars; i++) {
				if (frog.body[0].x == cars[i].body[0].x && frog.body[0].y == cars[i].body[0].y) {
					frog.gotHit = true;
				}
			}

			//Check if in water
			if (!frog.onLog && frog.body[0].y > 0 && frog.body[0].y < 7 ) {
				frog.gotHit = true;
			}

			//Checks to see if frog won or got hit
			if (frog.won) {
				std::cout << "You Win!!!!!" << std::endl;
				delay -= 0.04f; //Decreases the delay so that timer will reach delay earlier so the game seem to go faster.
				frog.won = false; //Reset the Indicator
				frog.onLog = false; //Reset on a log
				frog.resetPosition();
			}
			else if (frog.gotHit) {
				delay = 0.35f; //Resets the delay back to what the game started as
				frog.gotHit = false; //Resets the Indicator
				frog.onLog == false; //Reset on a log
				frog.resetPosition();
			}
		}
		/*****************

		//Draw in window

		*****************/

		window.clear();    //clear the window so new frame can be drawn in 

		//1st: Draw Background first 
		for (int x = 0; x < num_horzBox; x++)
		{
			for (int y = 0; y < num_vertBox; y++)
			{
				if (y == 0) {//if y == ? for finish
					sprite4.setPosition(x*size, y*size);
					window.draw(sprite4);
				}
				else if (y >= 1 && y < 7) {//if y == ? for water
					sprite1.setPosition(x*size, y*size);
					window.draw(sprite1);
				}
				else if (y == 7 || y == 10 || y == 13 || y == 16) {//if y == ? for grass
					sprite2.setPosition(x*size, y*size);
					window.draw(sprite2);
				}
				else {//if y == ? for street 
					sprite3.setPosition(x*size, y*size);
					window.draw(sprite3);
				}					
			}
		}
		
		//Draw Logs
		for (int i = 0; i < numberOfLogs; i++){
			for (int j = 0; j < logs[i].getSize(); j++) { 
				sprite5.setPosition(logs[i].body[j].x*size, logs[i].body[j].y*size);
				window.draw(sprite5);
			}
		}
		
		//Draw Cars
		for (int i = 0; i < numberOfCars; i++) {
			sprite6.setPosition(cars[i].body[0].x*size, cars[i].body[0].y*size);
			window.draw(sprite6);
		}

		//Draw Frog
		sprite7.setPosition(frog.body[0].x*size, frog.body[0].y*size);
		window.draw(sprite7);

		//Show everything we have drawn on the screen 
		window.display();
	}
	return 0;
}