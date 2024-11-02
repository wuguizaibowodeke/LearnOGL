#pragma once

#include "base/core.h"
#include<string>

class Shader {
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	
	void begin();

	void end();

	void setFloat(const std::string& name, float value);

	void setVector3(const std::string& name, float x, float y, float z);
	void setVector3(const std::string& name, const float* values);
	void setVector3(const std::string& name, const glm::vec3 value);

	void setInt(const std::string& name, int value);

	void setMatrix4x4(const std::string& name, glm::mat4 value);
	void setMatrix3x3(const std::string& name, glm::mat3 value);
private:
	//shader program
	//type:COMPILE LINK
	void checkShaderErrors(GLuint target,std::string type);

private:
	GLuint mProgram{ 0 };
};
