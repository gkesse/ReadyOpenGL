//===============================================
#ifndef _GHeat_
#define _GHeat_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GHeatO GHeatO;
//===============================================
struct _GHeatO {
    void (*Delete)();
    sGColor (*HeatColor)(sGHeat* heat);
    sGColor (*JetColor)(sGHeat* heat);
};
//===============================================
GHeatO* GHeat_New();
void GHeat_Delete();
GHeatO* GHeat();
//===============================================
#endif
//===============================================
