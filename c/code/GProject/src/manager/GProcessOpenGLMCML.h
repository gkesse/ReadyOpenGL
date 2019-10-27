//===============================================
#ifndef _GProcessOpenGLMCML_
#define _GProcessOpenGLMCML_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLMCMLO GProcessOpenGLMCMLO;
//===============================================
struct _GProcessOpenGLMCMLO {
    GProcessO* m_parent;
	double m_mcmlData[GMCML_BUFFER_MAX];
	sGVertex m_mcmlVertex[GMCML_BUFFER_MAX];
	sGColor m_mcmlColor[GMCML_BUFFER_MAX];
};
//===============================================
GProcessO* GProcessOpenGLMCML_New();
void GProcessOpenGLMCML_Delete();
GProcessO* GProcessOpenGLMCML();
//===============================================
#endif
//===============================================
