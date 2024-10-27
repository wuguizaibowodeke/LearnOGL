#pragma once

#include "base/core.h"
#include "camera.h"

#include <map>

class CameraControl
{
public:
    CameraControl();

    CameraControl(Camera *camera) : mCamera(camera) {}

    virtual ~CameraControl() {}

    virtual void update();

    virtual void OnMouse(int button, int action, double xpos, double ypos);

    virtual void OnCursor(float xpos, float ypos);

    virtual void OnKey(int key, int action, int mods);

    virtual void OnScroll(float offset);//offset = +-1

    void setCamera(Camera *camera) { mCamera = camera; }

    void setMouseSpeed(float speed) { mMouseSpeed = speed; }

    void setScaleSpeed(float speed) { mScaleSpeed = speed; }

protected:
    bool mLeftMouseButtonPressed = false;
    bool mRightMouseButtonPressed = false;
    bool mMiddleMouseButtonPressed = false;
    float mCurrentX = 0.0f;
    float mCurrentY = 0.0f;
    std::map<int, bool> mKeysPressed;
    float mMouseSpeed = 0.1f;
    Camera *mCamera = nullptr;

    //记录相机缩放速度
    float mScaleSpeed = 0.2f;
};