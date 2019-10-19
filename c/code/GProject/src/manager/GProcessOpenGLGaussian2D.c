//===============================================
#include "GProcessOpenGLGaussian2D.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GFunction.h"
#include "GEvent.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLGaussian2DO = 0;
//===============================================
static void GProcessOpenGLGaussian2D_Run(int argc, char** argv);
static void GProcessOpenGLGaussian2D_Update(sGWindow sWindow);
//===============================================
GProcessO* GProcessOpenGLGaussian2D_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLGaussian2DO* lChild = (GProcessOpenGLGaussian2DO*)malloc(sizeof(GProcessOpenGLGaussian2DO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLGaussian2D_Delete;
	lParent->Run = GProcessOpenGLGaussian2D_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLGaussian2D_Delete() {
	GProcess_Delete(m_GProcessOpenGLGaussian2DO);
	m_GProcessOpenGLGaussian2DO = 0;
}
//===============================================
GProcessO* GProcessOpenGLGaussian2D() {
	if(m_GProcessOpenGLGaussian2DO == 0) {
		m_GProcessOpenGLGaussian2DO = GProcessOpenGLGaussian2D_New();
	}
	return m_GProcessOpenGLGaussian2DO;
}
//===============================================
static void GProcessOpenGLGaussian2D_Run(int argc, char** argv) {
	sGWindow lWindow = {
			"WINDOW",
			"OpenGL | ReadyDev",
			400, 400,
			GProcessOpenGLGaussian2D_Update
	};
	GOpenGL()->MainLoop(lWindow);
}
//===============================================
static void GProcessOpenGLGaussian2D_Update(sGWindow sWindow) {
	GOpenGL()->Viewport(sWindow.name);
	GOpenGL()->Clear(GL_COLOR_BUFFER_BIT);
	GOpenGL()->Projection(sWindow.name);
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
			-5.0, 5.0, -5.0, 5.0, 201, 201,
			{0.0, 0.5, 0.0, 1.0}, {0.5, 0.0, 0.0, 1.0},
			10, 2, GFunction()->Gaussian2D, &lGaussian2D, 0,
			lGrid.gridDiv, 4.0/1.0, 4.0/1.0, 1.0
	};

	sGEvent lEvent = GEvent()->GetEvent();

	GConsole()->Print("lEvent : %.2f %.2f\n", lEvent.cursor.x, lEvent.cursor.y);

	GOpenGL()->DrawGrid(lGrid);
	GOpenGL()->DrawFunctionHeatMap(&lFunction);
}
//===============================================
