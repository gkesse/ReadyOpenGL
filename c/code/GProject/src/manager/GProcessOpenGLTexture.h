//===============================================
#ifndef _GProcessOpenGLTexture_
#define _GProcessOpenGLTexture_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLTextureO GProcessOpenGLTextureO;
//===============================================
struct _GProcessOpenGLTextureO {
    GProcessO* m_parent;

    sGWindow m_window;
    sGCamera m_camera;
    sGCameraView m_cameraView;

    sGShader m_shader;
    sGShaderVAO m_shaderVAO;
    sGShaderVBO m_vertexVBO;
    sGShaderVBO m_textureVBO;
    sGShaderAttrib m_vertexAttrib;
    sGShaderAttrib m_textureAttrib;

    sGTexture m_texture;

    sGProjection m_projection;
};
//===============================================
GProcessO* GProcessOpenGLTexture_New();
void GProcessOpenGLTexture_Delete();
GProcessO* GProcessOpenGLTexture();
//===============================================
#endif
//===============================================
