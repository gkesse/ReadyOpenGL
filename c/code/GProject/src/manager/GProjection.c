//===============================================
#include "GProjection.h"
#include "GGLFW.h"
#include "GConsole.h"
//===============================================
static GProjectionO* m_GProjectionO = 0;
//===============================================
static void GProjection_SetModel(mat4 data);
static void GProjection_SetView(sGCameraView* camera);
static void GProjection_SetProjection(char* windowName, sGCamera* camera);
static void GProjection_RotateModel(double angle, vec3 vecUp);
static void GProjection_GetMVP(mat4 mvp);
//===============================================
GProjectionO* GProjection_New() {
	GProjectionO* lObj = (GProjectionO*)malloc(sizeof(GProjectionO));
	lObj->Delete = GProjection_Delete;
	lObj->SetModel = GProjection_SetModel;
	lObj->SetView = GProjection_SetView;
	lObj->SetProjection = GProjection_SetProjection;
	lObj->RotateModel = GProjection_RotateModel;
	lObj->GetMVP = GProjection_GetMVP;
	return lObj;
}
//===============================================
void GProjection_Delete() {
	GProjectionO* lObj = GProjection();
	if(lObj != 0) {
		free(lObj);
	}
	m_GProjectionO = 0;
}
//===============================================
GProjectionO* GProjection() {
	if(m_GProjectionO == 0) {
		m_GProjectionO = GProjection_New();
	}
	return m_GProjectionO;
}
//===============================================
static void GProjection_SetModel(mat4 data) {
	sGProjection* lProjection = &m_GProjectionO->m_projection;
	glm_mat4_copy(data, lProjection->model);
}
//===============================================
static void GProjection_SetProjection(char* windowName, sGCamera* camera) {
	sGProjection* lProjection = &m_GProjectionO->m_projection;
	int lWidth;
	int lHeight;
	GGLFW()->FrameSize(windowName, &lWidth, &lHeight);
	double lRatio = (double)lWidth/lHeight;
	double lFovY = glm_rad(camera->fovY);
	glm_perspective(lFovY, lRatio, camera->zNear, camera->zFar, lProjection->projection);
}
//===============================================
static void GProjection_SetView(sGCameraView* camera) {
	sGProjection* lProjection = &m_GProjectionO->m_projection;
	glm_lookat(camera->eye, camera->center, camera->up, lProjection->view);
}
//===============================================
static void GProjection_RotateModel(double angle, vec3 vecUp) {
	sGProjection* lProjection = &m_GProjectionO->m_projection;
	double lAngle = glm_rad(angle);
	glm_rotate(lProjection->model, lAngle, vecUp);
}
//===============================================
static void GProjection_GetMVP(mat4 mvp) {
	sGProjection* lProjection = &m_GProjectionO->m_projection;
	glm_mat4_mul(lProjection->projection, lProjection->view, mvp);
	glm_mat4_mul(mvp, lProjection->model, mvp);
}
//===============================================
