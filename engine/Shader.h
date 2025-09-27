#pragma once
#include <string>
#include <glad/glad.h>

class Shader {
public:
    unsigned int ID;
    Shader(const char* vertexSrc, const char* fragmentSrc);
    void Use() const;
    ~Shader();
};
