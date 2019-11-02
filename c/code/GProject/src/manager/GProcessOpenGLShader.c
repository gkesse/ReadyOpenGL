//===============================================
#include "GProcessOpenGLShader.h"
#include "GOpenGL.h"
#include "GGLFW.h"
#include "GEvent.h"
#include "GShader.h"
//===============================================
static GProcessO* m_GProcessOpenGLShaderO = 0;
//===============================================
static void GProcessOpenGLShader_Run(int argc, char** argv);
static void GProcessOpenGLShader_Init(sGWindow* sWindow);
static void GProcessOpenGLShader_Update(sGWindow* sWindow);
//===============================================
GProcessO* GProcessOpenGLShader_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLShaderO* lChild = (GProcessOpenGLShaderO*)malloc(sizeof(GProcessOpenGLShaderO));

	sGDirection* lDirection = GOpenGL()->GetDirection();
	*lDirection = (sGDirection){
		{0.0, 0.0, -2.5},
		{-60.0, 0.0, 220.0},
		{10.0, 10.0, 10.0}
	};

	GOpenGL()->SetDirection(*lDirection);

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLShader_Delete;
	lParent->Run = GProcessOpenGLShader_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLShader_Delete() {
	GProcess_Delete(m_GProcessOpenGLShaderO);
	m_GProcessOpenGLShaderO = 0;
}
//===============================================
GProcessO* GProcessOpenGLShader() {
	if(m_GProcessOpenGLShaderO == 0) {
		m_GProcessOpenGLShaderO = GProcessOpenGLShader_New();
	}
	return m_GProcessOpenGLShaderO;
}
//===============================================
static void GProcessOpenGLShader_Run(int argc, char** argv) {
	sGWindow lWindow = {
			"WINDOW",
			"OpenGL | ReadyDev",
			400, 400,
			GProcessOpenGLShader_Update,
			GProcessOpenGLShader_Init
	};
	GOpenGL()->MainLoop(&lWindow);
}
//===============================================
static void GProcessOpenGLShader_Init(sGWindow* sWindow) {
	sGShaderItem lShaderMap[] = {
			{TRUE, "VERTEX", "../data/shader/simple.vert", 0, 0, GL_VERTEX_SHADER},
			{TRUE, "FRAGMENT", "../data/shader/simple.frag", 0, 0, GL_FRAGMENT_SHADER},
			{FALSE, 0, 0, 0, 0}
	};
	sGFragData lFragData[] = {
			{TRUE, 0, "color_out"},
			{FALSE, 0, 0}
	};
	sGVertexArray lVertexArray[] = {
			{TRUE, 1},
			{FALSE, 0}
	};
	sGGenBuffer lGenBuffer[] = {
			{TRUE, 1},
			{TRUE, 1},
			{FALSE, 0}
	};
	sGShader lShader = {
			0,
			lShaderMap,
			lFragData,
			lVertexArray,
			lGenBuffer
	};
	GShader()->LoadShader(&lShader);
}
//===============================================
static void GProcessOpenGLShader_Update(sGWindow* sWindow) {
	GOpenGL()->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GOpenGL()->ClearColor(0.0, 0.0, 0.0, 1.0);
	GOpenGL()->ModelView();

	GOpenGL()->InitDirection();

	sGEvent* lEvent = GEvent()->GetEvent();

	if(lEvent->frame.onFlag == TRUE) {
		sGCamera lCamera = {55.0, 0.1, 128.0};
		GOpenGL()->Viewport(sWindow->name);
		GOpenGL()->Projection();
		GOpenGL()->Frustum(sWindow->name, lCamera);
	}

	sGGrid lGrid = {
			5.0, 1.0, 1.0/10,
			1, {0.2, 0.2, 0.2, 1.0},
			2, {0.9, 0.9, 0.9, 1.0}
	};

	GOpenGL()->DrawGrid(lGrid);
	GOpenGL()->DrawOrigin();
}
//===============================================
