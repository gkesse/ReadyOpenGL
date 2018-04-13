//===============================================
#include "GCamera.h"
//===============================================
GCamera* GCamera::m_instance = 0;
//===============================================
GCamera::GCamera() {
    m_screenW = 0;
    m_screenH = 0;
    m_cameraPos = btVector3(10.0, 5.0, 0.0);
    m_targetPos = btVector3(0.0, 0.0, 0.0);
    m_upVec = btVector3(0.0, 1.0, 0.0);
    m_near = 1.0;
    m_far = 1000.0;
    m_cameraDist = 15.0;
    m_cameraPitch = 20.0;
    m_cameraYaw = 0.0;
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
    m_screenW = w;
    m_screenH = h;
}
//===============================================
void GCamera::update() {
    if(m_screenW == 0 && m_screenH == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float m_ratio = (float)m_screenW/m_screenH;
    float m_left = -m_ratio*m_near;
    float m_right = m_ratio*m_near;
    float m_top = -m_near;
    float m_bottom = m_near;
    float m_zNear = m_near;
    float m_zFar = m_far;
    glFrustum(m_left, m_right, m_top, m_bottom, m_zNear, m_zFar);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    float m_eyeX = m_cameraPos[0];
    float m_eyeY = m_cameraPos[1];
    float m_eyeZ = m_cameraPos[2];
    float m_centerX = m_targetPos[0];
    float m_centerY = m_targetPos[1];
    float m_centerZ = m_targetPos[2];
    float m_upX = m_upVec[0];
    float m_upY = m_upVec[1];
    float m_upZ = m_upVec[2];
    gluLookAt(m_eyeX, m_eyeY, m_eyeZ, m_centerX, m_centerY, m_centerZ, m_upX, m_upY, m_upZ);
}
//===============================================
