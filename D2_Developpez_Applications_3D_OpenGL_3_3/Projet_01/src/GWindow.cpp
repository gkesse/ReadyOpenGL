//===============================================
#include "GWindow.h"
#include "GDraw.h"
//===============================================
GWindow* GWindow::m_instance = 0;
//===============================================
GWindow::GWindow() {
    m_x = SDL_WINDOWPOS_CENTERED;
    m_y = SDL_WINDOWPOS_CENTERED;
    m_w = 400;
    m_h = 400;
    m_title = "OpenGL | ReadyDev";
    m_window = 0;
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
void GWindow::show() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    m_window = SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_w, m_h, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GLContext m_context = SDL_GL_CreateContext(m_window);
    glewInit();
    GDraw::Instance()->setVertices();
    SDL_Event m_event;
    while(1) {
        SDL_WaitEvent(&m_event);
        if(m_event.window.event == SDL_WINDOWEVENT_CLOSE) break;
        setBackground();
        glClear(GL_COLOR_BUFFER_BIT);
        GDraw::Instance()->draw();
        SDL_GL_SwapWindow(m_window);
    }
    SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
//===============================================
void GWindow::setBackground() {
    float m_red = 5.0/255.0;
    float m_green = 16.0/255.0;
    float m_blue = 57.0/255.0;
    float m_alpha = 255.0/255.0;

    glClearColor(m_red, m_green, m_blue, m_alpha);
}
//===============================================
