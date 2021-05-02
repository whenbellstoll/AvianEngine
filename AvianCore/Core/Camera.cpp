#include "Camera.h"

Camera::Camera(DirectX::XMFLOAT3 pos, float nFov, float nearClip, float farClip)
{
    transform.SetPosition(pos.x, pos.y, pos.z);
    mouseSpeed = 1.0f; // not sure what to set this
    fov = nFov;
    nearPlaneDistance = nearClip;
    farPlaneDistance = farClip;
    mousePos = {};
    XMStoreFloat4x4(&projMatrix, DirectX::XMMatrixIdentity());
    XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixIdentity());
    UpdateViewMatrix();
    UpdateProjectionMatrix(16.0f / 9.0f);
}

DirectX::XMFLOAT4X4 Camera::GetViewMatrix()
{
    return viewMatrix;
}

DirectX::XMFLOAT4X4 Camera::GetProjMatrix()
{
    return projMatrix;
}

DirectX::XMFLOAT3 Camera::GetPosition()
{
    return transform.GetPosition();
}

void Camera::UpdateProjectionMatrix(float aspectRatio)
{
    XMStoreFloat4x4(&projMatrix, DirectX::XMMatrixPerspectiveFovLH( 1.0f, aspectRatio, nearPlaneDistance, farPlaneDistance) );
}

void Camera::UpdateViewMatrix()
{
    DirectX::XMVECTOR positionVec = DirectX::XMVectorSet(transform.GetPosition().x, transform.GetPosition().y, transform.GetPosition().z, 0);
    
    // Direction Vector
    DirectX::XMVECTOR worldForward = DirectX::XMVectorSet(0, 0, 1, 0);
    DirectX::XMVECTOR quaternion = DirectX::XMQuaternionRotationRollPitchYaw(transform.GetRotation().x, transform.GetRotation().y, transform.GetRotation().z);
    DirectX::XMVECTOR directionVec = DirectX::XMVector3Rotate(worldForward, quaternion);

    DirectX::XMVECTOR upVec = DirectX::XMVectorSet(0, 1, 0, 0);

    XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixLookToLH( positionVec, directionVec, upVec) );
}

void Camera::Update(float dt, HWND windowHandle)
{
    // handle keyboard input
    float movementSpeed = 0.6f;
    if (GetAsyncKeyState( 'W' ) & 0x8000)
    {
        transform.MoveRelative(0, 0, movementSpeed * dt);
    }
    if (GetAsyncKeyState( 'S' ) & 0x8000)
    {
        transform.MoveRelative(0, 0, -movementSpeed * dt);
    }
    if (GetAsyncKeyState( 'A' ) & 0x8000)
    {
        transform.MoveRelative(-movementSpeed * dt, 0, 0);
    }
    if (GetAsyncKeyState( 'D' ) & 0x8000)
    {
        transform.MoveRelative(movementSpeed * dt, 0, 0);
    }
    if (GetAsyncKeyState( 'X' ) & 0x8000)
    {
        transform.MoveAbsolute(0, movementSpeed * dt, 0);
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        transform.MoveAbsolute(0, -movementSpeed * dt, 0);
    }
    // handle mouse
    POINT currentMousePos = {};
    GetCursorPos(&currentMousePos);
    ScreenToClient(windowHandle, &currentMousePos);

    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
    {
        float xdiff = (float)mousePos.x - (float)currentMousePos.x;
        float ydiff = (float)mousePos.y - (float)currentMousePos.y;

        xdiff *= dt;
        ydiff *= dt;
        xdiff *= mouseSpeed;
        ydiff *= mouseSpeed;

        transform.Rotate(-ydiff, -xdiff, 0);
    }

    mousePos = currentMousePos;

    // Update View Matrix
    UpdateViewMatrix();
}

