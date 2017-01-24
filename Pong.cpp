#include <SFML/Graphics.hpp>

#include"Window.h"
#include "Paddle.h"
#include "Ball.h"
int main()
{
	
	
	Paddle paddle;
	Ball ball(paddle.getWidth(),paddle.getHeight(),paddle.getX());
	sf::Clock clock;
	
	bool pressed = false;
	while (Window::getWindow().isOpen())
	{
		sf::Event event;
		while (Window::getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window::getWindow().close();
			else if (event.KeyPressed) {
				paddle.update(event.key, true);
			}
			else if (event.KeyReleased) {
				paddle.update(event.key, false);
			}
		}
		ball.update(paddle.getY());
		if (clock.getElapsedTime().asSeconds() >= 1 / 60.f) {
			clock.restart();
			Window::getWindow().clear();
			ball.draw();
			paddle.draw();
			Window::getWindow().display();
		}
	}

	return 0;
}