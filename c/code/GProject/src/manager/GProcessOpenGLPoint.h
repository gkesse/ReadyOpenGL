//===============================================
#ifndef _GProcessOpenGLPoint_
#define _GProcessOpenGLPoint_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLPointO GProcessOpenGLPointO;
//===============================================
struct _GProcessOpenGLPointO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLPoint_New();
void GProcessOpenGLPoint_Delete();
GProcessO* GProcessOpenGLPoint();
//===============================================
#endif
//===============================================
