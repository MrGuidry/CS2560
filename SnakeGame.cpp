// SFML_Test.cpp : snake game 

#include "pch.h" 
#include <SFML/Graphics.hpp>   //using namespace sf 
#include <time.h> 
#include <iostream>

//Scores for each player
int score1 = 0;
int score2 = 0;

//These are used to update the speed of the game
bool ateFruit,ateFruit2 = false; //Used to speed the game up
bool ateItself,ateItself2 = false; //Used to slow the game down

//dimensions for window size and background 
int num_vertBox = 30, num_horzBox = 20;
int size = 16; //number of pixels 
int w = size * num_horzBox;  //background number of pixels in width 
int h = size * num_vertBox;    //background number of pixels in height 

//Snake variables to dertermine length and direction 
int direction,direction2;    //direction the snake is moving  
int snake_length = 4; //initial size is 4  
int snake_length2 = 4; //Second snake intial size

//Actual Snake in game is an array of x,y coordinates of sprite2 
struct Snake
{
	int x, y;        //each sprite of snake needs an x,y coordinate 
}s[100];

//Second Snake
struct Snake2
{
	int x, y;        //each sprite of snake needs an x,y coordinate 
}s2[100];


//***NEW*** this is the fruit or food that the snake will eat 
struct Fruit
{
	int x, y;    // only need one sprite needed for one food item 
}pickup;

void updateScore() {
	std::cout << "---Score---" << std::endl;
	std::cout << "Player1: " << score1 << std::endl;
	std::cout << "Player2: " << score2 << std::endl;
}

void displayWinner() {
	if (score1 > score2) {
		std::cout << "Player 1 has won with " << score1 << " points!!!" << std::endl;
	}
	else if(score2 > score1) {
		std::cout << "Player 2 has won with " << score2 << " points!!!" << std::endl;
	}
	else {
		std::cout << "The Game Ended with a Tie..." << std::endl;
	}
}

//move snake head based on user input and body by incrementing  
//forward by iterating through arrays previous position 
void move() {

	//1st update body so everything updates in proper order 
	//move the body only!  s[0] = head will not be changed here 
	for (int i = snake_length; i > 0; i--)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	//Second Snake
	for (int i = snake_length2; i > 0; i--)
	{
		s2[i].x = s2[i - 1].x;
		s2[i].y = s2[i - 1].y;
	}

	//2nd update the head 
	//Head of snake, s[0] depends on direction user inputs  
	
	//if user presses up 
	if (direction == 0) {
		s[0].y -= 1;
	}
	if (direction2 == 0) {
		s2[0].y -= 1;
	}

	//if user presses down 
	if (direction == 1) {
		s[0].y += 1;
	}
	if (direction2 == 1) {
		s2[0].y += 1;
	}
		
	//if user presses left 
	if (direction == 2) {
		s[0].x -= 1;		
	}
	if (direction2 == 2) {
		s2[0].x -= 1;
	}

	//if user presses right 
	if (direction == 3) {
		s[0].x += 1;
	}
	if (direction2 == 3) {
		s2[0].x += 1;
	}


	//***NEW*** If Snake eats food it should grow 
	//check if snake head = food location 
	if (((s[0].x) == pickup.x) && ((s[0].y) == pickup.y))
	{
		ateFruit = true;
		score1++;
		updateScore();
		//increment snake 
		snake_length++;

		//Randomly place food somewhere else 
		pickup.x = rand() % num_horzBox;
		pickup.y = rand() % num_vertBox;
	}
	//Second Snake check for eaten fruit
	if (((s2[0].x) == pickup.x) && ((s2[0].y) == pickup.y))
	{
		ateFruit2 = true;
		score2++;
		updateScore();
		//increment snake 
		snake_length2++;

		//Randomly place food somewhere else 
		pickup.x = rand() % num_horzBox;
		pickup.y = rand() % num_vertBox;
	}

	//***NEW*** Boundary Checking snake as is hits screen end 
	//loop snake back on other side 

	//LEFT and RIGHT 
	if (s[0].x > num_horzBox)
		s[0].x = 0;
	if (s[0].x < 0)
		s[0].x = num_horzBox;

	//TOP and BOTTOM 
	if (s[0].y > num_vertBox)
		s[0].y = 0;
	if (s[0].y < 0)
		s[0].y = num_vertBox;

	//Second Snake check for boundary
	//LEFT and RIGHT 
	if (s2[0].x > num_horzBox)
		s2[0].x = 0;
	if (s2[0].x < 0)
		s2[0].x = num_horzBox;

	//TOP and BOTTOM 
	if (s2[0].y > num_vertBox)
		s2[0].y = 0;
	if (s2[0].y < 0)
		s2[0].y = num_vertBox;


	//***NEW*** Check if you eat body of snake 
	for (int i = 1; i < snake_length; i++)
	{
		//Cut Snake body from place eaten 
		if (s[0].x == s[i].x && s[0].y == s[i].y) {
			score1 = 0;
			updateScore();
			snake_length = i;
			ateItself = true;
		}
	}
	//Second Snake check for eaten body
	for (int i = 1; i < snake_length2; i++)
	{
		//Cut Snake body from place eaten 
		if (s2[0].x == s2[i].x && s2[0].y == s2[i].y) {
			score2 = 0;
			updateScore();
			snake_length2 = i;
			ateItself2 = true;
		}
	}
}


int main()
{
	//Setting pseudorandom time, TODO:discuss true random vs pseudorandom  
	srand(time(0));

	//Window that we can play the game in  
	sf::RenderWindow window(sf::VideoMode(w, h), "Snake Game (Score In Console)");

	updateScore();

	//Textures load an image into the GPU Memory 
	sf::Texture t1, t2, t3,t4;
	t1.loadFromFile("image/white.png");
	t2.loadFromFile("image/red.png");
	t3.loadFromFile("image/apple.png");
	t4.loadFromFile("image/scale.jpg");

	//Sprite has physical dimmensions that can be set in  
	//coordinate system, setPosition(x,y), and drawn on screen 
	sf::Sprite sprite1(t1);
	sf::Sprite sprite2(t2);
	sf::Sprite sprite3(t3);
	sf::Sprite sprite4(t4);

	//***NEW*** initially place food somewhere on screen 
	pickup.x = 10;
	pickup.y = 10;

	sf::Clock clock;
	float timer = 0.0f, delay = 0.1f;

	while (window.isOpen())
	{
		//Error in class I placed this before the while loop 
		//Should be placed in while loop as shown here to update 
		//timer  
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		//Allow us to check when a user does something 
		sf::Event e;

		//Check when the window is closed 
		while (window.pollEvent(e))
		{
			//If user presses x in the top right, Windows, top left, Mac,  close the window 
			if (e.type == sf::Event::Closed)
			{
				window.close();
				displayWinner();
			}
		}

		//Control for Snake by User 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction = 3;

		//Second Snake Controls
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction2 = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction2 = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction2 = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction2 = 3;

		if (timer > delay)
		{
			timer = 0; //reset timer 
			move();    //move Snake one sprite forward 

			//Checks to see if a fruit was eaten or you ate your self
			if (ateFruit) {
				delay -= 0.005f; //Decreases the delay so that timer will reach delay earlier so the sanke will move earlier making the game seem to go faster.
				ateFruit = false;//Reset the Indicator
			}
			else if(ateItself){
				delay = 0.1f; //Resets the delay back to what the game started as
				ateItself = false; //Resets the Indicator
			}
			if (ateFruit2) {
				delay -= 0.005f; //Decreases the delay so that timer will reach delay earlier so the sanke will move earlier making the game seem to go faster.
				ateFruit2 = false;//Reset the Indicator
			}
			else if (ateItself2) {
				delay = 0.1f; //Resets the delay back to what the game started as
				ateItself2 = false; //Resets the Indicator
			}

		}

		/*****************

		//Draw in window

		*****************/

		window.clear();    //clear the window so new frame can be drawn in 

		//NOTE: Order matters as we will draw over items listed first.  
		//Hence the background should be the first thing you will always do 

		//1st: Draw Background first 
		for (int i = 0; i < num_horzBox; i++)
		{
			for (int j = 0; j < num_vertBox; j++)
			{
				//Set position of sprite1 one at a time 
				sprite1.setPosition(i*size, j*size);

				//Draw sprite1 but, do not show it on screen.  
				window.draw(sprite1);
			}
		}

		//2nd: Then Draw snake otherwise background will be drawn over snake if order was reversed with background 
		for (int i = 0; i < snake_length; i++)
		{
			//position sprite2 one at a time 
			sprite2.setPosition(s[i].x*size, s[i].y*size);

			//Draw sprite2 one at a time by drawing over background 
			window.draw(sprite2);
		}
		for (int i = 0; i < snake_length2; i++)
		{
			//position sprite2 one at a time 
			sprite4.setPosition(s2[i].x*size, s2[i].y*size);

			//Draw sprite4 one at a time by drawing over background 
			window.draw(sprite4);
		}


		//***NEW*** 3rd: Draw Fruit 
		sprite3.setPosition(pickup.x*size, pickup.y*size);
		window.draw(sprite3);

		//Show everything we have drawn on the screen 
		window.display();
	}

	return 0;
}