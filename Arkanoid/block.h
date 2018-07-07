#pragma once
#include<SFML\Graphics.hpp>
using namespace sf;

class block: public Drawable
{
public:
	block(float t_X, float t_Y, float t_width, float t_height);
	block() = delete;
	
	~block()=default;

	void update();
	Vector2f getPosition();


	float top();
	float right();
	float left();
	float bottom();

	bool isDestroyed();
	void destroy();
	Vector2f getSize();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	RectangleShape shape;
	bool destroyed{ false };


};

