//===============================================
#ifndef _GProcessOpenGLShader_
#define _GProcessOpenGLShader_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLShaderO GProcessOpenGLShaderO;
//===============================================
struct _GProcessOpenGLShaderO {
    GProcessO* m_parent;
    sGShader m_shader;
    sGShaderVAO m_shaderVAO;
    sGShaderVBO m_vertexVBO;
    sGShaderVBO m_colorVBO;
    sGShaderAttrib m_positionAttrib;
    sGShaderAttrib m_colorAttrib;

    sGTexture m_texture;
};
//===============================================
GProcessO* GProcessOpenGLShader_New();
void GProcessOpenGLShader_Delete();
GProcessO* GProcessOpenGLShader();
//===============================================
#endif
//===============================================
