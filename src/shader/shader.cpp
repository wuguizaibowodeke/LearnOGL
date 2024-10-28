#include "shader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    std::string vertexShaderCode;
    std::string fragmentShaderCode;
    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;
    // Read shaders from file
    vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        vertexShaderFile.open(vertexShaderPath);
        fragmentShaderFile.open(fragmentShaderPath);
        std::stringstream vertexShaderStream, fragmentShaderStream;
        vertexShaderStream << vertexShaderFile.rdbuf();
        fragmentShaderStream << fragmentShaderFile.rdbuf();
        vertexShaderFile.close();
        fragmentShaderFile.close();
        vertexShaderCode = vertexShaderStream.str();
        fragmentShaderCode = fragmentShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char *vShaderCode = vertexShaderCode.c_str();
    const char *fShaderCode = fragmentShaderCode.c_str();
    // Compile shaders
    unsigned int vertexShader, fragmentShader;

    // Vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);
    // Check for errors
    checkCompileErrors(vertexShader, "COMPILE");
    // Fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);
    // Check for errors
    checkCompileErrors(fragmentShader, "COMPILE");
    // Link shaders
    mProgram = glCreateProgram();
    glAttachShader(mProgram, vertexShader);
    glAttachShader(mProgram, fragmentShader);
    glLinkProgram(mProgram);
    // Check for errors
    checkCompileErrors(mProgram, "LINK");
    // Delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
}

void Shader::begin()
{
    glUseProgram(mProgram);
}

void Shader::end()
{
    glUseProgram(0);
}

void Shader::setFloat(const std::string& name, float value) {
	//1 通过名称拿到Uniform变量的位置Location
	GLint location = glGetUniformLocation(mProgram, name.c_str());

	//2 通过Location更新Uniform变量的值
	glUniform1f(location, value);
}

void Shader::setVector3(const std::string& name, float x, float y, float z) {
	//1 通过名称拿到Uniform变量的位置Location
	GLint location = glGetUniformLocation(mProgram, name.c_str());
	
	//2 通过Location更新Uniform变量的值
	glUniform3f(location, x, y, z);
}

//重载 overload
void Shader::setVector3(const std::string& name, const float* values) {
	//1 通过名称拿到Uniform变量的位置Location
	GLint location = glGetUniformLocation(mProgram, name.c_str());

	//2 通过Location更新Uniform变量的值
	//第二个参数：你当前要更新的uniform变量如果是数组，数组里面包括多少个向量vec3
	glUniform3fv(location, 1, values);
}

void Shader::setInt(const std::string& name, int value) {
	//1 通过名称拿到Uniform变量的位置Location
	GLint location =glGetUniformLocation(mProgram, name.c_str());

	//2 通过Location更新Uniform变量的值
	glUniform1i(location, value);
}

void Shader::setMat4(const std::string &name, const float *values)
{
    GLint location = glGetUniformLocation(mProgram, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, values);
}

void Shader::checkCompileErrors(GLuint target, const std::string &type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type == "COMPILE")
    {
        glGetShaderiv(target, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(target, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
        }
    }
    else if (type == "LINK")
    {
        glGetProgramiv(target, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(target, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER::" << type << "::LINKING_FAILED\n"
                      << infoLog << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR::SHADER::UNKNOWN_TYPE" << std::endl;
        return;
    }
}
