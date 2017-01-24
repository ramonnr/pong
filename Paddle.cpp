#include "Paddle.h"
#include "Window.h"
Paddle::Paddle() {
	mMaxY = Window::getWindow().getSize().y - mHeight;
	mPaddle.setSize(sf::Vector2f(mWidth, mHeight));
	mPaddle.setFillColor(sf::Color::White);
	mPaddle.setPosition(mWidth, mMaxY / 2);
	mPressed = false;
	mDir = stopped;

}

void Paddle::draw() {
	move();
	Window::getWindow().draw(mPaddle);
}

void Paddle::update(sf::Event::KeyEvent& event, bool pressed) {
	mPressed = pressed;
	if (pressed) {
		switch (event.code) {
		case sf::Keyboard::Up:
			mDir = up;
			break;

		case sf::Keyboard::Down:
			mDir = down;
			break;
		}
	}
	else
		mDir = stopped;
}

void Paddle::move() {
	float y = mPaddle.getPosition().y;

	

	if (mPressed) {
		if (mDir == up && y > 0)
			mPaddle.move(0, -mSpeed);
		else if(mDir == down && y < mMaxY)
			mPaddle.move(0, mSpeed);
	}
	
}