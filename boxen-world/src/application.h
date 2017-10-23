#pragma once

#include <string>
#include "context.h"
#include "camera.h"
#include "quad_renderer.h"

class Application
{
public:
	Application(const std::string& name);
	void run_loop();
private:
	void handle_events();
	void print_opengl_errors() const;
	Context context_;
	Camera camera_;
	QuadRenderer renderer_;
};