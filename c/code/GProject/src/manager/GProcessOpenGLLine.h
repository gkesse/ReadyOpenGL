//===============================================
#ifndef _GProcessOpenGLLine_
#define _GProcessOpenGLLine_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLLineO GProcessOpenGLLineO;
//===============================================
struct _GProcessOpenGLLineO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLLine_New();
void GProcessOpenGLLine_Delete();
GProcessO* GProcessOpenGLLine();
//===============================================
#endif
//===============================================
