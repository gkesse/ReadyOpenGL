//===============================================
#include "GProcessTriangle.h"
#include "GGLfw.h"
#include "GOpenGL.h"
//===============================================
GProcessTriangle* GProcessTriangle::m_instance = 0;
//===============================================
GProcessTriangle::GProcessTriangle() {

}
//===============================================
GProcessTriangle::~GProcessTriangle() {

}
//===============================================
GProcessTriangle* GProcessTriangle::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessTriangle;
	}
	return m_instance;
}
//===============================================
void GProcessTriangle::run(int argc, char **argv) {
	GGLfw::Instance()->init();
	GGLfw::Instance()->createWindow("WINDOW", "OpenGL | ReadyDev", 400, 400);
	GGLfw::Instance()->makeContext("WINDOW");
	while(1) {
		bool lClose = GGLfw::Instance()->closeWindow("WINDOW");
		if(lClose == true) break;
		GOpenGL::Instance()->viewPort("WINDOW");
		GOpenGL::Instance()->clear(GL_COLOR_BUFFER_BIT);
		GOpenGL::Instance()->ortho("WINDOW");
		sGVertex lVertex[] = {
				{-0.6, -0.4, 0.0},
				{0.6, -0.4, 0.0},
				{0.0, 0.6, 0.0}
		};
		sGColor lColor = {1.0, 0.0, 0.0, 1.0};
		double lAngle = GGLfw::Instance()->getTime() * 50;
		GOpenGL::Instance()->rotate(lAngle, 0.0, 0.0, 1.0);
		GOpenGL::Instance()->drawTriangle(lVertex, lColor);
		GGLfw::Instance()->swapBuffers("WINDOW");
		GGLfw::Instance()->pollEvents();
	}
	GGLfw::Instance()->destroyWindow("WINDOW");
	GGLfw::Instance()->terminate();
}
//===============================================
