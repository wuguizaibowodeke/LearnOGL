#include "cameraControl.h"

CameraControl::CameraControl()
{
}

void CameraControl::update()
{
}

void CameraControl::OnMouse(int button, int action, double xpos, double ypos)
{
    bool pressed = action == GLFW_PRESS ? true : false;

    if (pressed)
    {
        mCurrentX = xpos;
        mCurrentY = ypos;
    }

    switch (button)
    {
    case GLFW_MOUSE_BUTTON_LEFT:
        mLeftMouseButtonPressed = pressed;
        break;
    case GLFW_MOUSE_BUTTON_MIDDLE:
        mMiddleMouseButtonPressed = pressed;
        break;
    case GLFW_MOUSE_BUTTON_RIGHT:
        mRightMouseButtonPressed = pressed;
        break;
    default:
        break;
    }
}

void CameraControl::OnCursor(float xpos, float ypos)
{

}

void CameraControl::OnKey(int key, int action, int mods)
{
    if(action == GLFW_RELEASE)
        return;
    bool pressed = action == GLFW_PRESS ? true : false;

    mKeysPressed[key] = pressed;
}

void CameraControl::OnScroll(float offset)
{
}
