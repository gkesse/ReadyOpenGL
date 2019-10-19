//===============================================
#include "GProcessOpenGLEcgData.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GData.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLEcgDataO = 0;
//===============================================
static void GProcessOpenGLEcgData_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenGLEcgData_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLEcgDataO* lChild = (GProcessOpenGLEcgDataO*)malloc(sizeof(GProcessOpenGLEcgDataO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLEcgData_Delete;
	lParent->Run = GProcessOpenGLEcgData_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLEcgData_Delete() {
	GProcess_Delete(m_GProcessOpenGLEcgDataO);
	m_GProcessOpenGLEcgDataO = 0;
}
//===============================================
GProcessO* GProcessOpenGLEcgData() {
	if(m_GProcessOpenGLEcgDataO == 0) {
		m_GProcessOpenGLEcgDataO = GProcessOpenGLEcgData_New();
	}
	return m_GProcessOpenGLEcgDataO;
}
//===============================================
static void GProcessOpenGLEcgData_Run(int argc, char** argv) {
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

		double lRatio = GGLFW()->Ratio("WINDOW");
		double lWidth = lRatio/lGrid.gridDiv;

		sGDataTab lDataTab = {
				GDATA_ECG, 1024, -lWidth, lWidth, 0.3,
				{0.0, 0.5, 0.0, 1.0}, {0.5, 0.0, 0.0, 1.0},
				10, 2,
				lGrid.gridDiv, 1.0, 1/0.1, 0.0
		};
		GOpenGL()->DrawGrid(lGrid);
		GOpenGL()->DrawDataTab(lDataTab);
		GGLFW()->SwapBuffers("WINDOW");
		GGLFW()->PollEvents();
	}
	GGLFW()->DestroyWindow("WINDOW");
	GGLFW()->Terminate();
}
//===============================================
