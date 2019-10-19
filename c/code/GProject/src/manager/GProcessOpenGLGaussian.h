//===============================================
#ifndef _GProcessOpenGLGaussian_
#define _GProcessOpenGLGaussian_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLGaussianO GProcessOpenGLGaussianO;
//===============================================
struct _GProcessOpenGLGaussianO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLGaussian_New();
void GProcessOpenGLGaussian_Delete();
GProcessO* GProcessOpenGLGaussian();
//===============================================
#endif
//===============================================
