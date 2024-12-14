#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "brick.hpp"

class Ball{
	private:
		sf::CircleShape shape;
		sf::Vector2f velocity;
		bool started;
	public:
		void Initialize(Player& pl);
		void Draw(sf::RenderWindow& window);
		void Update(Player& pl, float deltaTimeSeconds, std::vector<Brick>& bricks);
};