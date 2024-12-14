#pragma once
#include <vector>
class Brick {
	public:
		sf::RectangleShape shape;
		int hits;
	public:
		void Draw(sf::RenderWindow& window, std::vector<Brick>& bricks);
		void Initialize(std::vector<Brick>& bricks);
		void Update(std::vector<Brick>& bricks);
};