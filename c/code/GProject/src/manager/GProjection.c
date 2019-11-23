//===============================================
#include "GProjection.h"
#include "GGLFW.h"
#include "GGlm.h"
#include "GEvent.h"
#include "GConsole.h"
//===============================================
static GProjectionO* m_GProjectionO = 0;
//===============================================
static void GProjection_SetModel(sGProjection* MVP, mat4 data);
static void GProjection_InitModel(sGProjection* MVP);
static void GProjection_MoveModel(sGProjection* MVP, sGMoveModel* direction);
static void GProjection_UpdateModel(sGProjection* MVP, sGMoveModel* direction);
static void GProjection_SetView(sGProjection* MVP, sGCameraView* camera);
static void GProjection_SetProjection(sGProjection* MVP, sGCamera* camera);
static void GProjection_SetMVP(sGProjection* MVP);
//===============================================
GProjectionO* GProjection_New() {
	GProjectionO* lObj = (GProjectionO*)malloc(sizeof(GProjectionO));
	lObj->Delete = GProjection_Delete;
	lObj->SetModel = GProjection_SetModel;
	lObj->InitModel = GProjection_InitModel;
	lObj->MoveModel = GProjection_MoveModel;
	lObj->UpdateModel = GProjection_UpdateModel;
	lObj->SetView = GProjection_SetView;
	lObj->SetProjection = GProjection_SetProjection;
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
static void GProjection_InitModel(sGProjection* MVP) {
	GProjection()->SetModel(MVP, GLM_MAT4_IDENTITY);
}
//===============================================
static void GProjection_MoveModel(sGProjection* MVP, sGMoveModel* direction) {
	sGEvent* lEvent = GEvent()->GetEvent();

	if(lEvent->key.onFlag == TRUE) {
		//GConsole()->Print("[ KEY ] : %d\n", lEvent->key.key);

		if(lEvent->key.action == GLFW_PRESS) {
			switch(lEvent->key.key ) {
			// Rotation suivant -x
			case GLFW_KEY_UP:
				direction->rotate[0] -= 10.0;
				if(direction->rotate[0] <= -360.0) direction->rotate[0] = 0.0;
				break;
				// Rotation suivant +x
			case GLFW_KEY_DOWN:
				direction->rotate[0] += 10.0;
				if(direction->rotate[0] >= 360.0) direction->rotate[0] = 0.0;
				break;
				// Rotation suivant -y
			case GLFW_KEY_LEFT:
				direction->rotate[1] -= 10.0;
				if(direction->rotate[1] <= -360.0) direction->rotate[1] = 0.0;
				break;
				// Rotation suivant +y
			case GLFW_KEY_RIGHT:
				direction->rotate[1] += 10.0;
				if(direction->rotate[1] >= 360.0) direction->rotate[1] = 0.0;
				break;
				// Rotation suivant -z
			case GLFW_KEY_RIGHT_ALT:
				direction->rotate[2] -= 10.0;
				if(direction->rotate[2] <= -360.0) direction->rotate[2] = 0.0;
				break;
				// Rotation suivant +z
			case GLFW_KEY_RIGHT_CONTROL:
				direction->rotate[2] += 10.0;
				if(direction->rotate[2] >= 360.0) direction->rotate[2] = 0.0;
				break;
				// Translation suivant -x
			case GLFW_KEY_A:
				direction->translate[0] -= 0.02;
				if(direction->translate[0] <= -10.0) direction->translate[0] = -10.0;
				break;
				// Translation suivant +x
			case GLFW_KEY_S:
				direction->translate[0] += 0.02;
				if(direction->translate[0] >= 10.0) direction->translate[0] = 10.0;
				break;
				// Translation suivant -y
			case GLFW_KEY_Z:
				direction->translate[1] -= 0.02;
				if(direction->translate[1] <= -10.0) direction->translate[1] = -10.0;
				break;
				// Translation suivant +y
			case GLFW_KEY_W:
				direction->translate[1] += 0.02;
				if(direction->translate[1] >= 10.0) direction->translate[1] = 10.0;
				break;
				// Translation suivant -z
			case GLFW_KEY_X:
				direction->translate[2] -= 0.02;
				if(direction->translate[2] <= -100.0) direction->translate[2] = -100.0;
				break;
				// Translation suivant +z
			case GLFW_KEY_Q:
				direction->translate[2] += 0.02;
				if(direction->translate[2] >= 100.0) direction->translate[2] = 100.0;
				break;
			}
			GConsole()->Print("//===============================================\n");
			GConsole()->Print("// Direction\n");
			GConsole()->Print("//===============================================\n");
			GConsole()->Print("Rotation......[x, y, z] : [%.2lf , %.2lf , %.2lf]\n",
					direction->rotate[0],
					direction->rotate[1],
					direction->rotate[2]);
			GConsole()->Print("Translation...[x, y, z] : [%.2lf , %.2lf , %.2lf]\n",
					direction->translate[0],
					direction->translate[1],
					direction->translate[2]);
		}
	}
}
//===============================================
static void GProjection_UpdateModel(sGProjection* MVP, sGMoveModel* direction) {
	glm_translate(MVP->model, direction->translate);
	vec3 lAngle;
	GGlm()->RadVec3(direction->rotate, lAngle);
	glm_rotate(MVP->model, lAngle[0], GLM_XUP);
	glm_rotate(MVP->model, lAngle[1], GLM_YUP);
	glm_rotate(MVP->model, lAngle[2], GLM_ZUP);
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
static void GProjection_SetMVP(sGProjection* MVP) {
	glm_mat4_mul(MVP->projection, MVP->view, MVP->mvp);
	glm_mat4_mul(MVP->mvp, MVP->model, MVP->mvp);
}
//===============================================
