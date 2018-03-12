//================================================
#include "GDrawTriangle.h"
//================================================
GDrawTriangle* GDrawTriangle::m_instance = 0;
//================================================
GDrawTriangle::GDrawTriangle() {

}
//================================================
GDrawTriangle::~GDrawTriangle() {
	
}
//================================================
GDrawTriangle* GDrawTriangle::Instance() {
	if(m_instance == 0) {
		m_instance = new GDrawTriangle;
	}
	return m_instance;
}
//================================================
void GDrawTriangle::initDraw() {
	float m_vertices[3][2] = {
		{-0.5, -0.5}, {0.0, 0.5}, {0.5, -0.5}
	};
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, m_vertices);
}
//================================================
void GDrawTriangle::drawShape() {
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}
//================================================