//===============================================
#ifndef _GProcessOpenGLTriangle_
#define _GProcessOpenGLTriangle_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLTriangleO GProcessOpenGLTriangleO;
//===============================================
struct _GProcessOpenGLTriangleO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLTriangle_New();
void GProcessOpenGLTriangle_Delete();
GProcessO* GProcessOpenGLTriangle();
//===============================================
#endif
//===============================================
