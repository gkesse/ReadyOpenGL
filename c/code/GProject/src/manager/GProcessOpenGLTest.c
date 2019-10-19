//===============================================
#include "GProcessOpenGLTest.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLTestO = 0;
//===============================================
static void GProcessOpenGLTest_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenGLTest_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLTestO* lChild = (GProcessOpenGLTestO*)malloc(sizeof(GProcessOpenGLTestO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLTest_Delete;
	lParent->Run = GProcessOpenGLTest_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLTest_Delete() {
	GProcess_Delete(m_GProcessOpenGLTestO);
	m_GProcessOpenGLTestO = 0;
}
//===============================================
GProcessO* GProcessOpenGLTest() {
	if(m_GProcessOpenGLTestO == 0) {
		m_GProcessOpenGLTestO = GProcessOpenGLTest_New();
	}
	return m_GProcessOpenGLTestO;
}
//===============================================
static void GProcessOpenGLTest_Run(int argc, char** argv) {

}
//===============================================
