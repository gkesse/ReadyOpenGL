//===============================================
#include "GGlm.h"
#include "GConsole.h"
//===============================================
static GGlmO* m_GGlmO = 0;
//===============================================
static void GGlm_ShowVec3(vec3 v1);
static void GGlm_ShowMat4(mat4 m1);
static void GGlm_RotateMatrix(mat4 m1, double angle, vec3 axis);
//===============================================
GGlmO* GGlm_New() {
	GGlmO* lObj = (GGlmO*)malloc(sizeof(GGlmO));
	lObj->Delete = GGlm_Delete;
	lObj->ShowVec3 = GGlm_ShowVec3;
	lObj->ShowMat4 = GGlm_ShowMat4;
	lObj->RotateMatrix = GGlm_RotateMatrix;
	return lObj;
}
//===============================================
void GGlm_Delete() {
	GGlmO* lObj = GGlm();
	if(lObj != 0) {
		free(lObj);
	}
	m_GGlmO = 0;
}
//===============================================
GGlmO* GGlm() {
	if(m_GGlmO == 0) {
		m_GGlmO = GGlm_New();
	}
	return m_GGlmO;
}
//===============================================
static void GGlm_ShowVec3(vec3 v1) {
	for(int i = 0; i < 3; i++) {
		if(i != 0) GConsole()->Print(" | ");
		GConsole()->Print("%10.2f", v1[1]);
	}
	GConsole()->Print("\n\n");
}
//===============================================
static void GGlm_ShowMat4(mat4 m1) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(j != 0) GConsole()->Print(" | ");
			GConsole()->Print("%10.2f", m1[i][j]);
		}
		GConsole()->Print("\n");
	}
	GConsole()->Print("\n");
}
//===============================================
static void GGlm_RotateMatrix(mat4 m1, double angle, vec3 axis) {
	double lRad = (angle*GLM_PI)/180.0;
	glmc_rotate_make(m1, lRad, axis);
}
//===============================================
