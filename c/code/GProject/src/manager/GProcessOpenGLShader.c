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

	sGDirection* lDirection = GOpenGL()->GetDirection();
	*lDirection = (sGDirection){
		{0.0, 0.0, -2.5},
		{-60.0, 0.0, 220.0},
		{10.0, 10.0, 10.0}
	};

	GOpenGL()->SetDirection(*lDirection);

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

	GGLFW()->DestroyWindow("WINDOW");
	GGLFW()->Terminate();
}
//===============================================
static void GProcessOpenGLShader_Init() {
	sGShaderItem lVertexShader = {
			"../data/shader/simple.vert", 0, 0, GL_VERTEX_SHADER
	};
	sGShaderItem lFragmentShader = {
			"../data/shader/simple.frag", 0, 0, GL_FRAGMENT_SHADER
	};
	sGShader lShader = {
			0,
			&lVertexShader,
			&lFragmentShader
	};
	GShader()->LoadShader(&lShader);

	sGShaderFrag lColorFrag = {
			&lShader.programId, 0, "color_out"
	};
	GShader()->BindFragDataLocation(&lColorFrag);

	sGShaderVAO lShaderVAO = {
			1, 0
	};
	GShader()->BindVertexArray(&lShaderVAO);

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
	sGShaderVBO lVertexVBO = {
			1, 0, lVertexData, sizeof(lVertexData)
	};
	sGShaderVBO lColorVBO = {
			1, 0, lColorData, sizeof(lColorData)
	};
	GShader()->BindBuffer(&lVertexVBO);
	GShader()->BindBuffer(&lColorVBO);

	sGShaderAttrib lPositionAttrib = {
			&lShader.programId,
			"position",
			0, 3, lVertexVBO.vboId
	};
	sGShaderAttrib lColorAttrib = {
			&lShader.programId,
			"color_in",
			0, 3, lColorVBO.vboId
	};
	GShader()->EnableVertexAttribArray(&lPositionAttrib);
	GShader()->EnableVertexAttribArray(&lColorAttrib);
	GShader()->UseProgram(&lShader);
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
