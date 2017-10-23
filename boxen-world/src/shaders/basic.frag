#version 330

in vec2 out_texture_coord;
out vec4 color;

uniform sampler2D tex_sampler;

void main()
{
	color = texture(tex_sampler, out_texture_coord);
}