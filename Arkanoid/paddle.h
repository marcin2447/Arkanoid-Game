#pragma once
#include<SFML\Graphics.hpp>

using namespace sf;
using namespace std;
class paddle: public Drawable
{
public:
	paddle(float t_X, float t_Y);
	paddle() = delete;
	~paddle()=default;

	void update();
	float left();
	float right();
	float top();
	float bottom();

	Vector2f getPosition();


private:
	void draw(RenderTarget &target, RenderStates state) const override;
	RectangleShape shape;
	const float paddlewidth{ 80.0f };
	const float paddleheight{ 20.0f };
	const float paddleVelocity{ 6.0f };
	Vector2f velocity{ paddleVelocity,0.f };



};

