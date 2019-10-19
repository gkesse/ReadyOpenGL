//===============================================
#include "GProcessOpenGLSinus.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GFunction.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLSinusO = 0;
//===============================================
static void GProcessOpenGLSinus_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenGLSinus_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLSinusO* lChild = (GProcessOpenGLSinusO*)malloc(sizeof(GProcessOpenGLSinusO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLSinus_Delete;
	lParent->Run = GProcessOpenGLSinus_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLSinus_Delete() {
	GProcess_Delete(m_GProcessOpenGLSinusO);
	m_GProcessOpenGLSinusO = 0;
}
//===============================================
GProcessO* GProcessOpenGLSinus() {
	if(m_GProcessOpenGLSinusO == 0) {
		m_GProcessOpenGLSinusO = GProcessOpenGLSinus_New();
	}
	return m_GProcessOpenGLSinusO;
}
//===============================================
static void GProcessOpenGLSinus_Run(int argc, char** argv) {
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
		sGSinus lSinus = {
				5.0, 50.0, 0.0
		};
		sGFunction lFunction = {
				-3*0.02, 3*0.02, 151,
				{0.0, 0.5, 0.0, 1.0}, {0.5, 0.0, 0.0, 1.0},
				10, 2, GFunction()->Sinus, &lSinus, 0,
				lGrid.gridDiv, 8.0/0.02, 8.0/5, 0.0
		};
		GOpenGL()->DrawGrid(lGrid);
		GOpenGL()->DrawFunction(&lFunction);
		GGLFW()->SwapBuffers("WINDOW");
		GGLFW()->PollEvents();
	}
	GGLFW()->DestroyWindow("WINDOW");
	GGLFW()->Terminate();
}
//===============================================
