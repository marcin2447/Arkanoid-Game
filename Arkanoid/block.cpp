#include "stdafx.h"
#include "block.h"


block::block(float t_X, float t_Y, float t_width, float t_height)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ t_width, t_height });
	shape.setFillColor(Color::Yellow);
	shape.setOrigin(t_width / 2.0f, t_height / 2.0f);

}

void block::draw(RenderTarget& target, RenderStates state) const
{

	target.draw(this->shape, state);


}


float block::left()
{

	return this->shape.getPosition().x - shape.getSize().x / 2.0f;



}

float block::right()
{

	return this->shape.getPosition().x + shape.getSize().x / 2.0f;


}

float block::top()
{

	return this->shape.getPosition().y - shape.getSize().x / 2.0f;


}

float block::bottom()
{

	return this->shape.getPosition().y + shape.getSize().x / 2.0f;


}

Vector2f block::getPosition()
{

	return shape.getPosition();


}

bool block::isDestroyed()
{

	return this->destroyed;


}
void block::destroy()
{
	this->destroyed = true;


}
Vector2f block:: getSize()
{

	return shape.getSize();

}

void block::update()
{



}