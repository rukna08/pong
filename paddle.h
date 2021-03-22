#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Paddle {
	float x, y;
	int width, height;
	sf::RectangleShape transform;

public:
	Paddle(const char* side);
	void update();
	void draw(sf::RenderWindow& window);
	void move(int dir);
	sf::RectangleShape getTransform();
};