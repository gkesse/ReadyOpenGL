//===============================================
#include "GProcessOpenGLGrid.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLGridO = 0;
//===============================================
static void GProcessOpenGLGrid_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenGLGrid_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLGridO* lChild = (GProcessOpenGLGridO*)malloc(sizeof(GProcessOpenGLGridO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLGrid_Delete;
	lParent->Run = GProcessOpenGLGrid_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLGrid_Delete() {
	GProcess_Delete(m_GProcessOpenGLGridO);
	m_GProcessOpenGLGridO = 0;
}
//===============================================
GProcessO* GProcessOpenGLGrid() {
	if(m_GProcessOpenGLGridO == 0) {
		m_GProcessOpenGLGridO = GProcessOpenGLGrid_New();
	}
	return m_GProcessOpenGLGridO;
}
//===============================================
static void GProcessOpenGLGrid_Run(int argc, char** argv) {
	GGLFW()->Init();
	GGLFW()->CreateWindow("WINDOW", 400, 400, "OpenGL | ReadyDev");
	GGLFW()->MakeContext("WINDOW");
	GOpenGL()->Enable(GL_LINE_SMOOTH);
	GOpenGL()->Hint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	GOpenGL()->Enable(GL_POINT_SMOOTH);
	GOpenGL()->Hint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	GOpenGL()->Enable(GL_BLEND);
	GOpenGL()->BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	while(1) {
		int lRes = GGLFW()->WindowClose("WINDOW");
		if(lRes == 1) break;
		GOpenGL()->Viewport("WINDOW");
		GOpenGL()->Clear(GL_COLOR_BUFFER_BIT);
		GOpenGL()->Projection();
		GOpenGL()->Ortho("WINDOW");
		GOpenGL()->ModelView();
		GOpenGL()->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		sGGrid lGrid = {
				5.0, 1.0, 1.0/10,
				1, {0.2, 0.2, 0.2, 1.0},
				2, {0.2, 0.2, 0.9, 1.0}
		};
		GOpenGL()->DrawGrid(lGrid);
		GGLFW()->SwapBuffers("WINDOW");
		GGLFW()->PollEvents();
	}
	GGLFW()->DestroyWindow("WINDOW");
	GGLFW()->Terminate();
}
//===============================================
