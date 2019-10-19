//===============================================
#include "GProcessOpenGLPoint.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLPointO = 0;
//===============================================
static void GProcessOpenGLPoint_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenGLPoint_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLPointO* lChild = (GProcessOpenGLPointO*)malloc(sizeof(GProcessOpenGLPointO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLPoint_Delete;
	lParent->Run = GProcessOpenGLPoint_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLPoint_Delete() {
	GProcess_Delete(m_GProcessOpenGLPointO);
	m_GProcessOpenGLPointO = 0;
}
//===============================================
GProcessO* GProcessOpenGLPoint() {
	if(m_GProcessOpenGLPointO == 0) {
		m_GProcessOpenGLPointO = GProcessOpenGLPoint_New();
	}
	return m_GProcessOpenGLPointO;
}
//===============================================
static void GProcessOpenGLPoint_Run(int argc, char** argv) {
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
		GOpenGL()->Projection("WINDOW");
		GOpenGL()->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		sGGrid lGrid = {
				5.0, 1.0, 1.0/10,
				1, {0.2, 0.2, 0.2, 1.0},
				2, {0.2, 0.2, 0.9, 1.0}
		};
		sGPoint lPoint = {
				{1.0, 1.0, 0.0},
				{0.5, 0.0, 0.0, 1.0},
				10, lGrid.gridDiv,
				4.0/1, 4.0/1, 0.0
		};
		GOpenGL()->DrawGrid(lGrid);
		GOpenGL()->DrawPoint(lPoint);
		GGLFW()->SwapBuffers("WINDOW");
		GGLFW()->PollEvents();
	}
	GGLFW()->DestroyWindow("WINDOW");
	GGLFW()->Terminate();
}
//===============================================
