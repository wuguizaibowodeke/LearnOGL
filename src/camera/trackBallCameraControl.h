#pragma once

#include "cameraControl.h"

class TrackBallCameraControl : public CameraControl
{
public:
    TrackBallCameraControl();
    ~TrackBallCameraControl() {}

    void OnCursor(float xpos, float ypos) override;

    void OnScroll(float offset) override;

private:
    void pitch(float angle);
    void yaw(float angle);

private:
    float mMoveSpeed = 0.005f;
};