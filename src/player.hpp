#pragma once
#include <SFML/Graphics.hpp>
class Player {
	private:
		float speed;
	public:
		sf::RectangleShape shape;
		int score;
	public:
		void Draw(sf::RenderWindow& window);
		void Update(float deltaTimeSeconds);
		void Initialize();
};