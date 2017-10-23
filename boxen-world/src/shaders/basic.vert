#version 330

layout(location = 0) in vec3 vertex_pos;
layout(location = 1) in vec2 texture_coord;

out vec2 out_texture_coord;

uniform mat4 proj_view_mat;
uniform mat4 model_mat;

void main()
{
	gl_Position = proj_view_mat * model_mat * vec4(vertex_pos, 1.0);
	out_texture_coord = texture_coord;
}