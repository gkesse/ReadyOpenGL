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
};
//===============================================
GProcessO* GProcessOpenGLShader_New();
void GProcessOpenGLShader_Delete();
GProcessO* GProcessOpenGLShader();
//===============================================
#endif
//===============================================
