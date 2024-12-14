#include "hud.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <string>

sf::Font Hud::font;
sf::Text Hud::score_text;

void Hud::DrawHud(sf::RenderWindow& window) {
	window.draw(score_text);
}

bool Hud::InitializeHud() {
	if (!font.loadFromFile("C:/Users/jasko/Desktop/brick_breaker/resources/fonts/PlayfairDisplay.ttf")) {
		return false;
	}
	score_text.setFillColor(sf::Color::White);
	score_text.setPosition(0,sf::VideoMode().getDesktopMode().height / 3);
	score_text.setCharacterSize(30.f);
	score_text.setString("Score = 0");
	score_text.setFont(font);
	return true;
}

void Hud::UpdateHud(Player& pl) {
	
	std::string score = "Score = " + std::to_string(pl.score);
	score_text.setString(score);
}