//===============================================
#ifndef _GProcessOpenGLTest_
#define _GProcessOpenGLTest_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLTestO GProcessOpenGLTestO;
//===============================================
struct _GProcessOpenGLTestO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLTest_New();
void GProcessOpenGLTest_Delete();
GProcessO* GProcessOpenGLTest();
//===============================================
#endif
//===============================================
