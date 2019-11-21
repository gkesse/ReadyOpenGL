//===============================================
#ifndef _GProcessGlmTest_
#define _GProcessGlmTest_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessGlmTestO GProcessGlmTestO;
//===============================================
struct _GProcessGlmTestO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessGlmTest_New();
void GProcessGlmTest_Delete();
GProcessO* GProcessGlmTest();
//===============================================
#endif
//===============================================
