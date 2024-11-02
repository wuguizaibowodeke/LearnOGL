#pragma once

#include <vector>
#include "base/core.h"
#include "../model/mesh.h"
#include "../camera/camera.h"
#include "../light/directionalLight.h"
#include "../light/ambientLight.h"
#include "../shader/shader.h"

class Renderer {
public:
	Renderer();
	~Renderer();

	void render(
		const std::vector<Mesh*>& meshes,
		Camera* camera,
		DirectionalLight* dirLight,
		AmbientLight* ambLight
	);

private:
	Shader* pickShader(MaterialType type);

private:
	Shader* mPhongShader{ nullptr };
};