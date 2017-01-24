#pragma once

#include <SFML\Graphics.hpp>
#include "Window.h"

typedef enum direction { up, down, stopped};

class Paddle {
public:
	Paddle();
	void draw();
	void update(sf::Event::KeyEvent&,bool);
	float getY(void) { return mPaddle.getPosition().y; }
	float getX(void) { return mPaddle.getPosition().x; }
	float getHeight(void) { return mPaddle.getSize().y; }
	float getWidth(void) { return mPaddle.getSize().x; }

private:
	void move(void);
	const float mHeight = 160;
	const float mWidth = 20;
	sf::RectangleShape mPaddle;
	float mMaxY;
	float mSpeed = 20.f;
	direction mDir;
	bool mPressed;
};