//================================================
#include "GShader.h"
//================================================
GShader* GShader::m_instance = 0;
//================================================
GShader::GShader() {

}
//================================================
GShader::~GShader() {
	
}
//================================================
GShader* GShader::Instance() {
	if(m_instance == 0) {
		m_instance = new GShader;
	}
	return m_instance;
}
//================================================
GLuint GShader::loadShader(GShaderInfo* shaderInfo) {
	if(shaderInfo == 0) return 0;
	
	GLuint m_program = glCreateProgram();
	
	while(shaderInfo->type != GL_NONE) {
		GLuint m_shader = glCreateShader(shaderInfo->type);
		shaderInfo->shader = m_shader;
		GLchar* m_source = readShader(shaderInfo->filename);
		
	}
}
//================================================
GLchar* GShader::readShader(const string& filename) {
	
}
//================================================
