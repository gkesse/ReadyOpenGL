//===============================================
#include "GProjection.h"
#include "GGLFW.h"
#include "GConsole.h"
//===============================================
static GProjectionO* m_GProjectionO = 0;
//===============================================
static void GProjection_SetModel(sGProjection* MVP, mat4 data);
static void GProjection_SetView(sGProjection* MVP, sGCameraView* camera);
static void GProjection_SetProjection(sGProjection* MVP, sGCamera* camera);
static void GProjection_RotateModel(sGProjection* MVP, double angle, vec3 vecUp);
static void GProjection_SetMVP(sGProjection* MVP);
//===============================================
GProjectionO* GProjection_New() {
	GProjectionO* lObj = (GProjectionO*)malloc(sizeof(GProjectionO));
	lObj->Delete = GProjection_Delete;
	lObj->SetModel = GProjection_SetModel;
	lObj->SetView = GProjection_SetView;
	lObj->SetProjection = GProjection_SetProjection;
	lObj->RotateModel = GProjection_RotateModel;
	lObj->SetMVP = GProjection_SetMVP;
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
static void GProjection_SetModel(sGProjection* MVP, mat4 data) {
	glm_mat4_copy(data, MVP->model);
}
//===============================================
static void GProjection_SetProjection(sGProjection* MVP, sGCamera* camera) {
	double lFovY = glm_rad(camera->fovY);
	double lRatio = camera->ratio;
	double lzNear = camera->zNear;
	double lzFar = camera->zFar;
	glm_perspective(lFovY, lRatio, lzNear, lzFar, MVP->projection);
}
//===============================================
static void GProjection_SetView(sGProjection* MVP, sGCameraView* camera) {
	glm_lookat(camera->position, camera->center, camera->up, MVP->view);
}
//===============================================
static void GProjection_RotateModel(sGProjection* MVP, double angle, vec3 vecUp) {
	double lAngle = glm_rad(angle);
	glm_rotate(MVP->model, lAngle, vecUp);
}
//===============================================
static void GProjection_SetMVP(sGProjection* MVP) {
	glm_mat4_mul(MVP->projection, MVP->view, MVP->mvp);
	glm_mat4_mul(MVP->mvp, MVP->model, MVP->mvp);
}
//===============================================
