#pragma once
#include <string>

// tylko forward declaration, nie include
struct GLFWwindow;

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    void PollEvents();
    void SwapBuffers();
    bool ShouldClose() const;

    GLFWwindow* GetNativeWindow() const;

private:
    GLFWwindow* m_Window;
};
