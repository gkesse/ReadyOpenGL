//===============================================
#ifndef _GCamera_
#define _GCamera_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GCameraO GCameraO;
//===============================================
struct _GCameraO {
    void (*Delete)();
    void (*SetRatio)(char* windowName, sGCamera* camera);
    void (*UpdateRatio)(sGCamera* camera);
    void (*SetCenter)(sGCameraView* camera);
};
//===============================================
GCameraO* GCamera_New();
void GCamera_Delete();
GCameraO* GCamera();
//===============================================
#endif
//===============================================
