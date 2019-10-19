//================================================
#include "GOpenGL.h"
#include "GGLfw.h"
//================================================
GOpenGL* GOpenGL::m_instance = 0;
//================================================
GOpenGL::GOpenGL() {

}
//================================================
GOpenGL::~GOpenGL() {

}
//================================================
GOpenGL* GOpenGL::Instance() {
	if(m_instance == 0) {
		m_instance = new GOpenGL;
	}
	return m_instance;
}
//================================================
void GOpenGL::viewPort(const string& windowName) {
	int lWidth;
	int lHeight;
	GGLfw::Instance()->frameBufferSize(windowName, &lWidth, &lHeight);
	glViewport(0, 0, lWidth, lHeight);
}
//================================================
void GOpenGL::clear(const uint& mask) {
	glClear(mask);
}
//================================================
void GOpenGL::ortho(const string& windowName) {
	int lWidth;
	int lHeight;
	GGLfw::Instance()->frameBufferSize(windowName, &lWidth, &lHeight);
	double lRatio = (double)lWidth/lHeight;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-lRatio, lRatio, -1.0, 1.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//================================================
void GOpenGL::rotate(const double& angle, const double& x, const double& y, const double& z) {
	glRotatef(angle, x, y, z);
}
//================================================
void GOpenGL::enable(const int& cap) {
	glEnable(cap);
}
//================================================
void GOpenGL::hint(const int& target, const int& mode) {
	glHint(target, mode);
}
//================================================
void GOpenGL::blendFunc(const int& sFactor, const int& dFactor) {
	glBlendFunc(sFactor, dFactor);
}
//================================================
void GOpenGL::drawPoint(const sGVertex& vertex, const sGColor& color, const int& pointSize) {
	glPointSize(pointSize);
	glBegin(GL_POINTS);
	glColor4f(color.r, color.g, color.b, color.a);
	glVertex3f(vertex.x, vertex.y, vertex.z);
	glEnd();
}
//================================================
void GOpenGL::drawTriangle(sGVertex* vertex, const sGColor& color) {
	glBegin(GL_TRIANGLES);
	for(int i = 0; i < 3; i++) {
		glColor3f(color.r, color.g, color.b);
		glVertex3f(vertex[i].x, vertex[i].y, vertex[i].z);
	}
	glEnd();
}
//================================================
void GOpenGL::drawTriangle(sGVertex* vertex, sGColor* color) {
	glBegin(GL_TRIANGLES);
	for(int i = 0; i < 3; i++) {
		glColor3f(color[i].r, color[i].g, color[i].b);
		glVertex3f(vertex[i].x, vertex[i].y, vertex[i].z);
	}
	glEnd();
}
//================================================
void GOpenGL::drawTriangle(sGTriangle* triangle) {
	glBegin(GL_TRIANGLES);
	for(int i = 0; i < 3; i++) {
		glColor4f(triangle->m_color[i].r, triangle->m_color[i].g, triangle->m_color[i].b, triangle->m_color[i].a);
		glVertex3f(triangle->m_vertex[i].x, triangle->m_vertex[i].y, triangle->m_vertex[i].z);
	}
	glEnd();
}
//================================================
