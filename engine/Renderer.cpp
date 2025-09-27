#include "Renderer.h"
#include <glad/glad.h>

const char* vertexSrc = R"glsl(
#version 330 core
layout(location = 0) in vec2 aPos;
void main() { gl_Position = vec4(aPos, 0.0, 1.0); }
)glsl";

const char* fragmentSrc = R"glsl(
#version 330 core
out vec4 FragColor;
void main() { FragColor = vec4(1.0, 1.0, 0.0, 1.0); }
)glsl";

Renderer::Renderer() {
    shader = new Shader(vertexSrc, fragmentSrc);

    float lineVertices[] = { -0.5f, -0.5f, 0.5f, 0.5f };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(lineVertices), lineVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Renderer::~Renderer() {
    delete shader;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Renderer::Clear() const {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::DrawLine() const {
    shader->Use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);
}
