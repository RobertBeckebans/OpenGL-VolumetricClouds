#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int ID;
	Shader(const char* vertexPath, const char* fragmentPath);
	virtual ~Shader();
	void use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setVec2(const std::string &name, glm::vec2 vector) const;
	void setVec3(const std::string &name, glm::vec3 vector) const;
	void setVec4(const std::string &name, glm::vec4 vector) const;
	void setMat4(const std::string &name, glm::mat4 matrix) const;
	void setSampler2D(const std::string &name, unsigned int texture, int id) const;
	void setSampler3D(const std::string &name, unsigned int texture, int id) const;

protected:
	void checkCompileErrors(unsigned int shader, std::string type, std::string shaderName);
	std::string getShaderName(const char* shaderPath);
	std::string loadShaderFromFile(const char* shaderPath);
};

