#include "ball.h"

Ball::Ball() {
	xdirection = 1;
	ydirection = 1;
	radius = 5;
	x = 250-radius;
	y = 250-radius;
	transform.setRadius(radius);
	transform.setPosition(x, y);
	transform.setFillColor(sf::Color::White);
}

void Ball::draw(sf::RenderWindow& window) {
	window.draw(transform);
}

void Ball::move(float x, float y) {
	this->x += x * xdirection;
	this->y += y * ydirection;
}

void Ball::reset() {
	x = 250 - radius;
	y = 250 - radius;
}


void Ball::update() {
	transform.setPosition(x, y);
	if ((x+radius*2) >= 500 || (x-radius) <= 0) {
		reset();
	}
}

bool Ball::collides(Paddle p) {
	if (transform.getGlobalBounds().intersects(p.getTransform().getGlobalBounds())) {
		return true;
		std::cout << "collision!\n";
	}
	else {
		return false;
	}
}

void Ball::reverseDirection(const char coordinate) {
	if (coordinate == 'x') {
		xdirection *= -1;
	}
	if (coordinate == 'y') {
		ydirection *= -1;
	}
}

void Ball::bounceEdges() {
	if ((y <= 0) || (y + radius*2 >= 500)) {
		reverseDirection('y');
	}
}