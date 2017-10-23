#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"

Camera::Camera()
{
	position_ = glm::vec3(0.0f, 0.0f, 1.0f);
	target_ = glm::vec3(0.0f, 0.0f, 0.0f);
	direction_ = glm::normalize(position_ - target_);
	glm::vec3 world_up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 right_ = glm::normalize(glm::cross(world_up, direction_));
	up_ = glm::cross(direction_, right_);
	proj_mat_ = glm::perspective(90.0f, 1280.0f / 720.0f, 0.1f, 1000.0f);
}

void Camera::update()
{
	view_mat_ = glm::lookAt(position_, target_, up_);
	proj_view_mat_ = proj_mat_ * view_mat_;
}

glm::mat4 Camera::get_view_mat() const
{
	return view_mat_;
}

glm::mat4 Camera::get_proj_mat() const
{
	return proj_mat_;
}

glm::mat4 Camera::get_proj_view_mat() const
{
	return proj_view_mat_;
}
