//===============================================
#include "GProcessOpenGLLine.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLLineO = 0;
//===============================================
static void GProcessOpenGLLine_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenGLLine_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLLineO* lChild = (GProcessOpenGLLineO*)malloc(sizeof(GProcessOpenGLLineO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLLine_Delete;
	lParent->Run = GProcessOpenGLLine_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLLine_Delete() {
	GProcess_Delete(m_GProcessOpenGLLineO);
	m_GProcessOpenGLLineO = 0;
}
//===============================================
GProcessO* GProcessOpenGLLine() {
	if(m_GProcessOpenGLLineO == 0) {
		m_GProcessOpenGLLineO = GProcessOpenGLLine_New();
	}
	return m_GProcessOpenGLLineO;
}
//===============================================
static void GProcessOpenGLLine_Run(int argc, char** argv) {
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
		sGLine lLine = {
				{{-2.0, -2.0, 0.0}, {2.0, 2.0, 0.0}},
				{0.5, 0.0, 0.0, 1.0},
				2, lGrid.gridDiv,
				4.0/1, 4.0/1, 0.0
		};
		GOpenGL()->DrawGrid(lGrid);
		GOpenGL()->DrawLine(lLine);
		GGLFW()->SwapBuffers("WINDOW");
		GGLFW()->PollEvents();
	}
	GGLFW()->DestroyWindow("WINDOW");
	GGLFW()->Terminate();
}
//===============================================
