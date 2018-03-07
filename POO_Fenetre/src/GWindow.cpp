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
void GWindow::init() {
	int m_result = SDL_Init(SDL_INIT_VIDEO);
	
	if(m_result < 0) {
		cout << "ERROR: GWindow::init()\n";
		SDL_Quit();
		exit(-1);
	}
}
//===============================================
void GWindow::attribute() {
	// Version d'OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}
//===============================================
void GWindow::create() {
	m_window = SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_w, m_h, m_flags);
	
	if(m_window == 0) {
		cout << "ERROR: GWindow::create() - ";
		cout << SDL_GetError() << "\n";
		SDL_Quit();
		exit(-1);
	}
}
//===============================================
void GWindow::context() {
	m_context = SDL_GL_CreateContext(m_window);

	if(m_context == 0) {
		cout << "ERROR: GWindow::context() - ";
		cout << SDL_GetError() << "\n";
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		exit(-1);
	}
}
//===============================================
void GWindow::glew() {
	GLenum m_result = glewInit();

	if(m_result != GLEW_OK) {
		cout << "ERROR:  GWindow::glew() - ";
		cout << glewGetErrorString(m_result) << "\n";
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		exit(-1);
	}
}
//===============================================
void GWindow::draw() {
	float m_vertices[] = {
		0.0, 0.0, 0.5, 0.0, 0.0, 0.5, // Triangle 1
		-0.8, -0.8, -0.3, -0.8, -0.8, -0.3 // Triangle 2
	};
	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, m_vertices);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
}
//===============================================
void GWindow::run() {
	while(m_run) {
		SDL_WaitEvent(&m_events);
		if(m_events.window.event == SDL_WINDOWEVENT_CLOSE) m_run = false;
		glClear(GL_COLOR_BUFFER_BIT);
		draw();
		SDL_GL_SwapWindow(m_window);
	}
}
//===============================================
void GWindow::release() {
	if(m_window != 0) SDL_DestroyWindow(m_window);
}
//===============================================
