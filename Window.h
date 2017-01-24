#pragma once

#include <SFML\Graphics.hpp>
class Window {
public:
	static sf::RenderWindow& getWindow(void) {
		static sf::RenderWindow window(sf::VideoMode(1000, 800), "Pong");
		return window;
	}
};