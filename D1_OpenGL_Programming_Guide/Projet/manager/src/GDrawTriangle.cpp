//================================================
#include "GDrawTriangle.h"
#include "GShader.h"
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
void GDrawTriangle::drawShape() {
	GLuint m_vertexArray[1];
	
	glGenVertexArrays(1, m_vertexArray);
    glBindVertexArray(m_vertexArray[0]);
	
	GLfloat m_vertices[3][2] = {
		{-0.5f, -0.5f}, {0.5f, -0.5f}, {0.0f, 0.5f}
	};

	GLuint m_buffers[1];
	
	glCreateBuffers(1, m_buffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[0]);
    glBufferStorage(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, 0);

	GShaderInfo m_shaders[] = {
        {GL_VERTEX_SHADER, "res/shaders/shapes/shapes.vert"},
        {GL_FRAGMENT_SHADER, "res/shaders/shapes/shapes.frag"},
        {GL_NONE}
    };
	
	GLuint m_program =  GShader::Instance()->loadShader(m_shaders);
	
	glUseProgram(m_program);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(1);	
	glBindVertexArray(m_vertexArray[0]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
//================================================
