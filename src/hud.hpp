#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"
class Hud {
public:
	static sf::Font font;
	static sf::Text score_text;

	static bool InitializeHud();
	static void UpdateHud(Player& pl);
	static void DrawHud(sf::RenderWindow& window);
};