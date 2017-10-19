#include <stdexcept>
#include <SFML/Graphics.hpp>

#include "texture.h"

Texture::Texture(const std::string &filename)
{
	load_from_file(filename);
}

Texture::~Texture()
{
	glDeleteTextures(1, &texture_id_);
}

void Texture::load_from_file(const std::string &filename)
{
	sf::Image img;
	if (!img.loadFromFile(filename))
	{
		throw std::runtime_error("Failed to load texture image: " + filename);
	}

	glGenTextures(1, &texture_id_);
	glBindTexture(GL_TEXTURE_2D, texture_id_);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.getSize().x, img.getSize().y, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, img.getPixelsPtr());

	// Texture wrapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// Texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, texture_id_);
}
