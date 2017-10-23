#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
	Camera();
	void update();
	glm::mat4 get_view_mat() const;
	glm::mat4 get_proj_mat() const;
	glm::mat4 get_proj_view_mat() const;
private:
	glm::vec3 position_;
	glm::vec3 target_;
	glm::vec3 direction_;
	glm::vec3 right_;
	glm::vec3 up_;
	glm::mat4 proj_mat_;
	glm::mat4 view_mat_;
	glm::mat4 proj_view_mat_;
};