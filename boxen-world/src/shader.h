#pragma once

#include <string>
#include <GL/glew.h>

class Shader
{
public:
	Shader(const std::string& vert_path, const std::string& frag_path);
	~Shader();
	void enable() const;
	void disable() const;

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