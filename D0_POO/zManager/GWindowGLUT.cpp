//===============================================
#include "GWindowGLUT.h"
//===============================================
GWindowGLUT* GWindowGLUT::m_instance = 0;
//===============================================
GWindowGLUT::GWindowGLUT() {
    m_x = 0;
    m_y = 0;
    m_w = 400;
    m_h = 400;
    m_title = "OpenGL | FreeGLUT | ReadyDev";
}
//===============================================
GWindowGLUT::~GWindowGLUT() {

}
//===============================================
GWindowGLUT* GWindowGLUT::Instance() {
    if(m_instance == 0) {
        m_instance = new GWindowGLUT;
    }
    return m_instance;
}
//===============================================
void GWindowGLUT::show(int* argc, char** argv) {
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(m_x, m_y);
    glutInitWindowSize(m_w, m_h);
    glutCreateWindow(m_title.c_str());
    glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
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
void GWindowGLUT::KeyboardFunc(unsigned char key, int w, int h) {

}
//===============================================
void GWindowGLUT::KeyboardUpFunc(unsigned char key, int w, int h) {

}
//===============================================
void GWindowGLUT::SpecialFunc(int key, int w, int h) {

}
//===============================================
void GWindowGLUT::SpecialUpFunc(int key, int w, int h) {

}
//===============================================
void GWindowGLUT::ReshapeFunc(int w, int h) {

}
//===============================================
void GWindowGLUT::IdleFunc() {

}
//===============================================
void GWindowGLUT::MouseFunc(int button, int state, int x, int y) {

}
//===============================================
void GWindowGLUT::MotionFunc(int x,int y) {

}
//===============================================
void GWindowGLUT::DisplayFunc() {

}
//===============================================
