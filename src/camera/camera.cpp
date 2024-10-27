#include "camera.h"

glm::mat4 Camera::getViewMatrix()
{
    //lookat 
    //-eye:相机位置
    //-center:相机指向的目标位置
    //-up:相机的上方向mUp
    glm::vec3 front = glm::cross(mUp, mRight);

    glm::vec3 center = mPosition + front;

    return glm::lookAt(mPosition, center, mUp);
}

glm::mat4 Camera::getProjectionMatrix()
{
    return glm::identity<glm::mat4>();
}

void Camera::scale(float scale)
{
}
