#pragma once

#include "base/core.h"

#include <string>

class Shader {
public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~Shader();

    void begin();
    void end();

    // uniform工具函数
	void setFloat(const std::string& name, float value);

	void setVector3(const std::string& name, float x, float y, float z);
	void setVector3(const std::string& name, const float* values);

	void setInt(const std::string& name, int value);

    void setMat4(const std::string& name, const float* values);

private:
    //type:Compile LINK
    void checkCompileErrors(GLuint target, const std::string& type);

private:
    GLuint mProgram{0};

};