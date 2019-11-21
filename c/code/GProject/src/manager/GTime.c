//===============================================
#include "GTime.h"
#include "GConsole.h"
//===============================================
static GTimeO* m_GTimeO = 0;
//===============================================
static void GTime_InitLastTime(GTimeO* obj);
static void GTime_SetCurrentTime();
static void GTime_SetDiffTime();
static double GTime_GetDiffTime();
//===============================================
GTimeO* GTime_New() {
	GTimeO* lObj = (GTimeO*)malloc(sizeof(GTimeO));

	GTime_InitLastTime(lObj);

	lObj->GetDiffTime = GTime_GetDiffTime;
	return lObj;
}
//===============================================
void GTime_Delete() {
	GTimeO* lObj = GTime();
	if(lObj != 0) {
		free(lObj);
	}
	m_GTimeO = 0;
}
//===============================================
GTimeO* GTime() {
	if(m_GTimeO == 0) {
		m_GTimeO = GTime_New();
	}
	return m_GTimeO;
}
//===============================================
static void GTime_InitLastTime(GTimeO* obj) {
	sGTime* lTime = &obj->m_time;
	lTime->lastTime = glfwGetTime();
}
//===============================================
static void GTime_SetCurrentTime() {
	sGTime* lTime = &m_GTimeO->m_time;
	lTime->currentTime = glfwGetTime();
}
//===============================================
static void GTime_SetDiffTime() {
	sGTime* lTime = &m_GTimeO->m_time;
	GTime_SetCurrentTime();
	lTime->diffTime = lTime->currentTime - lTime->lastTime;
}
//===============================================
static double GTime_GetDiffTime() {
	sGTime* lTime = &m_GTimeO->m_time;
	GTime_SetDiffTime();
	return lTime->diffTime;
}
//===============================================
