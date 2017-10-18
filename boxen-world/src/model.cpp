#include "model.h"

Model::Model(const std::vector<GLfloat>& vertex_positions,
	const std::vector<GLfloat>& texture_coords, const std::vector<GLuint>& indices)
{
	add_data(vertex_positions, texture_coords, indices);
}

Model::~Model()
{
	delete_data();
}

void Model::add_data(const std::vector<GLfloat>& vertex_positions,
	const std::vector<GLfloat>& texture_coords, const std::vector<GLuint>& indices)
{
	if (vao_ != 0)
	{
		delete_data();
	}

	indices_count_ = indices.size();
	glGenVertexArrays(1, &vao_);
	glBindVertexArray(vao_);

	add_vbo(3, vertex_positions);
	add_vbo(2, texture_coords);
	add_ebo(indices);
}

void Model::delete_data()
{
	glDeleteVertexArrays(1, &vao_);
	glDeleteBuffers(buffers_.size(), buffers_.data());
	buffers_.clear();
	vbo_count_ = 0;
	vao_ = 0;
	indices_count_ = 0;
}

void Model::add_vbo(int dimensions, const std::vector<GLfloat>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(vbo_count_, dimensions, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vbo_count_); ++vbo_count_;
	buffers_.push_back(vbo);
}

void Model::bind_vao() const
{
	glBindVertexArray(vao_);
}

int Model::get_indices_count() const
{
	return indices_count_;
}

void Model::add_ebo(const std::vector<GLuint>& indices)
{
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(),
		GL_STATIC_DRAW);
}
