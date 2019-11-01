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
//===============================================
static void GProcessOpenGLGaussian2D_Update(sGWindow* sWindow);
//===============================================
GProcessO* GProcessOpenGLGaussian2D_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLGaussian2DO* lChild = (GProcessOpenGLGaussian2DO*)malloc(sizeof(GProcessOpenGLGaussian2DO));

	lChild->m_parent = lParent;
	lChild->m_gaussian2D = (sGGaussian2D){1.0, 1.0, 0.0, 0.0};

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
	GOpenGL()->MainLoop(&lWindow);
}
//===============================================
static void GProcessOpenGLGaussian2D_Update(sGWindow* sWindow) {
	GOpenGL()->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GOpenGL()->ClearColor(0.0, 0.0, 0.0, 1.0);
	GOpenGL()->ModelView();

	GProcessOpenGLGaussian2DO* lProcess = m_GProcessOpenGLGaussian2DO->m_child;
	sGGaussian2D* lGaussian2D = &lProcess->m_gaussian2D;
	sGEvent* lEvent = GEvent()->GetEvent();
	sGDirection* lDirection = GOpenGL()->GetDirection();

	GOpenGL()->InitDirection();

	if(lEvent->frame.onFlag == TRUE) {
		sGCamera lCamera = {45.0, 0.1, 100.0};
		GOpenGL()->Viewport(sWindow->name);
		GOpenGL()->Projection();
		GOpenGL()->Frustum(sWindow->name, lCamera);
	}

	if(lEvent->key.onFlag == TRUE) {
		//GConsole()->Print("[ KEY ] : %d\n", lEvent->key.key);

		if(lEvent->key.action == GLFW_PRESS) {
			switch(lEvent->key.key ) {
				// Variation suivant -Sigma
			case GLFW_KEY_Y:
				lGaussian2D->sigmaX -= 0.05;
				if(lGaussian2D->sigmaX <= 0.01) lGaussian2D->sigmaX = 0.01;
				lGaussian2D->sigmaY = lGaussian2D->sigmaX;
				break;
				// Variation suivant +Sigma
			case GLFW_KEY_B:
				lGaussian2D->sigmaX += 0.05;
				if(lGaussian2D->sigmaX >= 2.0) lGaussian2D->sigmaX = 2.0;
				lGaussian2D->sigmaY = lGaussian2D->sigmaX;
				break;
			}
		}
	}

	sGGrid lGrid = {
			5.0, 1.0, 1.0/10,
			1, {0.2, 0.2, 0.2, 1.0},
			2, {0.2, 0.2, 0.9, 1.0}
	};
	sGFunction2D lFunction = {
			-5.0, 5.0, -5.0, 5.0, 151, 151, 0.5,
			{0.0, 0.5, 0.0, 1.0}, {0.5, 0.0, 0.0, 1.0},
			10, 2, GFunction()->Gaussian2D, lGaussian2D, 0,
			lGrid.gridDiv, lDirection->div.x, lDirection->div.y, lDirection->div.z
	};

	GOpenGL()->DrawFunctionHeatMap(&lFunction);
	GOpenGL()->DrawGrid(lGrid);
	GOpenGL()->DrawOrigin();
}
//===============================================
