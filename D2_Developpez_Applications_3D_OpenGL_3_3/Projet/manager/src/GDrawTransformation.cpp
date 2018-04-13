//================================================
#include "GDrawTransformation.h"
#include "GVertex.h"
#include "GShader.h"
//================================================
GDrawTransformation* GDrawTransformation::m_instance = 0;
//================================================
GDrawTransformation::GDrawTransformation() {

}
//================================================
GDrawTransformation::~GDrawTransformation() {
	
}
//================================================
GDrawTransformation* GDrawTransformation::Instance() {
	if(m_instance == 0) {
		m_instance = new GDrawTransformation;
	}
	return m_instance;
}
//================================================
void GDrawTransformation::initDraw() {
	float m_data[3][3] = {
		{-0.5, -0.5, -1.0}, {0.0, 0.5, -1.0}, {0.5, -0.5, -1.0}
	};
	
	GVertex::Instance()->loadVertex2D(m_vertices, m_data, 3);
	
	GShaderInfo m_shaders[] = {
        {GL_VERTEX_SHADER, "res/shaders/color/color.vert"},
        {GL_FRAGMENT_SHADER, "res/shaders/color/color.frag"},
        {GL_NONE}
    };
	
	m_program =  GShader::Instance()->loadShader(m_shaders);
	
	m_projection = glm::perspective(70.0, (float)m_w/m_h, 1.0, 100.0);
	m_modelview = glm::mat4(1.0);
}
//================================================
void GDrawTransformation::drawShape() {
	m_projection = glm::mat4(1.0);
	glUseProgram(m_program);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, m_vertices);
	glEnableVertexAttribArray(0);
	glUniformMatrix4fv(glGetUniformLocation(m_program, "modelview"), 1, GL_FALSE, value_ptr(modelview));
glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(),
"projection"), 1, GL_FALSE, value_ptr(projection));

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glUseProgram(0);
}
//================================================
