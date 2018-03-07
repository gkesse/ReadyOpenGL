//===============================================
#include "GWindow.h"
//===============================================
GWindow* GWindow::m_instance = 0;
//===============================================
GWindow::GWindow() {
	m_title = "GWindow";
	m_x = SDL_WINDOWPOS_CENTERED;
	m_y = SDL_WINDOWPOS_CENTERED;
	m_w = 640;
	m_h = 480;
	m_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
	m_window = 0;
	m_run = true;
}
//===============================================
GWindow::~GWindow() {
	
}
//===============================================
GWindow* GWindow::Instance() {
	if(m_instance == 0) {
		m_instance = new GWindow;
	}
	return m_instance;
}
//===============================================
void GWindow::print() {
	string m_format = "GWindow: Info: ";
	m_format += m_title + " | ";
	m_format += to_string(m_x) + " | ";
	m_format += to_string(m_y) + " | ";
	m_format += to_string(m_w) + " | ";
	m_format += to_string(m_h) + " | ";
	m_format += to_string(m_flags);
	cout << m_format << "\n";
}
//===============================================
void GWindow::create() {
	m_window = SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_w, m_h, m_flags);
	
	if(m_window == 0) {
		cout << "GWindow: Error: SDL_CreateWindow : ";
		cout << SDL_GetError() << "\n";
		SDL_Quit();
		exit(-1);
	}
}
//===============================================
void GWindow::context() {
	// Version d'OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}
//===============================================
void GWindow::run() {
	while(m_run) {
		SDL_WaitEvent(&m_events);
		if(m_events.window.event == SDL_WINDOWEVENT_CLOSE) m_run = false;
		glClear(GL_COLOR_BUFFER_BIT);
		
		SDL_GL_SwapWindow(m_window);
	}
}
//===============================================
