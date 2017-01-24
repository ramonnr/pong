#pragma once

#include <SFML\Graphics.hpp>
class Ball {
public:

	Ball(float w, float h, float x);
	void draw(void);
	void update(float paddleY);

private:
	void move(void);
	sf::CircleShape mBall;
	float mHeadingX;
	float mHeadingY;
	float mXMax;
	float mYMax;
	const float mSpeed = 10;
	const float mBallR = 20;
	const float mPaddleHeight;
	const float mPaddleWidth;
	float mPaddleY;
	const float mPaddleX;
};