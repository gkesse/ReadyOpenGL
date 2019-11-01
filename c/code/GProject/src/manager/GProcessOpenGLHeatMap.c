//===============================================
#include "GProcessOpenGLHeatMap.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GFunction.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLHeatMapO = 0;
//===============================================
static void GProcessOpenGLHeatMap_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenGLHeatMap_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLHeatMapO* lChild = (GProcessOpenGLHeatMapO*)malloc(sizeof(GProcessOpenGLHeatMapO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLHeatMap_Delete;
	lParent->Run = GProcessOpenGLHeatMap_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLHeatMap_Delete() {
	GProcess_Delete(m_GProcessOpenGLHeatMapO);
	m_GProcessOpenGLHeatMapO = 0;
}
//===============================================
GProcessO* GProcessOpenGLHeatMap() {
	if(m_GProcessOpenGLHeatMapO == 0) {
		m_GProcessOpenGLHeatMapO = GProcessOpenGLHeatMap_New();
	}
	return m_GProcessOpenGLHeatMapO;
}
//===============================================
static void GProcessOpenGLHeatMap_Run(int argc, char** argv) {
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
		sGGaussian2D lGaussian2D = {
				1.0, 1.0, 0.0, 0.0
		};
		sGFunction2D lFunction = {
				-5.0, 5.0, -5.0, 5.0, 401, 401, 0.5,
				{0.0, 0.5, 0.0, 1.0}, {0.5, 0.0, 0.0, 1.0},
				10, 2, GFunction()->Gaussian2D, &lGaussian2D, 0,
				lGrid.gridDiv, 4.0/1.0, 4.0/1.0, 1.0
		};
		GOpenGL()->DrawGrid(lGrid);
		GOpenGL()->DrawFunctionHeatMap(&lFunction);
		GGLFW()->SwapBuffers("WINDOW");
		GGLFW()->PollEvents();
	}
	GGLFW()->DestroyWindow("WINDOW");
	GGLFW()->Terminate();
}
//===============================================
