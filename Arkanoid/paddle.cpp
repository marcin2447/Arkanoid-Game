#include "stdafx.h"
#include "paddle.h"


paddle::paddle(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({this->paddlewidth, this->paddleheight });
	shape.setFillColor(Color::Blue);
	shape.setOrigin(paddlewidth / 2.0f, paddleheight / 2.0f);





}

void paddle::draw(RenderTarget& target, RenderStates state) const
{

	target.draw(this->shape, state);


}

void paddle::update()
{


	this->shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
	{
		velocity.x = -paddleVelocity;


	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800)
	{
		velocity.x = paddleVelocity;


	}
	else
	{
		velocity.x = 0;



	}



}


float paddle::left()
{

	return this->shape.getPosition().x - shape.getSize().x/2.0f;



}

float paddle::right()
{

	return this->shape.getPosition().x + shape.getSize().x/2.0f;


}

float paddle::top()
{

	return this->shape.getPosition().y - shape.getSize().x / 2.0f;


}

float paddle::bottom()
{

	return this->shape.getPosition().y + shape.getSize().x / 2.0f;


}

Vector2f paddle::getPosition()
{

	return shape.getPosition();


}