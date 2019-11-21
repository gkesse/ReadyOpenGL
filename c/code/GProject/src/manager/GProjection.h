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
    void (*SetModel)(mat4 data);
    void (*SetView)(sGCameraView* camera);
    void (*SetProjection)(char* windowName, sGCamera* camera);
    void (*RotateModel)(double angle, vec3 vecUp);
    void (*GetMVP)(mat4 mvp);
    sGProjection m_projection;
};
//===============================================
GProjectionO* GProjection_New();
void GProjection_Delete();
GProjectionO* GProjection();
//===============================================
#endif
//===============================================
