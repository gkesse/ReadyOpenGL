//===============================================
#include "GCamera.h"
#include "GGLFW.h"
//===============================================
static GCameraO* m_GCameraO = 0;
//===============================================
static void GCamera_SetRatio(char* windowName, sGCamera* camera);
static void GCamera_SetCenter(sGCameraView* camera);
//===============================================
GCameraO* GCamera_New() {
    GCameraO* lObj = (GCameraO*)malloc(sizeof(GCameraO));
    lObj->Delete = GCamera_Delete;
    lObj->SetRatio = GCamera_SetRatio;
    lObj->SetCenter = GCamera_SetCenter;
    return lObj;
}
//===============================================
void GCamera_Delete() {
    GCameraO* lObj = GCamera();
    if(lObj != 0) {
        free(lObj);
    }
    m_GCameraO = 0;
}
//===============================================
GCameraO* GCamera() {
    if(m_GCameraO == 0) {
        m_GCameraO = GCamera_New();
    }
    return m_GCameraO;
}
//===============================================
static void GCamera_SetRatio(char* windowName, sGCamera* camera) {
	int lWidth;
	int lHeight;
	GGLFW()->FrameSize(windowName, &lWidth, &lHeight);
	double lRatio = (double)lWidth/lHeight;
	camera->ratio = lRatio;
}
//===============================================
static void GCamera_SetCenter(sGCameraView* camera) {
	glm_vec3_add(camera->position, camera->direction, camera->center);
}
//===============================================
