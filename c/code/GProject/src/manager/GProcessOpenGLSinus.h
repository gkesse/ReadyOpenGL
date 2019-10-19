//===============================================
#ifndef _GProcessOpenGLSinus_
#define _GProcessOpenGLSinus_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLSinusO GProcessOpenGLSinusO;
//===============================================
struct _GProcessOpenGLSinusO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLSinus_New();
void GProcessOpenGLSinus_Delete();
GProcessO* GProcessOpenGLSinus();
//===============================================
#endif
//===============================================
