#pragma once

#include <vector>
#include <glm/fwd.hpp>

#include "model.h"
#include "shader.h"
#include "texture.h"
#include "camera.h"

class QuadRenderer
{
public:
	QuadRenderer();
	void add_quad(const glm::vec3& position);
	void render_quads(const Camera& camera);
private:
	std::vector<glm::vec3> quads_;
	Model quad_model_;
	Shader basic_shader_;
	Texture basic_texture_;
};