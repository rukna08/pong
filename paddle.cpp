#include "paddle.h"

Paddle::Paddle(const char* side) {
	width = 10;
	height = 50;
	x = 0;
	y = 0;

	if (side == "left") {
		x = 0 + width;
		y = 250 - height;
	}
	if (side == "right") {
		x = 500 - width*2;
		y = 250 - height;
	}

	transform = sf::RectangleShape(sf::Vector2f(width, height));
	transform.setFillColor(sf::Color::White);
	transform.setPosition(x, y);
}

void Paddle::update() {
	transform.setPosition(x, y);
}

void Paddle::draw(sf::RenderWindow& window) {
	window.draw(transform);
}

void Paddle::move(int dir) {
	if (dir == -1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			y -= 0.1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			y += 0.1;
		}
	}
	if (dir == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			y -= 0.1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			y += 0.1;
		}
	}
}

sf::RectangleShape Paddle::getTransform() {
	return transform;
}