//===============================================
#include "GGLew.h"
#include "GConsole.h"
//===============================================
static GGLewO* m_GGLewO = 0;
//===============================================
static void GGLew_Experimental(int flag);
static void GGLew_Init();
//===============================================
GGLewO* GGLew_New() {
	GGLewO* lObj = (GGLewO*)malloc(sizeof(GGLewO));
	lObj->Delete = GGLew_Delete;
	lObj->Experimental = GGLew_Experimental;
	lObj->Init = GGLew_Init;
	return lObj;
}
//===============================================
void GGLew_Delete() {
	GGLewO* lObj = GGLew();
	if(lObj != 0) {
		free(lObj);
	}
	m_GGLewO = 0;
}
//===============================================
GGLewO* GGLew() {
	if(m_GGLewO == 0) {
		m_GGLewO = GGLew_New();
	}
	return m_GGLewO;
}
//===============================================
static void GGLew_Experimental(int flag) {
	glewExperimental = flag;
}
//===============================================
static void GGLew_Init() {
	int lRes = glewInit();
	if(lRes != GLEW_OK) {GConsole()->Print("Error GGLew_Init\n"); exit(0);}
}
//===============================================
