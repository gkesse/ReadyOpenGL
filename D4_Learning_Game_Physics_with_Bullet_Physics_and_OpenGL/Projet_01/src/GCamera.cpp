//===============================================
#include "GCamera.h"
//===============================================
GCamera* GCamera::m_instance = 0;
//===============================================
GCamera::GCamera() {
    m_w = 0;
    m_h = 0;
}
//===============================================
GCamera::~GCamera() {

}
//===============================================
GCamera* GCamera::Instance() {
    if(m_instance == 0) {
        m_instance = new GCamera;
    }
    return m_instance;
}
//===============================================
void GCamera::setWindowSize(int w, int h) {
    m_w = w;
    m_h = h;
}
//===============================================
void GCamera::update() {
    if(m_w == 0 && m_h == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float m_ratio = (float)m_w/m_h;
    float m_nearPlane = 1.0;
    float m_farPlane = 1000.0;
    float m_left = -m_ratio*m_nearPlane;
    float m_right = m_ratio*m_nearPlane;
    float m_top = -m_nearPlane;
    float m_bottom = m_nearPlane;
    float m_zNear = m_nearPlane;
    float m_zFar = m_farPlane;
    glFrustum(m_left, m_right, m_top, m_bottom, m_zNear, m_zFar);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    float m_eyeX = 10.0;
    float m_eyeY = 5.0;
    float m_eyeZ = 0.0;
    float m_centerX = 0.0;
    float m_centerY = 0.0;
    float m_centerZ = 0.0;
    float m_upX = 0.0;
    float m_upY = 1.0;
    float m_upZ = 0.0;
    gluLookAt(m_eyeX, m_eyeY, m_eyeZ, m_centerX, m_centerY, m_centerZ, m_upX, m_upY, m_upZ);
}
//===============================================
