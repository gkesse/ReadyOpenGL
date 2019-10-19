//===============================================
#ifndef _GProcessOpenGLGaussian2D_
#define _GProcessOpenGLGaussian2D_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLGaussian2DO GProcessOpenGLGaussian2DO;
//===============================================
struct _GProcessOpenGLGaussian2DO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLGaussian2D_New();
void GProcessOpenGLGaussian2D_Delete();
GProcessO* GProcessOpenGLGaussian2D();
//===============================================
#endif
//===============================================
