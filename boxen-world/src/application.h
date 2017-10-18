#pragma once

#include <string>
#include "context.h"

class Application
{
public:
	Application(const std::string& name);
	void run_loop();
private:
	void handle_events();
	Context context_;
};