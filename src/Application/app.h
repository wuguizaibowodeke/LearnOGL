#pragma once

class GLFWwindow;

typedef void (*ResizeCallBack)(int, int);
typedef void (*KeyboardCallBack)(int key, int action, int mods);
typedef void (*MouseCallBack)(int button, int action, int mods);
typedef void (*CursorCallBack)(double xoffset, double yoffset);
typedef void (*ScrollCallBack)(double offset);

class App
{
public:
    ~App() {};

    static App *getInstance();

    bool Init(const int width = 800, const int height = 600);

    bool update();

    bool destory();

    void setResizeCallBack(ResizeCallBack callback);

    void setKeyboardCallBack(KeyboardCallBack keyboardCallBack);

    void setMouseCallBack(MouseCallBack mouseCallBack);

    void setCursorCallBack(CursorCallBack cursorCallBack);

    void setScrollCallBack(ScrollCallBack scrollCallBack);

    unsigned int getWight() { return mWidth; }

    unsigned int getHeight() { return mHeight; }

    GLFWwindow *getWindow() { return mWindow; }

    void getCursorPos(double &xpos, double &ypos);

private:
    App() {};

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    static void keyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods);

    static void mouseCallBack(GLFWwindow *window, int button, int action, int mods);

    static void cursorCallBack(GLFWwindow *window, double xpos, double ypos);

    static void scrollCallBack(GLFWwindow *window, double xoffset, double yoffset);

private:
    static App *mInstance;
    GLFWwindow *mWindow;
    unsigned int mWidth;
    unsigned int mHeight;

    ResizeCallBack mResizeCallBack{nullptr};
    KeyboardCallBack mKeyboardCallBack{nullptr};
    MouseCallBack mMouseCallBack{nullptr};
    CursorCallBack mCursorCallBack{nullptr};
    ScrollCallBack mScrollCallBack{nullptr};
};
