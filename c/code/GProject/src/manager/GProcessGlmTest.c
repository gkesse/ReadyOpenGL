//===============================================
#include "GProcessGlmTest.h"
#include "GGlm.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessGlmTestO = 0;
//===============================================
static void GProcessGlmTest_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessGlmTest_New() {
	GProcessO* lParent = GProcess_New();
	GProcessGlmTestO* lChild = (GProcessGlmTestO*)malloc(sizeof(GProcessGlmTestO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessGlmTest_Delete;
	lParent->Run = GProcessGlmTest_Run;
	return lParent;
}
//===============================================
void GProcessGlmTest_Delete() {
	GProcess_Delete(m_GProcessGlmTestO);
	m_GProcessGlmTestO = 0;
}
//===============================================
GProcessO* GProcessGlmTest() {
	if(m_GProcessGlmTestO == 0) {
		m_GProcessGlmTestO = GProcessGlmTest_New();
	}
	return m_GProcessGlmTestO;
}
//===============================================
static void GProcessGlmTest_Run(int argc, char** argv) {
	vec3 v1 = {1, 2, 3};

	mat4 m1 = {
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	GGlm()->ShowVec3(v1);
	GGlm()->ShowMat4(m1);
	GGlm()->RotateMatrix(m1, 90, GLM_ZUP);
	GGlm()->ShowMat4(m1);
}
//===============================================
