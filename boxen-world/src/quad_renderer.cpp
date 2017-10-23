#include <iostream>
#include <glm/glm.hpp>
#include <GL/glew.h>

#include "quad_renderer.h"

QuadRenderer::QuadRenderer() :
	basic_shader_(".\\src\\shaders\\basic.vert", ".\\src\\shaders\\basic.frag")
{
	quad_model_.add_data(
	{
		-0.5,  0.5, 0,
		 0.5,  0.5, 0,
		 0.5, -0.5, 0,
		-0.5, -0.5, 0
	},
	{
		0, 1,
		1, 1,
		1, 0,
		0, 0
	},
	{
		0, 1, 2,
		2, 3, 0
	}
	);

	basic_texture_.load_from_file("data\\grass.png");
	
}

void QuadRenderer::add_quad(const glm::vec3& position)
{
	quads_.push_back(position);
}

void QuadRenderer::render_quads(const Camera& camera)
{
	basic_shader_.enable();
	quad_model_.bind_vao();
	basic_texture_.bind();

	basic_shader_.set_uniform_mat4("proj_view_mat", camera.get_proj_view_mat());
	basic_shader_.set_uniform_mat4("model_mat", glm::mat4());

	for (auto& quad : quads_)
	{
		glDrawElements(GL_TRIANGLES, quad_model_.get_indices_count(), GL_UNSIGNED_INT, nullptr);
	}
}
