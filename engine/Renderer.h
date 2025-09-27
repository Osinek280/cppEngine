#pragma once
#include "Shader.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void Clear() const;
    void DrawLine() const;

private:
    unsigned int VAO, VBO;
    Shader* shader;
};
