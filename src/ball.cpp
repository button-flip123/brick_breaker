#include <vector>
#include "ball.hpp"
#include "player.hpp"
#include "brick.hpp"

void Ball::Draw(sf::RenderWindow& window) {
	window.draw(shape);
}

void Ball::Initialize(Player& pl) {
	velocity.x = velocity.y = 200.f;
	started = false;
	shape.setFillColor(sf::Color::Red);
	shape.setRadius(7.0f);
	shape.setOutlineColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(pl.shape.getPosition().x + 1.5f, pl.shape.getPosition().y - 10.0f));
}

void Ball::Update(Player& pl, float deltaTimeSeconds,std::vector<Brick>& bricks) {

	shape.move(velocity.x * deltaTimeSeconds, velocity.y * deltaTimeSeconds);

	//left
	if (shape.getPosition().x < 0.f) {
		shape.setPosition(0, shape.getPosition().y);
		velocity.x = velocity.x * (-1);
	}

	//right
	if (shape.getPosition().x + shape.getGlobalBounds().width > sf::VideoMode::getDesktopMode().width) {
		shape.setPosition(sf::VideoMode::getDesktopMode().width - shape.getGlobalBounds().width, shape.getPosition().y);
		velocity.x = velocity.x * (-1);
	}

	//top
	if (shape.getPosition().y < 0.f) {
		shape.setPosition(shape.getPosition().x, 0);
		velocity.y = velocity.y * (-1);
	}

	//bottom
	if (shape.getPosition().y + shape.getGlobalBounds().height > sf::VideoMode::getDesktopMode().height) {
		shape.setPosition(shape.getPosition().x, sf::VideoMode::getDesktopMode().height - shape.getGlobalBounds().height);
		velocity.y = velocity.y * (-1);
	}
	
	if (shape.getGlobalBounds().intersects(pl.shape.getGlobalBounds())) {
		velocity.y = velocity.y * (-1);
		float paddleCenter = pl.shape.getPosition().x + pl.shape.getSize().x / 2;
		float ballCenter = shape.getPosition().x + shape.getRadius();
		velocity.x += (ballCenter - paddleCenter) * 0.5f;
		//shape.move(0, -shape.getRadius()*deltaTimeSeconds);
		shape.move(velocity.x * deltaTimeSeconds, velocity.y * deltaTimeSeconds/*15 * (-1)*/);
	}
	
	for (int i = 0; i < bricks.size(); i++) {
		if (shape.getGlobalBounds().intersects(bricks[i].shape.getGlobalBounds())) {
			velocity.y *= -1;
			bricks[i].hits--;
			if (bricks[i].hits == 0) {
				bricks.erase(bricks.begin() + i);
				pl.score++;
			}
		}
	}
	if (bricks.empty()) {
		Initialize(pl);
	}
}