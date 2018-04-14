//===============================================
#include "GDraw.h"
//===============================================
GDraw* GDraw::m_instance = 0;
//===============================================
GDraw::GDraw() {

}
//===============================================
GDraw::~GDraw() {

}
//===============================================
GDraw* GDraw::Instance() {
    if(m_instance == 0) {
        m_instance = new GDraw;
    }
    return m_instance;
}
//===============================================
void GDraw::setVertices() {
    float m_vertices[] = {-0.5, -0.5, 0.0, 0.5, 0.5, -0.5};
    int m_size = sizeof(m_vertices)/sizeof(float);
    for(int i = 0; i < m_size; i++) {
        m_verticesMap[i] = m_vertices[i];
    }
}
//===============================================
void GDraw::draw() {
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, m_verticesMap);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
}
//===============================================
