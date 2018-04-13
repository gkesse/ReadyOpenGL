//===============================================
#include "GLight.h"
//===============================================
GLight* GLight::m_instance = 0;
//===============================================
GLight::GLight() {
    m_w = 0;
    m_h = 0;
}
//===============================================
GLight::~GLight() {

}
//===============================================
GLight* GLight::Instance() {
    if(m_instance == 0) {
        m_instance = new GLight;
    }
    return m_instance;
}
//===============================================
void GLight::initLight() {
    GLfloat m_ambient[] = {51.0/255.0, 51.0/255.0, 51.0/255.0, 255.0/255.0};
    GLfloat m_diffuse[] = {255.0/255.0, 255.0/255.0, 255.0/255.0, 255.0/255.0};
    GLfloat m_specular[] = {255.0/255.0, 255.0/255.0, 255.0/255.0, 255.0/255.0};
    GLfloat m_position[] = {5.0, 10.0, 1.0, 0.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, m_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, m_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, m_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, m_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glMaterialfv(GL_FRONT, GL_SPECULAR, m_specular);
    glMateriali(GL_FRONT, GL_SHININESS, 15);

    glShadeModel(GL_SMOOTH);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}
//===============================================
