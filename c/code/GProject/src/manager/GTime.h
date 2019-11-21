//===============================================
#ifndef _GTime_
#define _GTime_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GTimeO GTimeO;
//===============================================
struct _GTimeO {
    void (*Delete)();
    double (*GetDiffTime)();
    sGTime m_time;
};
//===============================================
GTimeO* GTime_New();
void GTime_Delete();
GTimeO* GTime();
//===============================================
#endif
//===============================================
