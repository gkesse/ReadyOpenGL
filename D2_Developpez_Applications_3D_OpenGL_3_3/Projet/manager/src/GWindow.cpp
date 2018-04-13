//================================================
#include "GWindow.h"
#include "GDraw.h"
//================================================
GWindow::GWindow() {
	m_title = "OpenGL Window";
	m_x = SDL_WINDOWPOS_CENTERED;
	m_y = SDL_WINDOWPOS_CENTERED;
	m_w = 480;
	m_h = 480;
	m_window = 0;
	m_run = true;
	GDraw::Instance()->setWindowSize(m_w, m_h);
}
//================================================
GWindow::~GWindow() {
	
}
//================================================
void GWindow::initSdl() {
	int m_res = SDL_Init(SDL_INIT_VIDEO);
	if(m_res < 0) {cout << "ERROR: SDL_Init\n"; exit(0);}
}
//================================================
void GWindow::initGlew() {
	GLenum m_res = glewInit();
	if(m_res != GLEW_OK) {cout << "ERROR: glewInit\n"; exit(0);}
}
//================================================
void GWindow::initAttribute() {
	// Version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}
//================================================
void GWindow::createWindow() {
	m_window = SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_w, m_h, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL); 
	if(m_window == 0) {cout << "ERROR: SDL_CreateWindow\n"; exit(0);}
}
//================================================
void GWindow::createContext() {
	// Context
	m_context = SDL_GL_CreateContext(m_window);
	if(m_context == 0) {cout << "ERROR: SDL_GL_CreateContext\n"; exit(0);}
}
//================================================
void GWindow::run() {	
	GDraw::Instance()->initDraw();
	while(m_run) {
		SDL_WaitEvent(&m_events);
		if(m_events.window.event == SDL_WINDOWEVENT_CLOSE) m_run = false;
		glClear(GL_COLOR_BUFFER_BIT);
		draw();
		SDL_GL_SwapWindow(m_window);
	}
}
//================================================
void GWindow::release() {
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
//================================================
