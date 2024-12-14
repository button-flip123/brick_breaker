#include <SFML/Graphics.hpp>
#include "brick.hpp"
#include <random>

sf::Color hitColor(Brick& brick) {
	switch (brick.hits) 
	{
		case 1: {
			return sf::Color::White;
		}
		case 2: {
			return sf::Color::Red;
		}
		case 3: {
			return sf::Color::Cyan;
		}
		case 4: {
			return sf::Color::Yellow;
		}
		case 5: {
			return sf::Color::Green;
		}
	}
	return sf::Color::White;
}

void Brick::Draw(sf::RenderWindow& window, std::vector<Brick>& bricks) {
	for (int i = 0; i < bricks.size(); i++) {
		window.draw(bricks[i].shape);
	}
}

void Brick::Initialize(std::vector<Brick>& bricks) {
	for (int i = 2; i < 13; i++)
	{
		for (int j = 1; j < 24; j++)
		{
			std::random_device rd;
			std::mt19937 gen(rd()); 
			std::uniform_int_distribution<> distr(1, 5); 
			Brick brick;
			brick.shape.setFillColor(hitColor(brick));
			brick.shape.setSize(sf::Vector2f(53, 14));
			brick.hits = distr(gen);
			brick.shape.setPosition(sf::Vector2f(((float)j-0.2) * (brick.shape.getSize().x + 5), ((float)i+0.0) * (brick.shape.getSize().y + 5)));
			brick.shape.setOrigin(sf::Vector2f(brick.shape.getSize().x / 2, brick.shape.getSize().y / 2));
			bricks.push_back(brick);
		}
	}
}

void Brick::Update(std::vector<Brick>& bricks) {
	if (bricks.empty()) {
		Initialize(bricks);
	}
}