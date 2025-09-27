#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Renderer.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    Window window(800, 600, "Skibidi Sigma Engine");
    Renderer renderer;

    while (!window.ShouldClose()) {
        window.PollEvents();
        renderer.Clear();
        renderer.DrawLine();
        window.SwapBuffers();
    }

    return 0;
}

