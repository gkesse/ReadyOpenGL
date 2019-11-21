//===============================================
#include "GProcessOpenGLShader.h"
#include "GOpenGL.h"
#include "GGLFW.h"
#include "GGLew.h"
#include "GEvent.h"
#include "GShader.h"
//===============================================
static GProcessO* m_GProcessOpenGLShaderO = 0;
//===============================================
static void GProcessOpenGLShader_Run(int argc, char** argv);
static void GProcessOpenGLShader_Init();
static void GProcessOpenGLShader_Update();
//===============================================
GProcessO* GProcessOpenGLShader_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLShaderO* lChild = (GProcessOpenGLShaderO*)malloc(sizeof(GProcessOpenGLShaderO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLShader_Delete;
	lParent->Run = GProcessOpenGLShader_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLShader_Delete() {
	GProcess_Delete(m_GProcessOpenGLShaderO);
	m_GProcessOpenGLShaderO = 0;
}
//===============================================
GProcessO* GProcessOpenGLShader() {
	if(m_GProcessOpenGLShaderO == 0) {
		m_GProcessOpenGLShaderO = GProcessOpenGLShader_New();
	}
	return m_GProcessOpenGLShaderO;
}
//===============================================
static void GProcessOpenGLShader_Run(int argc, char** argv) {
	GProcessOpenGLShaderO* lProcess = m_GProcessOpenGLShaderO->m_child;
	sGShader* lShader = &lProcess->m_shader;
	sGShaderVAO* lShaderVAO = &lProcess->m_shaderVAO;
	sGShaderVBO* lVertexVBO = &lProcess->m_vertexVBO;
	sGShaderVBO* lColorVBO = &lProcess->m_colorVBO;
	sGShaderAttrib* lPositionAttrib = &lProcess->m_positionAttrib;
	sGShaderAttrib* lColorAttrib = &lProcess->m_colorAttrib;

	GGLFW()->Init();
	GGLFW()->CreateWindow("WINDOW", 400, 400, "OpenGL | ReadyDev");
	GGLFW()->MakeContext("WINDOW");

	GOpenGL()->Enable(GL_LINE_SMOOTH);
	GOpenGL()->Hint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	GOpenGL()->Enable(GL_POINT_SMOOTH);
	GOpenGL()->Hint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	GOpenGL()->Enable(GL_BLEND);
	GOpenGL()->BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GGLew()->Experimental(TRUE);
	GGLew()->Init();

	GProcessOpenGLShader_Init();

	while(1) {
		int lRes = GGLFW()->WindowClose("WINDOW");
		if(lRes == 1) break;

		GProcessOpenGLShader_Update();

		GGLFW()->SwapBuffers("WINDOW");
		GGLFW()->PollEvents();
	}

	GShader()->DisableVertexAttribArray(lPositionAttrib);
	GShader()->DisableVertexAttribArray(lColorAttrib);
	GShader()->DeleteBuffer(lVertexVBO);
	GShader()->DeleteBuffer(lColorVBO);
	GShader()->DeleteVertexArray(lShaderVAO);
	GShader()->DeleteProgram(lShader);

	GGLFW()->DestroyWindow("WINDOW");
	GGLFW()->Terminate();
}
//===============================================
static void GProcessOpenGLShader_Init() {
	GProcessOpenGLShaderO* lProcess = m_GProcessOpenGLShaderO->m_child;
	sGShader* lShader = &lProcess->m_shader;
	sGShaderVAO* lShaderVAO = &lProcess->m_shaderVAO;
	sGShaderVBO* lVertexVBO = &lProcess->m_vertexVBO;
	sGShaderVBO* lColorVBO = &lProcess->m_colorVBO;
	sGShaderAttrib* lPositionAttrib = &lProcess->m_positionAttrib;
	sGShaderAttrib* lColorAttrib = &lProcess->m_colorAttrib;

	sGShaderItem lVertexShader = {
			"../data/shader/simple.vert", 0, 0, GL_VERTEX_SHADER
	};
	sGShaderItem lFragmentShader = {
			"../data/shader/simple.frag", 0, 0, GL_FRAGMENT_SHADER
	};
	*lShader = (sGShader){
			0,
			&lVertexShader,
			&lFragmentShader
	};
	sGShaderFrag lColorFrag = {
			&lShader->programId, 0, "color_out"
	};
	*lShaderVAO = (sGShaderVAO){
			1, 0
	};
	double lVertexData[] = {
			-0.5, -0.5, 0.0,
			0.5, -0.5, 0.0,
			0.5, 0.5, 0.0,
			-0.5, -0.5, 0.0,
			0.5, 0.5, 0.0,
			-0.5, 0.5, 0.0
	};
	double lColorData[]={
			0.0, 0.0, 1.0,
			0.0, 1.0, 0.0,
			1.0, 0.0, 0.0,
			0.0, 0.0, 1.0,
			1.0, 0.0, 0.0,
			0.0, 1.0, 0.0
	};
	*lVertexVBO = (sGShaderVBO){
			1, 0, lVertexData, sizeof(lVertexData)
	};
	*lColorVBO = (sGShaderVBO){
			1, 0, lColorData, sizeof(lColorData)
	};
	*lPositionAttrib = (sGShaderAttrib){
			&lShader->programId,
			"position",
			0, 3, &lVertexVBO->vboId
	};
	*lColorAttrib = (sGShaderAttrib){
			&lShader->programId,
			"color_in",
			0, 3, &lColorVBO->vboId
	};

	GShader()->LoadShader(lShader);
	GShader()->BindFragDataLocation(&lColorFrag);
	GShader()->BindVertexArray(lShaderVAO);
	GShader()->BindBuffer(lVertexVBO);
	GShader()->BindBuffer(lColorVBO);
	GShader()->EnableVertexAttribArray(lPositionAttrib);
	GShader()->EnableVertexAttribArray(lColorAttrib);
	GShader()->UseProgram(lShader);
}
//===============================================
static void GProcessOpenGLShader_Update() {
	GOpenGL()->Clear(GL_COLOR_BUFFER_BIT);
	GOpenGL()->ClearColor(0.0, 0.0, 0.0, 1.0);

	sGShaderArray lShaderArray = {
			GL_TRIANGLES, 0, 6
	};

	GOpenGL()->DrawArray(lShaderArray);
}
//===============================================
