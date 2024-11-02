#include "renderer.h"
#include <iostream>
#include "model/material/phongMaterial.h"

Renderer::Renderer() {
	mPhongShader = new Shader("assets/shaders/phong.vert", "assets/shaders/phong.frag");
}

Renderer::~Renderer() {

}

void Renderer::render(
	const std::vector<Mesh*>& meshes,
	Camera* camera,
	DirectionalLight* dirLight,
	AmbientLight* ambLight
) {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < meshes.size(); i++) {
		auto mesh = meshes[i];
		auto geometry = mesh->mGeometry;
		auto material = mesh->mMaterial;
 
		Shader* shader = pickShader(material->mType);

		shader->begin();

		switch (material->mType) {
		case MaterialType::PhongMaterial: {
			PhongMaterial* phongMat = (PhongMaterial*)material;
			shader->setInt("sampler", 0);

			phongMat->mDiffuse->bind();

			//mvp
			shader->setMatrix4x4("modelMatrix", mesh->getModelMatrix());
			shader->setMatrix4x4("viewMatrix", camera->getViewMatrix());
			shader->setMatrix4x4("projectionMatrix", camera->getProjectionMatrix());

			auto normalMatrix = glm::mat3(glm::transpose(glm::inverse(mesh->getModelMatrix())));
			shader->setMatrix3x3("normalMatrix", normalMatrix);

			shader->setVector3("lightDirection", dirLight->mDirection);
			shader->setVector3("lightColor", dirLight->mColor);
			shader->setFloat("specularIntensity", dirLight->mSpecularIntensity);

			shader->setFloat("shiness", phongMat->mShiness);

			shader->setVector3("ambientColor", ambLight->mColor);

			shader->setVector3("cameraPosition", camera->mPosition);

		}	
			break;
		default:
			continue;
		}
	
		glBindVertexArray(geometry->getVao());

		glDrawElements(GL_TRIANGLES, geometry->getIndicesCount(), GL_UNSIGNED_INT, 0);
	}
}

Shader* Renderer::pickShader(MaterialType type) {
	Shader* result = nullptr;

	switch (type) {
	case MaterialType::PhongMaterial:
		result = mPhongShader;
		break;
	default:
		std::cout << "Unknown material type to pick shader" << std::endl;
		break;
	}

	return result;
}
