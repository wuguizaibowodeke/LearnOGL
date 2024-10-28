#include "app.h"
#include <glad/glad.h> 
#include "GLFW/glfw3.h"

#include <iostream>
App* App::mInstance = nullptr;

App *App::getInstance()
{
    if (mInstance == nullptr)
    {
        mInstance = new App();
    }
    return mInstance;
}

bool App::Init(const int width ,const int height)
{
    mWidth = width;
    mHeight = height;

    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    mWindow = glfwCreateWindow(mWidth,mHeight , "LearnOpenGL", NULL, NULL);
    if (mWindow == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(mWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glfwSetFramebufferSizeCallback(mWindow,framebuffer_size_callback); 
    glfwSetKeyCallback(mWindow,keyCallBack);
    glfwSetMouseButtonCallback(mWindow,mouseCallBack);
    glfwSetCursorPosCallback(mWindow,cursorCallBack);
    glfwSetScrollCallback(mWindow,scrollCallBack);

    return true;    
}

bool App::update()
{
    if(glfwWindowShouldClose(mWindow))
    {
        return false;
    }

    glfwPollEvents();

    glfwSwapBuffers(mWindow);
    return true;
}

bool App::destory()
{
    glfwTerminate();
    return true;
}

void App::setResizeCallBack(ResizeCallBack callback)
{
    mResizeCallBack = callback;
}

void App::setKeyboardCallBack(KeyboardCallBack keyboardCallBack)
{
    mKeyboardCallBack = keyboardCallBack;
}

void App::setMouseCallBack(MouseCallBack mouseCallBack)
{
    mMouseCallBack = mouseCallBack;
}

void App::setCursorCallBack(CursorCallBack cursorCallBack)
{
    mCursorCallBack = cursorCallBack;
}

void App::setScrollCallBack(ScrollCallBack scrollCallBack)
{
    mScrollCallBack = scrollCallBack;
}

void App::getCursorPos(double &xpos, double &ypos)
{
    glfwGetCursorPos(mWindow, &xpos, &ypos);
}

void App::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    if(App::getInstance()->mResizeCallBack!=nullptr)
        App::getInstance()->mResizeCallBack(width,height);
}

void App::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(App::getInstance()->mKeyboardCallBack!=nullptr)
        App::getInstance()->mKeyboardCallBack(key,action,mods);
}

void App::mouseCallBack(GLFWwindow *window, int button, int action, int mods)
{
    if(App::getInstance()->mMouseCallBack!=nullptr)
        App::getInstance()->mMouseCallBack(button,action,mods);
}

void App::cursorCallBack(GLFWwindow *window, double xpos, double ypos)
{
    if(App::getInstance()->mCursorCallBack!=nullptr)
        App::getInstance()->mCursorCallBack(xpos,ypos);
}

void App::scrollCallBack(GLFWwindow *window, double xoffset, double yoffset)
{
    if(App::getInstance()->mScrollCallBack!=nullptr)
        App::getInstance()->mScrollCallBack(yoffset);
}
