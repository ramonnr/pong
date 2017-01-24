#include "Ball.h"
#include "Window.h"

Ball::Ball(float paddleW, float paddleH, float paddleX)
	:mPaddleWidth(paddleW), mPaddleHeight(paddleH), mPaddleX(paddleX) {
	srand(time(NULL));

	mXMax = Window::getWindow().getSize().x;
	mYMax = Window::getWindow().getSize().y;

	mHeadingX = rand() % 2 * mXMax;
	mHeadingY = rand() % 2 * mYMax;

	mBall.setRadius(mBallR);
	mBall.setFillColor(sf::Color::White);
	mBall.setPosition(mXMax / 2, mYMax / 2);
}


void Ball::update(float paddleY) {
	mPaddleY = paddleY;
}

void Ball::draw(void) {

	move();
	Window::getWindow().draw(mBall);

}

void Ball::move(void) {
	float xCurr = mBall.getPosition().x;
	float yCurr = mBall.getPosition().y;

	bool collision = false;
	if (xCurr < mPaddleX * 1.05 && xCurr > mPaddleX * 0.95) {
		if (yCurr > mPaddleY - 1 && yCurr < (mPaddleY + mPaddleHeight + 1))
			collision = true;
	}

	if (xCurr == 0 || collision)
		mHeadingX = mXMax;
	else if (xCurr + mBallR * 2 >= mXMax - 1)
		mHeadingX = 0;

	if (yCurr == 0 || collision)
		mHeadingY = mYMax;
	else if (yCurr + mBallR * 2 >= mYMax - 1)
		mHeadingY = 0;

	/*
	if( ((xCurr +mBallR*2) >= (mXMax -1)) || xCurr == 0 || collision)
	mHeadingX = rand() % 2 * mXMax;
	if( ((yCurr + mBallR*2) >= (mYMax -1)) || yCurr == 0 || collision)
	mHeadingY = rand() % 2 * mYMax;

	*/
	if (mHeadingX < xCurr) xCurr = -mSpeed;
	else xCurr = mSpeed;

	if (mHeadingY < yCurr) yCurr = -mSpeed;
	else yCurr = mSpeed;

	mBall.move(xCurr, yCurr);

}

