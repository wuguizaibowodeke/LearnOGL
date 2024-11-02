#include <iostream>

#include "base/core.h"
#include "src/shader/shader.h"
#include <string>
#include <assert.h>
#include "src/wrapper/checkError.h"
#include "src/Application/app.h"
#include "src/model/texture.h"

#include "src/camera/perspectiveCamera.h"
#include "src/camera/orthographicCamera.h"
#include "src/camera/trackBallCameraControl.h"

#include "src/model/geometry.h"
#include "src/model/material/phongMaterial.h"
#include "src/model/mesh.h"
#include "src/renderer/renderer.h"

Renderer* renderer = nullptr;
std::vector<Mesh*> meshes{};
DirectionalLight* dirLight = nullptr;
AmbientLight* ambLight = nullptr;

Camera* camera = nullptr;
CameraControl* cameraControl = nullptr;

App *app = App::getInstance();

void OnResize(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OnKeyBoard(int key, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(app->getWindow(), GLFW_TRUE);
    }
    else
    {
        cameraControl->OnKey(key, action, mods);
    }
}

void OnMouce(int button, int action, int mods)
{
    double xpos, ypos;
    app->getCursorPos(xpos, ypos);
    cameraControl->OnMouse(button, action,xpos, ypos);
}


void OnCursor(double xpos, double ypos)
{
    cameraControl->OnCursor(xpos, ypos);
}

void OnScroll(double offset)
{
    cameraControl->OnScroll(offset);
}

void prepare() {
	renderer = new Renderer();

	auto geometry = Geometry::createSphere(3.0f);

	auto material = new PhongMaterial();
	material->mShiness = 2.0f;
	material->mDiffuse = new Texture("assets/textures/goku.jpg", 0);

	auto mesh = new Mesh(geometry, material);

	meshes.push_back(mesh);

	dirLight = new DirectionalLight();
	ambLight = new AmbientLight();
	ambLight->mColor = glm::vec3(0.1f);
}

void prepareCamera() {
	float size = 10.0f;
	//camera = new OrthographicCamera(-size, size, size, -size, size, -size);
	camera = new PerspectiveCamera(
		60.0f, 
		(float)app->getWight() / (float)app->getHeight(),
		0.1f,
		1000.0f
	);

	//cameraControl = new GameCameraControl();
    cameraControl = new TrackBallCameraControl();
	cameraControl->setCamera(camera);
	//cameraControl->setSensitivity(0.4f);
}



int main() {
	if (!app->Init(1600, 1200)) {
		return -1;
	}

    app->setResizeCallBack(OnResize);
    app->setKeyboardCallBack(OnKeyBoard);
    app->setMouseCallBack(OnMouce);
    app->setCursorCallBack(OnCursor);
    app->setScrollCallBack(OnScroll);

	GL_CALL(glViewport(0, 0, 1600, 1200));
	GL_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));

	prepareCamera();
	prepare();

	while (app->update()) {
		cameraControl->update();
		renderer->render(meshes, camera, dirLight, ambLight);
	}

	app->destory();

	return 0;
}