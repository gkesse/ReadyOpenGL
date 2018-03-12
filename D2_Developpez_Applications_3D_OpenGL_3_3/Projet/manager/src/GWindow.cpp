//================================================
#include "GWindow.h"
//================================================
GWindow* GWindow::m_instance = 0;
//================================================
GWindow::GWindow() {
	m_title = "OpenGL Window";
	m_x = SDL_WINDOWPOS_CENTERED;
	m_y = SDL_WINDOWPOS_CENTERED;
	m_w = 480;
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
void GWindow::initSdl() {
	SDL_Init(SDL_INIT_VIDEO);
}
//================================================
void GWindow::initGlew() {
	GLenum m_res = glewInit();
	if(m_res == GLEW_OK) cout << "GLEW_OK\n";
}
//================================================
void GWindow::createWindow() {
	m_window = SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_w, m_h, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL); 
}
//================================================
void GWindow::createContext() {
	// Version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	// Context
	m_context = SDL_GL_CreateContext(m_window);
}
//================================================
void GWindow::run() {
	float m_vertices[3][2] = {
		{-0.5, -0.5}, {0.0, 0.5}, {0.5, -0.5}
	};
	
	while(m_run) {
		SDL_WaitEvent(&m_events);
		if(m_events.window.event == SDL_WINDOWEVENT_CLOSE) m_run = false;
		glClear(GL_COLOR_BUFFER_BIT);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, m_vertices);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
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
