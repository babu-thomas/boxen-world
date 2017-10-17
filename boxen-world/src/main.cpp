#include <iostream>
#include <GL/glew.h>
#include <SFML/Window.hpp>

int main()
{
	sf::Window window(sf::VideoMode(800, 600), "Boxen World");
	window.setVerticalSyncEnabled(true);

	window.setActive(true);

	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW!" << std::endl;
		return 1;
	}

	bool running = true;
	while (running)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				running = false;
			}
			else if (event.type == sf::Event::Resized)
			{
				glViewport(0, 0, event.size.width, event.size.height);
			}
		}

		glClearColor(0.3f, 0.0f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		window.display();
	}

	return 0;
}