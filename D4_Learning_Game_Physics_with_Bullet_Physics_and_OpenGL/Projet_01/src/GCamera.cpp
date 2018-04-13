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
    m_cameraDis = 15.0;
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
    float m_pitch = m_cameraPitch*RADIANS_PER_DEGREE;
    float m_yaw = m_cameraYaw*RADIANS_PER_DEGREE;
    btQuaternion m_rotation(m_upVec, m_yaw);
    btVector3 m_cameraPosition(0.0, 0.0, 0.0);
    m_cameraPosition[2] = -m_cameraDis;
    btVector3 m_forward(m_cameraPosition[0], m_cameraPosition[1], m_cameraPosition[2]);
    if (m_forward.length2() < SIMD_EPSILON) {
        m_forward.setValue(1.0, 0.0, 0.0);
    }
    btVector3 m_rightVec = m_upVec.cross(m_forward);
    btQuaternion m_roll(m_rightVec, - m_pitch);
    m_cameraPosition = btMatrix3x3(m_rotation) * btMatrix3x3(m_roll) * m_cameraPosition;

    m_cameraPos[0] = m_cameraPosition.x();
    m_cameraPos[1] = m_cameraPosition.y();
    m_cameraPos[2] = m_cameraPosition.z();
    m_cameraPos += m_targetPos;

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
void GCamera::zoom(const float& distance) {
    m_cameraDis -= distance;
    if(m_cameraDis < 0.1) m_cameraDis = 0.1;
    update();
}
//===============================================
void GCamera::rotatePitch(const float& angle) {
    m_cameraPitch -= angle;
    if (m_cameraPitch < 0) m_cameraPitch += 360;
    if (m_cameraPitch >= 360) m_cameraPitch -= 360;
    update();
}
//===============================================
void GCamera::rotateYaw(const float& angle) {
    m_cameraYaw -= angle;
    if (m_cameraYaw < 0) m_cameraYaw += 360;
    if (m_cameraYaw >= 360) m_cameraYaw -= 360;
    update();
}
//===============================================
