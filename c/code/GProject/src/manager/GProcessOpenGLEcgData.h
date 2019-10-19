//===============================================
#ifndef _GProcessOpenGLEcgData_
#define _GProcessOpenGLEcgData_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLEcgDataO GProcessOpenGLEcgDataO;
//===============================================
struct _GProcessOpenGLEcgDataO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLEcgData_New();
void GProcessOpenGLEcgData_Delete();
GProcessO* GProcessOpenGLEcgData();
//===============================================
#endif
//===============================================
