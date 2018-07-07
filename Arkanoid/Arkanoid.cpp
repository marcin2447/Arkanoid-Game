// Arkanoid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include "ball.h"
#include "paddle.h"
#include "block.h"



using namespace sf;
using namespace std;


template <class T1, class T2> bool isIntersecting(T1&A, T2&B)
{

	return A.right() >= B.left() && A.left() <= B.right()
		&& A.bottom() >= B.top() && A.top() <= B.bottom();

}

bool colisiontest(paddle& paddle, ball&ball )
{

	if (!isIntersecting(paddle, ball)) return false;

	ball.moveUp();

	if (ball.getPosition().x < paddle.getPosition().x)
	{
		ball.moveLeft();

	}
	else if (ball.getPosition().x > paddle.getPosition().x)
	{

		ball.moveRight();


	}


}

bool colisiontest(block& block, ball&ball)
{
	if (!isIntersecting(block, ball)) return false;

	block.destroy();

	float overlapLeft{ ball.right() - block.left() };
	float overlapRight{ block.right() - ball.left() };

	float overlapTop{ ball.bottom() - block.top() };
	float overlapbottom{ block.bottom() - ball.top() };


	bool ballFromLeft{ abs(overlapLeft) < abs(overlapRight) };
	bool ballFromTop{ abs(overlapTop) < abs(overlapbottom) };

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapbottom };

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		ballFromLeft ? ball.moveLeft() : ball.moveRight();

	}
	else

	{

		ballFromTop ? ball.moveUp() : ball.moveDown();


	}

}



int main()
{
	ball ball(400, 300);
	paddle paddle(400, 550);
	RenderWindow window{ VideoMode{ 800,600 },"arcanoid" };
	window.setFramerateLimit(100);
	Event event;
	unsigned blocksX{ 10 }, blocksY{ 4 }, blockwidth{ 60 }, blockheight{ 20 };
	vector<block> blocks;

	for ( int i = 0; i < blocksY; i++)
	{
		for (int j = 0; j < blocksX; j++)
			blocks.emplace_back((j+1)*(blockwidth+10), (i+2)*(blockheight+5), blockwidth, blockheight);
	}

	
	while (true)
	{

		window.clear(Color::Black);
		window.pollEvent(event);

		if(event.type==Event::Closed)
		{
			window.close();
			break;
		}


		ball.update();
		paddle.update();
		colisiontest(paddle, ball);

		for (auto&block : blocks) if (colisiontest(block, ball)) break;
		auto iterator = remove_if(begin(blocks), end(blocks), [](block&block) {return block.isDestroyed(); });
		blocks.erase(iterator, end(blocks));


		

		window.draw(ball);
		window.draw(paddle);

		for (auto&block:blocks)
		{
			window.draw(block);
		}



		window.display();
	}



	return 0;
}

