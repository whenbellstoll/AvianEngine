#include "Transform.h"

Transform::Transform()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);

	//XMStoreFloat4x4(&worldMatrix, DirectX::XMMatrixIdentity());
}

glm::vec3 Transform::GetPosition()
{
	return position;
}

glm::vec3 Transform::GetRotation()
{
	return rotation;
}

glm::vec3 Transform::GetScale()
{
	return scale;
}

glm::mat4x4 Transform::GetWorldMatrix()
{
	// Update World Matrix
	glm::mat4x4 translationMatrix;// = DirectX::XMMatrixTranslation(position.x, position.y, position.z);
	glm::mat4x4 scaleMatrix;// = DirectX::XMMatrixScaling(scale.x, scale.y, scale.z);
	glm::mat4x4 rpyMatrix;// = DirectX::XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);

	// From the example, order is scale, rotation, translation in multiplcation.
	glm::mat4x4 world = scaleMatrix * rpyMatrix * translationMatrix;
	
	// Put our calculation into our Float4x4
	//DirectX::XMStoreFloat4x4(&worldMatrix, world);

	// return our 4x4
	return world;
}


// setters
void Transform::SetPosition(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
}

void Transform::SetRotation(float pitch, float yaw, float roll)
{
	rotation = glm::vec3(pitch, yaw, roll);
}

void Transform::SetScale(float x, float y)
{
	scale = glm::vec3(x, y, 1.0f);
}


// Transformers
void Transform::MoveAbsolute(float x, float y)
{
	//just add to the current position :)
	position = glm::vec3(position.x + x, position.y + y, position.z);
}

void Transform::Rotate(float pitch, float yaw, float roll)
{
	rotation = glm::vec3(rotation.x + pitch, rotation.y + yaw, rotation.z + roll);
}

void Transform::Scale(float x, float y)
{
	scale = glm::vec3( scale.x + x, scale.y + y, scale.z);
}

void Transform::MoveRelative(float x, float y)
{
	// Direction Vector
	//DirectX::XMVECTOR absoluteDirection = DirectX::XMVectorSet(x, y, z, 0);
	//DirectX::XMVECTOR quaternion = DirectX::XMQuaternionRotationRollPitchYaw(GetRotation().x, GetRotation().y, GetRotation().z);
	//DirectX::XMVECTOR directionVec = DirectX::XMVector3Rotate(absoluteDirection, quaternion);

	//DirectX::XMVECTOR pos = DirectX::XMLoadFloat3(&GetPosition());
	//pos = DirectX::XMVectorAdd(pos, directionVec);
	//DirectX::XMStoreFloat3(&position, pos);
}