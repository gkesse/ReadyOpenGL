//================================================
#include "GDrawTriangleDouble.h"
//================================================
GDrawTriangleDouble* GDrawTriangleDouble::m_instance = 0;
//================================================
GDrawTriangleDouble::GDrawTriangleDouble() {

}
//================================================
GDrawTriangleDouble::~GDrawTriangleDouble() {
	
}
//================================================
GDrawTriangleDouble* GDrawTriangleDouble::Instance() {
	if(m_instance == 0) {
		m_instance = new GDrawTriangleDouble;
	}
	return m_instance;
}
//================================================
void GDrawTriangleDouble::initDraw() {
	float m_vertices[3][2] = {
		{-0.5, -0.5}, {0.0, 0.5}, {0.5, -0.5}
	};
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, m_vertices);
}
//================================================
void GDrawTriangleDouble::drawShape() {
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}
//================================================
