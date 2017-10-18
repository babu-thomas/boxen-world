#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/fwd.hpp>

class Shader
{
public:
	Shader(const std::string& vert_path, const std::string& frag_path);
	~Shader();
	void enable() const;
	void disable() const;

	void set_uniform1f(const GLchar* name, float value) const;
	void set_uniform1i(const GLchar* name, int value) const;
	void set_uniform2f(const GLchar* name, const glm::vec2& value) const;
	void set_uniform3f(const GLchar* name, const glm::vec3& value) const;
	void set_uniform4f(const GLchar* name, const glm::vec4& value) const;
	void set_uniform_mat4(const GLchar* name, const glm::mat4& value) const;

	GLint get_uniform_location(const GLchar *name) const;

private:
	GLuint load() const;
	GLuint create_vertex_shader() const;
	GLuint create_fragment_shader() const;
	void compile_shader(GLuint shader, const std::string& error_msg) const;
	GLuint create_shader_program(GLuint vertex_shader, GLuint fragment_shader) const;

	bool check_shader_error(GLuint shader, GLuint flag, const std::string& error_msg) const;
	bool check_shader_program_error(GLuint program, GLuint flag,
		const std::string& error_msg) const;
	GLuint program_id_;
	std::string vert_path_;
	std::string frag_path_;
};