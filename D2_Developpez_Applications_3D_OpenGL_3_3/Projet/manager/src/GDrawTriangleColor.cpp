//================================================
#include "GDrawTriangleColor.h"
#include "GVertex.h"
#include "GShader.h"
//================================================
GDrawTriangleColor* GDrawTriangleColor::m_instance = 0;
//================================================
GDrawTriangleColor::GDrawTriangleColor() {

}
//================================================
GDrawTriangleColor::~GDrawTriangleColor() {
	
}
//================================================
GDrawTriangleColor* GDrawTriangleColor::Instance() {
	if(m_instance == 0) {
		m_instance = new GDrawTriangleColor;
	}
	return m_instance;
}
//================================================
void GDrawTriangleColor::initDraw() {
	float m_data[3][2] = {
		{-0.5, -0.5}, {0.0, 0.5}, {0.5, -0.5}
	};
	
	GVertex::Instance()->loadVertex2D(m_vertices, m_data, 3);
	
	GShaderInfo m_shaders[] = {
        {GL_VERTEX_SHADER, "res/shaders/color/color.vert"},
        {GL_FRAGMENT_SHADER, "res/shaders/color/color.frag"},
        {GL_NONE}
    };
	
	m_program =  GShader::Instance()->loadShader(m_shaders);
}
//================================================
void GDrawTriangleColor::drawShape() {
	glUseProgram(m_program);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, m_vertices);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glUseProgram(0);
}
//================================================
