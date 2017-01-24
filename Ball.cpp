#include "Ball.h"
#include "Window.h"

Ball::Ball(float paddleW, float paddleH, float paddleX) 
	:mPaddleWidth(paddleW), mPaddleHeight(paddleH), mPaddleX(paddleX){
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
	if (xCurr == mPaddleX) {
		if (yCurr > mPaddleY && yCurr < mPaddleY + mPaddleHeight)
			collision = true;
	}
	

	if(xCurr +mBallR*2 >= mXMax -1 || xCurr == 0 || collision)
		mHeadingX = rand() % 2 * mXMax;
	if(yCurr + mBallR*2 >= mYMax -1 || yCurr == 0 || collision)
		mHeadingY = rand() % 2 * mYMax;

	if (mHeadingX < xCurr) xCurr = -mSpeed;
	else xCurr = mSpeed;

	if (mHeadingY < yCurr) yCurr = -mSpeed;
	else yCurr = mSpeed;

	mBall.move(xCurr, yCurr);
	
}

