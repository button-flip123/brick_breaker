#include "player.hpp"

void Player::Draw(sf::RenderWindow& window) {
	window.draw(shape);
}

void Player::Initialize() {
	score = 0;
	speed = 350.f;
	shape.setPosition(684,384);
	shape.setSize(sf::Vector2f(76.0f,16.0f));
	shape.setFillColor(sf::Color::White);
}

void Player::Update(float deltaTimeSeconds) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		shape.move(speed * deltaTimeSeconds,0.f);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		shape.move(-speed * deltaTimeSeconds,0.f);
	}

	if (shape.getPosition().x < 0.f) {
		shape.setPosition(0, shape.getPosition().y);
	}

	if (shape.getPosition().x + shape.getGlobalBounds().width > sf::VideoMode::getDesktopMode().width) {
		shape.setPosition(sf::VideoMode::getDesktopMode().width - shape.getGlobalBounds().width,shape.getPosition().y);
	}	
}