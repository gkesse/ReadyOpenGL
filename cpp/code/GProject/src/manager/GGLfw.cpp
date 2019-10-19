//================================================
#include "GGLfw.h"
//================================================
GGLfw* GGLfw::m_instance = 0;
//================================================
GGLfw::GGLfw() {

}
//================================================
GGLfw::~GGLfw() {
	
}
//================================================
GGLfw* GGLfw::Instance() {
	if(m_instance == 0) {
		m_instance = new GGLfw;
	}
	return m_instance;
}
//================================================
void GGLfw::init() {
    bool lRes = glfwInit();
    if(lRes == false) {cout << "[ GGLfw ] Error GGLfw::init\n"; exit(0);}
}
//================================================
void GGLfw::createWindow(const string& windowName, const string& title, const int& w, const int& h) {
	GLFWwindow* lWindow = glfwCreateWindow(w, h, title.c_str(), NULL, NULL);
    if(lWindow == 0) {cout << "[ GGLfw ] Error GGLfw::createWindow\n"; glfwTerminate(); exit(0);}
    m_windowMap[windowName] = lWindow;
}
//================================================
void GGLfw::makeContext(const string& windowName) {
	GLFWwindow* lWindow = m_windowMap[windowName];
    glfwMakeContextCurrent(lWindow);
}
//================================================
bool GGLfw::closeWindow(const string& windowName) {
	GLFWwindow* lWindow = m_windowMap[windowName];
    bool lRes = glfwWindowShouldClose(lWindow);
    return lRes;
}
//================================================
void GGLfw::frameBufferSize(const string& windowName, int* width, int* height) {
	GLFWwindow* lWindow = m_windowMap[windowName];
	glfwGetFramebufferSize(lWindow, width, height);
}
//================================================
double GGLfw::getTime() {
	double lTime = glfwGetTime();
	return lTime;
}
//================================================
void GGLfw::swapBuffers(const string& windowName) {
	GLFWwindow* lWindow = m_windowMap[windowName];
    glfwSwapBuffers(lWindow);
}
//================================================
void GGLfw::pollEvents() {
	glfwPollEvents();
}
//================================================
void GGLfw::destroyWindow(const string& windowName) {
	GLFWwindow* lWindow = m_windowMap[windowName];
    glfwDestroyWindow(lWindow);
}
//================================================
void GGLfw::terminate() {
	glfwTerminate();
}
//================================================
