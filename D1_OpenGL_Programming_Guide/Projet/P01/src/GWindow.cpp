//================================================
#include "GWindow.h"
//================================================
GWindow* GWindow::m_instance = 0;
//================================================
GWindow::GWindow() {
	m_title = "GWindow - Rendu de Scene 3D";
	m_w = 640;
	m_h = 480;
	m_window = 0;
	m_run = true;
}
//================================================
GWindow::~GWindow() {
	
}
//================================================
GWindow* GWindow::Instance() {
	if(m_instance == 0) {
		m_instance = new GWindow;
	}
	return m_instance;
}
//================================================
void GWindow::initGlfw() {
	glfwInit();
}
//================================================
void GWindow::createWindow() {
	m_window = glfwCreateWindow(m_w, m_h, m_title.c_str(), NULL, NULL);
}
//================================================
void GWindow::createContext() {
	glfwMakeContextCurrent(m_window);
}
//================================================
void GWindow::initGl3w() {
	gl3wInit();
}
//================================================
void GWindow::run() {
	while(m_run) {
		bool m_res = glfwWindowShouldClose(m_window);
		if(m_res == true) m_run = false;
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
}
//================================================
void GWindow::release() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}
//================================================
