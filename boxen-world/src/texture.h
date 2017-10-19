#pragma once

#include <string>
#include <GL/glew.h>

class Texture
{
public:
	Texture() = default;
	Texture(const std::string &filename);
	~Texture();
	void load_from_file(const std::string &filename);
	void bind() const;

private:
	GLuint texture_id_;
};