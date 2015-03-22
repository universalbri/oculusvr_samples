#ifndef SHADERMANAGER_HPP
#define SHADERMANAGER_HPP

#include "renderer/OpenGL.hpp"
#include "renderer/Shader.hpp"

class ShaderManager
{
public:
    // specific shaders
    enum ShaderName
    {
        BasicShader,
        FrustumShader,
        NUM_SHADERS
    };

    static ShaderManager* GetInstance();

    void LoadShaders();
    void DestroyShaders();

    const ShaderProgram& GetShaderProgram(ShaderName type) const { return m_shaderProgram[type]; }
    const ShaderProgram& GetActiveShader() const { return m_shaderProgram[m_activeShader]; }
    const ShaderProgram& UseShaderProgram(ShaderName type);
    void ResetActiveShader() { m_activeShader = NUM_SHADERS; }
private:
    ShaderManager() : m_activeShader(NUM_SHADERS)
    {
    }

    ~ShaderManager();

    char *ReadShaderFromFile(const char *filename);
    void CompileShader(GLuint *newShader, GLenum shaderType, const char *shaderSrc);
    void LoadShader(ShaderName shaderName, const char* vshFilename, const char *fshFilename);
    bool LinkShader(GLuint* const pProgramObject, const GLuint VertexShader, const GLuint FragmentShader); /*, const char** const pszAttribs, const int i32NumAttribs)*/
    ShaderName m_activeShader;

    ShaderProgram m_shaderProgram[NUM_SHADERS];
};

#endif
