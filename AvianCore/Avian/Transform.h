#pragma once
#include <glm/glm.hpp>

class Transform
{
	// Fields
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	glm::mat4x4 worldMatrix;

public:
	// Constructor
	Transform();

	// Getters
	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();
	glm::mat4x4 GetWorldMatrix();

	// Setters
	void SetPosition(float x, float y, float z); 
	void SetRotation(float pitch, float yaw, float roll);
	void SetScale(float x, float y);

	// Transformers
	void MoveAbsolute(float x, float y);
	void Rotate(float pitch, float yaw, float roll);
	void Scale(float x, float y);

	//Assignment 5 Move Relative
	void MoveRelative(float x, float y);
};

