#include "orthographicCamera.h"

OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float near, float far)
{
    mLeft = left;
    mRight = right;
    mBottom = bottom;
    mTop = top;
    mNear = near;
    mFar = far;
}

glm::mat4 OrthographicCamera::getProjectionMatrix()
{
    float scale = std::pow(2.0f, mScale);
    mLeft *= scale;
    mRight *= scale;
    mBottom *= scale;
    mTop *= scale;  
    return glm::ortho(mLeft, mRight, mBottom, mTop, mNear, mFar);
}

void OrthographicCamera::scale(float scale)
{
    mScale+=scale;
}
