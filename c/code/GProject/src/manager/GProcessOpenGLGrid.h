//===============================================
#ifndef _GProcessOpenGLGrid_
#define _GProcessOpenGLGrid_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLGridO GProcessOpenGLGridO;
//===============================================
struct _GProcessOpenGLGridO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLGrid_New();
void GProcessOpenGLGrid_Delete();
GProcessO* GProcessOpenGLGrid();
//===============================================
#endif
//===============================================
