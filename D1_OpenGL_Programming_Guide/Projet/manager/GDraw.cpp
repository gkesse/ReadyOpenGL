//================================================
#include "GDraw.h"
#include "GShader.h"
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
	drawBackground();
	
	switch(index) {
		case 0: drawTriangle(); break;
	}
}
//================================================
void GDraw::drawBackground() {
	float m_bgColor[] = {0.0f, 0.2f, 0.0f, 0.0f};
	glClearBufferfv(GL_COLOR, 0, m_bgColor);
}
//================================================
void GDraw::drawTriangle() {
	GLuint m_vertexArray[1];
	
	glGenVertexArrays(1, m_vertexArray);
    glBindVertexArray(m_vertexArray[0]);
	
	GLfloat m_vertices[3][2] = {
		{-0.5f, -0.5f}, {0.0f, 0.5f}, {0.5f, -0.5f}
	};

	GLuint m_buffers[1];
	
	glCreateBuffers(1, m_buffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[0]);
    glBufferStorage(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, 0);

	GShaderInfo m_shaders[] = {
        {GL_VERTEX_SHADER, "res/shaders/triangles/triangles.vert"},
        {GL_FRAGMENT_SHADER, "res/shaders/triangles/triangles.frag"},
        {GL_NONE}
    };
	
	GLuint m_program =  GShader::Instance()->loadShader(m_shaders);
	
	glUseProgram(m_program);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);	
	
	glBindVertexArray(m_vertexArray[0]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
//================================================
