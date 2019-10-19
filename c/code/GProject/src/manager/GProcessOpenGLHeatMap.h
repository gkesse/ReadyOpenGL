//===============================================
#ifndef _GProcessOpenGLHeatMap_
#define _GProcessOpenGLHeatMap_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLHeatMapO GProcessOpenGLHeatMapO;
//===============================================
struct _GProcessOpenGLHeatMapO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenGLHeatMap_New();
void GProcessOpenGLHeatMap_Delete();
GProcessO* GProcessOpenGLHeatMap();
//===============================================
#endif
//===============================================
