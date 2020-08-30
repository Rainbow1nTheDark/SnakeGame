#include "iostream"
#include <conio.h>
#include "Class.h"

snake::operator bool() const
{
	return this->gameOver;
}

snake::snake()
{
	nTail = 0;
	gameOver = false;
	dir = eDirection::STOP;
	x = width / 2;
	y = height / 2;
	// randomly place a fruit 
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}


void snake::draw()
{
	// clear the screen
	system("cls");
	//printing the header of the map
	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	//printing the body of the map
	for (int i = 0; i < height; i++)
	{


		for (int j = 0; j < width; j++)
		{
			//the border
			if (j == 0) {
				std::cout << "#";
			}
			//head of the snake
			if (i == y && j == x)
			{
				std::cout << "S";
			}
			//displaying a fruit
			else if (i == fruitY && j == fruitX)
			{
				std::cout << "F";
			}
			else
			{
				bool print = false;
				for (int q = 0; q < nTail; q++)
				{

					if (tailX[q] == j && tailY[q] == i)
					{
						std::cout << "o";
						print = true;
					}

				}
				
				//the field of the game

			}
			if (j == width - 1) {
				std::cout << "#";
			}


		}
		std::cout << std::endl;
	}
	//printing the pooter of the map
	for (int i = 0; i < width + 2; i++) {
		std::cout << "#";
	}
	//printing the score
	std::cout << std::endl << "score: " << score;
}

void snake::logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	// the first part of the body always follows the head
	tailX[0] = x;
	tailY[0] = y;
	//shift the data to the left (movement of the body)
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case snake::eDirection::STOP:
		break;
	case snake::eDirection::LEFT:

		x--;

		break;
	case snake::eDirection::RIGHT:
		x++;
		break;
	case snake::eDirection::UP:
		y--;
		break;
	case snake::eDirection::DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width || x < 0 || y > height || y < 0)
	{
		gameOver = true;
	}
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}
	// if the snake eats the fruit, spawn the new one and increase the score
	if (x == fruitX && y == fruitY)
	{
		fruitX = rand() % width;
		fruitY = rand() % height;
		score += 10;
		nTail++;
	}
}

void snake::input()
{
	//if a key is pressed (returns a boolian)
	if (_kbhit())
	{
		//_getch - which key is pressed ( returns the pressed key)
		switch (_getch())
		{
		case 'a':
			//if statement to prevent hit the snake to itself
			if (dir != eDirection::RIGHT || nTail < 2)
			{
				dir = eDirection::LEFT;
			}
			break;
		case 'd':
			//if statement to prevent hit the snake to itself
			if (dir != eDirection::LEFT || nTail < 2)
			{
				dir = eDirection::RIGHT;
			}
			break;
		case 'w':
			//if statement to prevent hit the snake to itself
			if (dir != eDirection::DOWN || nTail < 2)
			{
				dir = eDirection::UP;
			}
			break;
		case 's':
			//if statement to prevent hit the snake to itself
			if (dir != eDirection::UP || nTail < 2)
			{
				dir = eDirection::DOWN;
			}
			break;
			//an option to exit the game
		case 'x':
			gameOver = true;
		default:
			break;
		}
	}
}
