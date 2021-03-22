#pragma once

#include "SFML/Graphics.hpp"
#include "paddle.h"

class Ball {
	float x, y;
	int radius;
	int xdirection, ydirection;
	sf::CircleShape transform;

	void reset();
public:
	Ball();
	void draw(sf::RenderWindow& window);
	void move(float x, float y);
	void update();
	bool collides(Paddle p);
	void reverseDirection(const char coordinate);
	void bounceEdges();
};