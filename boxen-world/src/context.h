#pragma once

#include <string>
#include <SFML/Window.hpp>

struct Context
{
	Context(const std::string& name);
	sf::Window window;
};