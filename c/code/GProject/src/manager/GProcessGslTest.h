//===============================================
#ifndef _GProcessGslTest_
#define _GProcessGslTest_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessGslTestO GProcessGslTestO;
//===============================================
struct _GProcessGslTestO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessGslTest_New();
void GProcessGslTest_Delete();
GProcessO* GProcessGslTest();
//===============================================
#endif
//===============================================
