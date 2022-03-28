#include <SFML/Graphics.hpp>
#include <thread>
#include "World.h"
#include <iostream>

//#ifdef _DEBUG
//#pragma comment(lib, "sfml-window-d.lib")
//#pragma comment(lib, "sfml-system-d.lib")
//#pragma comment(lib, "sfml-graphics-d.lib")
//#else
//#pragma comment(lib, "sfml-window.lib")
//#pragma comment(lib, "sfml-system.lib")
//#pragma comment(lib, "sfml-graphics.lib")
//#endif

int main() {

	int windowHeights = 1000;
	int windowWidth = 1600;
	sf::Event sfevent;
	sf::RenderWindow* gameWindow = nullptr;
	sf::Clock clock;
	sf::Time timePerFrame = sf::seconds(1 / 60.f);
	sf::Time elapsedTimeSinceLastUpdate;
	double zoomLevel = 1;
	float panSpeed = 2;
	float jogFactor = 3;

	World testWorld;
	testWorld.loadWorld("../worldmap/tiny_world.ybin");

	gameWindow = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeights), "Game");


	auto moveView = [&](float dirX, float dirY, float speed) {
		sf::View current = gameWindow->getView();
		current.move(dirX * speed, dirY * speed);
		gameWindow->setView(current);
	};

	elapsedTimeSinceLastUpdate = sf::Time::Zero;

	while (gameWindow->isOpen())
	{
		elapsedTimeSinceLastUpdate += clock.restart();


		while (elapsedTimeSinceLastUpdate > timePerFrame)
		{
			elapsedTimeSinceLastUpdate -= timePerFrame;
		
			if (gameWindow->pollEvent(sfevent)) {
				if (sfevent.type == sf::Event::Closed) {
					gameWindow->close();
				}
				if (sfevent.type == sf::Event::KeyPressed) {
					float speed = panSpeed;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
						speed *= jogFactor;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						moveView(-1.f * zoomLevel * speed, 0, 10.f);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
						moveView(0.f, 1.f * zoomLevel * speed, 10.f);

					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						moveView(1.f * zoomLevel * speed, 0, 10.f);

					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						moveView(0.f, -1.f * zoomLevel * speed, 10.f);

					}
				}
				if (sfevent.type == sf::Event::MouseWheelScrolled) {
					sf::View current = gameWindow->getView();
					zoomLevel += (sfevent.mouseWheelScroll.delta / 50.f);
					current.zoom(1 + (sfevent.mouseWheelScroll.delta / 50.f));
					gameWindow->setView(current);

				}
			}


			gameWindow->clear();

			testWorld.draw(gameWindow);

			gameWindow->display();
		}
	}
	return 0;
}