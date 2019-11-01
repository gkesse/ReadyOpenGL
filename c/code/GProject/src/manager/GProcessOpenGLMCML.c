//===============================================
#include "GProcessOpenGLMCML.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GFunction.h"
#include "GEvent.h"
#include "GMcml.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLMCMLO = 0;
//===============================================
static void GProcessOpenGLMCML_Run(int argc, char** argv);
static void GProcessOpenGLMCML_Update(sGWindow* sWindow);
//===============================================
GProcessO* GProcessOpenGLMCML_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLMCMLO* lChild = (GProcessOpenGLMCMLO*)malloc(sizeof(GProcessOpenGLMCMLO));

	sGDirection* lDirection = GOpenGL()->GetDirection();
	*lDirection = (sGDirection){
		{0.0, 0.0, -2.5},
		{-60.0, 0.0, 220.0},
		{10.0, 10.0, 10.0}
	};

	GOpenGL()->SetDirection(*lDirection);

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLMCML_Delete;
	lParent->Run = GProcessOpenGLMCML_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLMCML_Delete() {
	GProcess_Delete(m_GProcessOpenGLMCMLO);
	m_GProcessOpenGLMCMLO = 0;
}
//===============================================
GProcessO* GProcessOpenGLMCML() {
	if(m_GProcessOpenGLMCMLO == 0) {
		m_GProcessOpenGLMCMLO = GProcessOpenGLMCML_New();
	}
	return m_GProcessOpenGLMCMLO;
}
//===============================================
static void GProcessOpenGLMCML_Run(int argc, char** argv) {
	sGWindow lWindow = {
			"WINDOW",
			"OpenGL | ReadyDev",
			400, 400,
			GProcessOpenGLMCML_Update
	};
	GOpenGL()->MainLoop(&lWindow);
}
//===============================================
static void GProcessOpenGLMCML_Update(sGWindow* sWindow) {
	GOpenGL()->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GOpenGL()->ClearColor(0.0, 0.0, 0.0, 1.0);
	GOpenGL()->ModelView();

	GProcessOpenGLMCMLO* lProcess = m_GProcessOpenGLMCMLO->m_child;
	sGEvent* lEvent = GEvent()->GetEvent();
	sGDirection* lDirection = GOpenGL()->GetDirection();

	GOpenGL()->InitDirection();

	if(lEvent->frame.onFlag == TRUE) {
		sGCamera lCamera = {55.0, 0.1, 128.0};
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
				break;
				// Variation suivant +Sigma
			case GLFW_KEY_B:
				break;
			}
		}
	}

	sGGrid lGrid = {
			5.0, 1.0, 1.0/10,
			1, {0.2, 0.2, 0.2, 1.0},
			2, {0.9, 0.9, 0.9, 1.0}
	};

	sGMCML lMcml = {
			lProcess->m_mcmlData, lProcess->m_mcmlVertex, lProcess->m_mcmlColor,
			0.0, 0.0,
			GMCML_BUFFER_X, GMCML_BUFFER_Y, GMCML_BUFFER_Z,
			0.15, 5.0,
			0, 0, 0, 0.9, 10.0,
			lGrid.gridDiv, lDirection->div.x, lDirection->div.y, lDirection->div.z
	};

	GMcml()->Load("../data/mcml/MCML_output.txt", &lMcml);
	GMcml()->JetColor(&lMcml);

	GOpenGL()->DrawMcml(lMcml);
	GOpenGL()->DrawMcmlSlice(lMcml);
	GOpenGL()->DrawGrid(lGrid);
	GOpenGL()->DrawOrigin();
}
//===============================================
