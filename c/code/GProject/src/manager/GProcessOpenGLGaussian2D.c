//===============================================
#include "GProcessOpenGLGaussian2D.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GFunction.h"
#include "GEvent.h"
#include "GConsole.h"
//===============================================
#define GDIRECTION_INIT (sGDirection){{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
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
	lChild->m_direction = GDIRECTION_INIT;
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
	GOpenGL()->MainLoop(lWindow);
}
//===============================================
static void GProcessOpenGLGaussian2D_Update(sGWindow sWindow) {
	GOpenGL()->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GOpenGL()->ClearColor(0.0, 0.0, 0.0, 1.0);
	GOpenGL()->ModelView();

	GProcessOpenGLGaussian2DO* lProcess = m_GProcessOpenGLGaussian2DO->m_child;
	sGDirection* lDirection = &lProcess->m_direction;
	sGGaussian2D* lGaussian2D = &lProcess->m_gaussian2D;

	GOpenGL()->Translate(lDirection->tra.x, lDirection->tra.y, lDirection->tra.z);
	GOpenGL()->Rotate(lDirection->rot.x, 1.0, 0.0, 0.0);
	GOpenGL()->Rotate(lDirection->rot.y, 0.0, 1.0, 0.0);
	GOpenGL()->Rotate(lDirection->rot.z, 0.0, 0.0, 1.0);

	sGEvent* lEvent = GEvent()->GetEvent();

	if(lEvent->frame.onFlag == TRUE) {
		lEvent->frame.onFlag = FALSE;
		GOpenGL()->Viewport(sWindow.name);
	}

	if(lEvent->key.onFlag == TRUE) {
		lEvent->key.onFlag = FALSE;
		//GConsole()->Print("[ KEY ] : %d\n", lEvent->key.key);

		if(lEvent->key.action == GLFW_PRESS) {
			switch(lEvent->key.key ) {
			// Rotation suivant -x
			case GLFW_KEY_UP:
				lDirection->rot.x -= 10.0;
				if(lDirection->rot.x <= -360.0) lDirection->rot.x = 0.0;
				break;
				// Rotation suivant +x
			case GLFW_KEY_DOWN:
				lDirection->rot.x += 10.0;
				if(lDirection->rot.x >= 360.0) lDirection->rot.x = 0.0;
				break;
				// Rotation suivant -y
			case GLFW_KEY_LEFT:
				lDirection->rot.y -= 10.0;
				if(lDirection->rot.y >= 360.0) lDirection->rot.y = 0.0;
				break;
				// Rotation suivant +y
			case GLFW_KEY_RIGHT:
				lDirection->rot.y += 10.0;
				if(lDirection->rot.y >= 360.0) lDirection->rot.y = 0.0;
				break;
				// Rotation suivant -z
			case GLFW_KEY_RIGHT_CONTROL:
				lDirection->rot.z -= 10.0;
				if(lDirection->rot.z >= 360.0) lDirection->rot.z = 0.0;
				break;
				// Rotation suivant +z
			case GLFW_KEY_RIGHT_ALT:
				lDirection->rot.z += 10.0;
				if(lDirection->rot.z >= 360.0) lDirection->rot.z = 0.0;
				break;
				// Translation suivant -x
			case GLFW_KEY_D:
				lDirection->tra.x -= 0.02;
				if(lDirection->tra.x <= -10.0) lDirection->tra.x = -10.0;
				break;
				// Translation suivant +x
			case GLFW_KEY_G:
				lDirection->tra.x += 0.02;
				if(lDirection->tra.x >= 10.0) lDirection->tra.x = 10.0;
				break;
				// Translation suivant -y
			case GLFW_KEY_V:
				lDirection->tra.y -= 0.02;
				if(lDirection->tra.y <= -10.0) lDirection->tra.y = -10.0;
				break;
				// Translation suivant +y
			case GLFW_KEY_R:
				lDirection->tra.y += 0.02;
				if(lDirection->tra.y >= 10.0) lDirection->tra.y = 10.0;
				break;
				// Translation suivant -z
			case GLFW_KEY_C:
				lDirection->tra.z -= 1.0;
				if(lDirection->tra.z <= -100.0) lDirection->tra.z = -100.0;
				break;
				// Translation suivant +z
			case GLFW_KEY_E:
				lDirection->tra.z += 1.0;
				if(lDirection->tra.z >= 100.0) lDirection->tra.z = 100.0;
				break;
				// Initialisation de la direction
			case GLFW_KEY_MENU:
				*lDirection = GDIRECTION_INIT;
				break;
				// Variation suivant -Sigma
			case GLFW_KEY_T:
				lGaussian2D->sigmaX -= 0.02;
				if(lGaussian2D->sigmaX <= -10.0) lGaussian2D->sigmaX = -10.0;
				lGaussian2D->sigmaY = lGaussian2D->sigmaX;
				break;
				// Variation suivant +Sigma
			case GLFW_KEY_B:
				lGaussian2D->sigmaX += 0.02;
				if(lGaussian2D->sigmaX >= 10.0) lGaussian2D->sigmaX = 10.0;
				lGaussian2D->sigmaY = lGaussian2D->sigmaX;
				break;
			}
		}
	}

	sGGrid lGrid = {
			5.0, 1.0, 1.0/10,
			1, {0.2, 0.2, 0.2, 1.0},
			5, {1.0, 1.0, 1.0, 1.0}
	};
	sGFunction2D lFunction = {
			-5.0, 5.0, -5.0, 5.0, 201, 201,
			{0.0, 0.5, 0.0, 1.0}, {0.5, 0.0, 0.0, 1.0},
			10, 2, GFunction()->Gaussian2D, lGaussian2D, 0,
			lGrid.gridDiv, 4.0/1.0, 4.0/1.0, 1.0
	};

	GOpenGL()->DrawGrid(lGrid);
	GOpenGL()->DrawFunctionHeatMap(&lFunction);
}
//===============================================
