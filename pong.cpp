#include "pong.h"

void pong::run() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "PONG");
	Ball b;
	Paddle pLeft("left");
	Paddle pRight("right");

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		pLeft.draw(window);
		pLeft.move(-1);
		pLeft.update();

		pRight.draw(window);
		pRight.move(1);
		pRight.update();

		b.draw(window);
		b.move(0.05, 0.009);
		b.bounceEdges();
		b.update();

		if (b.collides(pLeft) || b.collides(pRight)) {
			b.reverseDirection('x');
		}

		window.display();
	}
}