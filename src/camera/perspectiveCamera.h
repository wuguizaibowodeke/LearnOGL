#pragma once

#include "camera.h"

class PerspectiveCamera : public Camera
{
public:
    PerspectiveCamera(float fov, float aspectRatio, float near, float far);

    glm::mat4 getProjectionMatrix() override;

    void scale(float scale) override;

private:
    float mFov = 0.0f;
    float mAspectRatio = 0.0f;
    float mNear = 0.0f;
    float mFar = 0.0f;
};