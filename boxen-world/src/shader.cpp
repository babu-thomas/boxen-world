#include <iostream>
#include <stdexcept>

#include "util/fileutil.h"
#include "shader.h"

const int ERROR_MSG_LEN = 1024;

Shader::Shader(const std::string& vert_path, const std::string& frag_path)
	: vert_path_(vert_path), frag_path_(frag_path)
{
	program_id_ = load();
}

Shader::~Shader()
{
	glDeleteProgram(program_id_);
}

void Shader::enable() const
{
	glUseProgram(program_id_);
}

void Shader::disable() const
{
	glUseProgram(0);
}

GLuint Shader::load() const
{
	GLuint vertex = create_vertex_shader();
	compile_shader(vertex, "Failed to compile vertex shader");
	
	GLuint fragment = create_fragment_shader();
	compile_shader(fragment, "Failed to compile fragment shader");

	GLuint program = create_shader_program(vertex, fragment);

	return program;
}

GLuint Shader::create_vertex_shader() const
{
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	std::string vert_src = util::read_file(vert_path_);
	if (vert_src.empty())
	{
		throw std::runtime_error("Can't load vertex shader");
	}
	const char *vert_src_char = vert_src.c_str();
	glShaderSource(vertex, 1, &vert_src_char, nullptr);
	return vertex;
}

GLuint Shader::create_fragment_shader() const
{
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
	std::string frag_src = util::read_file(frag_path_);
	if (frag_src.empty())
	{
		throw std::runtime_error("Can't load fragment shader");
	}
	const char *frag_src_char = frag_src.c_str();
	glShaderSource(fragment, 1, &frag_src_char, nullptr);
	return fragment;
}

void Shader::compile_shader(GLuint shader, const std::string& error_msg) const
{
	glCompileShader(shader);
	if (check_shader_error(shader, GL_COMPILE_STATUS, error_msg))
	{
		throw std::runtime_error(error_msg);
	}
}

GLuint Shader::create_shader_program(GLuint vertex_shader, GLuint fragment_shader) const
{
	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);
	if (check_shader_program_error(program, GL_LINK_STATUS, "Error: Shader program linking failed"))
	{
		throw std::runtime_error("Error: Shader program linking failed");
	}

	glValidateProgram(program);
	if (check_shader_program_error(program, GL_VALIDATE_STATUS,
		"Error: Shader program validation failed"))
	{
		throw std::runtime_error("Error: Shader program validation failed");
	}

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return program;
}

bool Shader::check_shader_error(GLuint shader, GLuint flag, const std::string& error_msg) const
{
	GLint success = 0;
	glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		GLchar error[ERROR_MSG_LEN] = { 0 };
		glGetShaderInfoLog(shader, sizeof(error), nullptr, error);
		std::cerr << error_msg << ":\n" << error << std::endl;
		return true;
	}
	return false;
}

bool Shader::check_shader_program_error(GLuint program, GLuint flag,
	const std::string& error_msg) const
{
	GLint success = 0;
	glGetProgramiv(program, flag, &success);

	if (success == GL_FALSE)
	{
		GLchar error[ERROR_MSG_LEN] = { 0 };
		glGetProgramInfoLog(program, sizeof(error), NULL, error);
		std::cerr << error_msg << ":\n" << error << std::endl;
		return true;
	}

	return false;
}
