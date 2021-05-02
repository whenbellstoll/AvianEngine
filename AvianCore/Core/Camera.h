#pragma once
#include <Windows.h>
#include "Transform.h"
class Camera
{
	// Fields
	Transform transform;
	DirectX::XMFLOAT4X4 viewMatrix;
	DirectX::XMFLOAT4X4 projMatrix;
	POINT mousePos;
	float mouseSpeed;
	float fov;
	float nearPlaneDistance;
	float farPlaneDistance;

public:
	// Constructor
	Camera(DirectX::XMFLOAT3 pos, float nFov, float nearClip, float farClip);

	// Getters
	DirectX::XMFLOAT4X4 GetViewMatrix();
	DirectX::XMFLOAT4X4 GetProjMatrix();
	DirectX::XMFLOAT3 GetPosition();

	void UpdateProjectionMatrix( float aspectRatio );
	void UpdateViewMatrix();

	void Update(float dt, HWND windowHandle);
};

