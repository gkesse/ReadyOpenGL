//================================================
#include "GDraw.h"
//================================================
GDraw* GDraw::m_instance = 0;
//================================================
GDraw::GDraw() {

}
//================================================
GDraw::~GDraw() {
	
}
//================================================
GDraw* GDraw::Instance() {
	if(m_instance == 0) {
		m_instance = new GDraw;
	}
	return m_instance;
}
//================================================
void GDraw::draw(const int& index) {
	float m_bgColor[] = {0.0f, 0.2f, 0.0f, 0.0f};
	
	glClearBufferfv(GL_COLOR, 0, m_bgColor);
	
	switch(index) {
		case 0: drawTriangle(); break;
	}
}
//================================================
void GDraw::drawTriangle() {
	/*GLfloat m_vertices[6][2] = {
		{ -0.90f, -0.90f }, {  0.85f, -0.90f }, { -0.90f,  0.85f },  // Triangle 1
		{  0.90f, -0.85f }, {  0.90f,  0.90f }, { -0.85f,  0.90f }   // Triangle 2
	};
	GLuint m_buffers[1];
	GLuint m_vertexArray[1];
	
	glCreateBuffers(1, m_buffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[0]);
	
	
	glUseProgram(m_program);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);
	glBindVertexArray(m_vertexArray[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6)*/
}
//================================================
