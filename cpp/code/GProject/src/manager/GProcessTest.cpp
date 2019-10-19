//===============================================
#include "GProcessTest.h"
#include "GGLfw.h"
#include "GOpenGL.h"
//===============================================
GProcessTest* GProcessTest::m_instance = 0;
//===============================================
GProcessTest::GProcessTest() {

}
//===============================================
GProcessTest::~GProcessTest() {

}
//===============================================
GProcessTest* GProcessTest::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessTest;
	}
	return m_instance;
}
//===============================================
void GProcessTest::run(int argc, char **argv) {
	GGLfw::Instance()->init();
	GGLfw::Instance()->createWindow("WINDOW", "OpenGL | ReadyDev", 400, 400);
	GGLfw::Instance()->makeContext("WINDOW");
	while(1) {
		bool lClose = GGLfw::Instance()->closeWindow("WINDOW");
		if(lClose == true) break;
		GOpenGL::Instance()->viewPort("WINDOW");
		GOpenGL::Instance()->clear(GL_COLOR_BUFFER_BIT);
		GOpenGL::Instance()->ortho("WINDOW");
		sGVertex lVertex = {0.0, 0.0, 0.0};
		sGColor lColor = {1.0, 0.0, 0.0, 1.0};
		GOpenGL::Instance()->enable(GL_POINT_SMOOTH);
		GOpenGL::Instance()->hint(GL_POINT_SMOOTH_HINT, GL_NICEST);
		GOpenGL::Instance()->enable(GL_BLEND);
		GOpenGL::Instance()->blendFunc(GL_POINT_SMOOTH_HINT, GL_ONE_MINUS_SRC_ALPHA);
		GOpenGL::Instance()->drawPoint(lVertex, lColor, 50);
		GGLfw::Instance()->swapBuffers("WINDOW");
		GGLfw::Instance()->pollEvents();
	}
	GGLfw::Instance()->destroyWindow("WINDOW");
	GGLfw::Instance()->terminate();
}
//===============================================
