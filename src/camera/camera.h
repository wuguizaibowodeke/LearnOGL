#pragma once
#include "base/core.h"

class Camera {
public:
    Camera() {}      
    ~Camera() {} 

    glm::mat4 getViewMatrix();
    virtual glm::mat4 getProjectionMatrix();

    virtual void scale(float scale);

public:
    glm::vec3 mPosition = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 mUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 mRight = glm::vec3(1.0f, 0.0f, 0.0f);
};

