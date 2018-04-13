//===============================================
#include "GWindow.h"
#include "GDraw.h"
#include "GCamera.h"
#include "GLight.h"
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
    setLight();
    setBackground();
    glutKeyboardFunc(KeyboardFunc);
    glutKeyboardUpFunc(KeyboardUpFunc);
    glutSpecialFunc(SpecialFunc);
    glutSpecialUpFunc(SpecialUpFunc);
    glutReshapeFunc(ReshapeFunc);
    glutIdleFunc(IdleFunc);
    glutMouseFunc(MouseFunc);
    glutPassiveMotionFunc(MotionFunc);
    glutMotionFunc(MotionFunc);
    glutDisplayFunc(DisplayFunc);
    glutMainLoop();
}
//===============================================
void GWindow::setLight() {
    GLight::Instance()->initLight();
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
void GWindow::KeyboardFunc(unsigned char key, int w, int h) {

}
//===============================================
void GWindow::KeyboardUpFunc(unsigned char key, int w, int h) {

}
//===============================================
void GWindow::SpecialFunc(int key, int w, int h) {

}
//===============================================
void GWindow::SpecialUpFunc(int key, int w, int h) {

}
//===============================================
void GWindow::ReshapeFunc(int w, int h) {
    glViewport(0, 0, w, h);
    GCamera::Instance()->setWindowSize(w, h);
    GCamera::Instance()->update();
}
//===============================================
void GWindow::IdleFunc() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GDraw::Instance()->draw();
    GCamera::Instance()->update();
    glutSwapBuffers();
}
//===============================================
void GWindow::MouseFunc(int button, int state, int x, int y) {

}
//===============================================
void GWindow::MotionFunc(int x,int y) {

}
//===============================================
void GWindow::DisplayFunc() {

}
//===============================================
