#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "brick.hpp"
#include "ball.hpp"
#include "hud.hpp"
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "SFML works!", sf::Style::Fullscreen, settings);
	window.setFramerateLimit(60);
	sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
	window.setView(view);
	

	Player pl;
	Brick br;
	Ball bl;
	pl.Initialize();
	if (!Hud::InitializeHud()) {
		std::cout << "Failed to initialize hud\n";
		return 1;
	}
	bl.Initialize(pl);
	std::vector<Brick> bricks;
	br.Initialize(bricks);
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::Resized) {
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.scancode == sf::Keyboard::Scan::Escape) {
					window.close();
				}
			}
		}
		sf::Time deltaTime = clock.restart();
		float deltaTimeSeconds = deltaTime.asSeconds();

		deltaTimeSeconds = std::min(deltaTimeSeconds, 1.f);
		deltaTimeSeconds = std::max(deltaTimeSeconds, 0.f);

		Hud::UpdateHud(pl);
		pl.Update(deltaTimeSeconds);
		bl.Update(pl, deltaTimeSeconds, bricks);
		br.Update(bricks);

		window.clear(sf::Color::Black);
		pl.Draw(window);
		br.Draw(window, bricks);
		bl.Draw(window);
		Hud::DrawHud(window);
		window.display();
	}
	return 0;
}