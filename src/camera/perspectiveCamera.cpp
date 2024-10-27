#include "perspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(float fov, float aspectRatio, float near, float far)
{
    mFov = fov;
    mAspectRatio = aspectRatio;        
    mNear = near;
    mFar = far;
}

glm::mat4 PerspectiveCamera::getProjectionMatrix()
{
    return glm::perspective(glm::radians(mFov), mAspectRatio, mNear, mFar);
}

void PerspectiveCamera::scale(float scale)
{
    auto front = glm::cross(mUp,mRight);
    mPosition += front * scale;
}
