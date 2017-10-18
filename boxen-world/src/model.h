#pragma once

#include <vector>
#include <GL/glew.h>

#include "util/non_copyable.h"

class Model : public NonCopyable
{
public:
	Model() = default;
	Model(const std::vector<GLfloat>& vertex_positions, const std::vector<GLfloat>& texture_coords,
		const std::vector<GLuint>& indices);
	~Model();

	void add_data(const std::vector<GLfloat>& vertex_positions,
		const std::vector<GLfloat>& texture_coords, const std::vector<GLuint>& indices);
	void delete_data();
	void add_vbo(int dimensions, const std::vector<GLfloat>& data);
	void bind_vao() const;
	int get_indices_count() const;

private:
	void add_ebo(const std::vector<GLuint>& indices);

	GLuint vao_ = 0;
	int vbo_count_ = 0;
	int indices_count_ = 0;
	std::vector<GLuint> buffers_;

};