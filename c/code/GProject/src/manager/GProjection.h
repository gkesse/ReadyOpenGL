//===============================================
#ifndef _GProjection_
#define _GProjection_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GProjectionO GProjectionO;
//===============================================
struct _GProjectionO {
    void (*Delete)();
    void (*SetModel)(sGProjection* MVP, mat4 data);
    void (*InitModel)(sGProjection* MVP);
    void (*SetView)(sGProjection* MVP, sGCameraView* camera);
    void (*SetProjection)(sGProjection* MVP, sGCamera* camera);
    void (*SetMVP)(sGProjection* MVP);
    void (*MoveModel)(sGProjection* MVP, sGMoveModel* direction);
};
//===============================================
GProjectionO* GProjection_New();
void GProjection_Delete();
GProjectionO* GProjection();
//===============================================
#endif
//===============================================
