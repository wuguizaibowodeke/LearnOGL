#include "trackBallCameraControl.h"

TrackBallCameraControl::TrackBallCameraControl()
{
}

void TrackBallCameraControl::OnCursor(float xpos, float ypos)
{
    if(mLeftMouseButtonPressed)
    {
        float dx = (xpos - mCurrentX) * mMouseSpeed;
        float dy = (ypos - mCurrentY) * mMouseSpeed;

        pitch(-dy);
        yaw(-dx);
    }
    else if(mRightMouseButtonPressed)
    {
        float dx = (xpos - mCurrentX) * mMoveSpeed;
        float dy = (ypos - mCurrentY) * mMoveSpeed;        

        mCamera->mPosition -= mCamera->mRight * dx ;
        mCamera->mPosition += mCamera->mUp * dy;
    }

    mCurrentX = xpos;
    mCurrentY = ypos;
}

void TrackBallCameraControl::OnScroll(float offset)
{
    mCamera->scale(mScaleSpeed * offset);
}

void TrackBallCameraControl::pitch(float angle)
{
    auto mat = glm::rotate(glm::mat4(1.0f), glm::radians(angle), mCamera->mRight);

    mCamera->mUp = mat * glm::vec4(mCamera->mUp, 0.0f);

    mCamera->mPosition = mat * glm::vec4(mCamera->mPosition, 1.0f);
}

void TrackBallCameraControl::yaw(float angle)
{
    auto mat = glm::rotate(glm::mat4(1.0f), glm::radians(angle),glm::vec3(0.0f, 1.0f, 0.0f));

    mCamera->mRight = mat * glm::vec4(mCamera->mRight, 0.0f);

    mCamera->mPosition = mat * glm::vec4(mCamera->mPosition, 1.0f);

    mCamera->mUp = mat * glm::vec4(mCamera->mUp, 0.0f);
}
