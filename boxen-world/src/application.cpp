#include <iostream>
#include <GL/glew.h>

#include "application.h"

Application::Application(const std::string & name)
	: context_(name)
{
}

void Application::run_loop()
{
	renderer_.add_quad({ 0, 0, 0 });
	while (context_.window.isOpen())
	{
		print_opengl_errors();
		handle_events();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		camera_.update();
		renderer_.render_quads(camera_);
		context_.window.display();
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

void Application::print_opengl_errors() const
{
	GLenum error = glGetError();
	while (error != GL_NO_ERROR)
	{
		std::cerr << "OpenGL Error: " << error << std::endl;
		error = glGetError();
	}
}
