//===============================================
#include "GProcessOpenGLGaussian.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GFunction.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLGaussianO = 0;
//===============================================
static void GProcessOpenGLGaussian_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenGLGaussian_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLGaussianO* lChild = (GProcessOpenGLGaussianO*)malloc(sizeof(GProcessOpenGLGaussianO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLGaussian_Delete;
	lParent->Run = GProcessOpenGLGaussian_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLGaussian_Delete() {
	GProcess_Delete(m_GProcessOpenGLGaussianO);
	m_GProcessOpenGLGaussianO = 0;
}
//===============================================
GProcessO* GProcessOpenGLGaussian() {
	if(m_GProcessOpenGLGaussianO == 0) {
		m_GProcessOpenGLGaussianO = GProcessOpenGLGaussian_New();
	}
	return m_GProcessOpenGLGaussianO;
}
//===============================================
static void GProcessOpenGLGaussian_Run(int argc, char** argv) {
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
		sGGaussian lGaussian = {
				1.0, 0.0
		};
		sGFunction lFunction = {
				-15.0, 15.0, 81,
				{0.0, 0.5, 0.0, 1.0}, {0.5, 0.0, 0.0, 1.0},
				10, 2, GFunction()->Gaussian, &lGaussian, 0,
				lGrid.gridDiv, 10.0/4.0, 8.0/0.4, 0.0
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
