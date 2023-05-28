#pragma once

#define WIDTH 1280
#define HEIGHT 720

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Managers
{
	class GraphicsManager
	{
	private:
		sf::RenderWindow* window;

		/* Singleton Design pattern */
		static GraphicsManager* instance;
		GraphicsManager();

		sf::Clock clock;
		static float deltaTime;

	public:
		~GraphicsManager();

		static GraphicsManager* getInstance();
		static void deleteInstance();

		bool isWindowOpen();
		void clear();
		void close();
		void display();
        void draw(sf::Sprite& body);
        void draw(sf::RectangleShape& body);
		sf::RenderWindow* getWindow();

		void updateDeltaTime();
		static const float getDeltaTime();

	};
}// namespace Managers
