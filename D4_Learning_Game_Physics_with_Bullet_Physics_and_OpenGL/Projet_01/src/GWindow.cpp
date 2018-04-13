//===============================================
#include "GWindow.h"
//===============================================
GWindow* GWindow::m_instance = 0;
//===============================================
GWindow::GWindow() {
    m_x = 0;
    m_y = 0;
    m_w = 400;
    m_h = 400;
    m_title = "OpenGL | ReadyDev";
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
void GWindow::show(int* argc, char** argv) {
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(m_x, m_y);
    glutInitWindowSize(m_w, m_h);
    glutCreateWindow(m_title.toStdString().c_str());
    glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    glutDisplayFunc(runDisplay);
    glutMainLoop();
}
//===============================================
void GWindow::runDisplay() {

}
//===============================================
