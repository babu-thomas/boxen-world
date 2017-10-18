#include <iostream>
#include <GL/glew.h>

#include "application.h"

Application::Application(const std::string & name)
	: context_(name)
{
}

void Application::run_loop()
{
	while (context_.window.isOpen())
	{
		print_opengl_errors();
		handle_events();
	}
}

void Application::handle_events()
{
	sf::Event event;
	while (context_.window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			context_.window.close();
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				context_.window.close();
				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
	}
}

void Application::print_opengl_errors()
{
	GLenum error = glGetError();
	while (error != GL_NO_ERROR)
	{
		std::cerr << "OpenGL Error: " << error << std::endl;
		error = glGetError();
	}
}
