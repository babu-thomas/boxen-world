#include <iostream>
#include <stdexcept>
#include <GL/glew.h>

#include "context.h"

Context::Context(const std::string & name)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;
	settings.majorVersion = 3;
	settings.minorVersion = 3;
	settings.depthBits = 24;
	settings.stencilBits = 8;

	window.create(sf::VideoMode(1280, 720), name, sf::Style::Close, settings);
	window.setFramerateLimit(60);
	window.setActive(true);

	if (glewInit() != GLEW_OK)
	{
		throw std::runtime_error("Failed to initialize GLEW!");
	}

	glViewport(0, 0, 1280, 720);
}