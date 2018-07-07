#pragma once
#include<SFML\Graphics.hpp>
using namespace sf;
class ball : public sf::Drawable
{
public:
	ball(float t_X, float t_Y);
	ball()= delete;
	~ball()= default;
	void update();

	Vector2f getPosition();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();


	float left();
	float right();
	float top();
	float bottom();

	
private:
	CircleShape shape;
	const float ballRadius{ 10.0f };
	const float ballVelocity{ 2.0f };
	Vector2f velocity{ ballVelocity,ballVelocity };

	void draw(RenderTarget &target, RenderStates state) const override;
};

