//===============================================
#include "GProcessOpenGLTexture.h"
#include "GOpenGL.h"
#include "GGLFW.h"
#include "GGLew.h"
#include "GEvent.h"
#include "GShader.h"
#include "GTexture.h"
#include "GProjection.h"
#include "GCamera.h"
//===============================================
static GProcessO* m_GProcessOpenGLTextureO = 0;
//===============================================
static void GProcessOpenGLTexture_Run(int argc, char** argv);
static void GProcessOpenGLTexture_Init();
static void GProcessOpenGLTexture_Update();
static void GProcessOpenGLTexture_UpdateView();
//===============================================
GProcessO* GProcessOpenGLTexture_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLTextureO* lChild = (GProcessOpenGLTextureO*)malloc(sizeof(GProcessOpenGLTextureO));

	sGWindow* lWindow = &lChild->m_window;
	*lWindow = (sGWindow){
		"WINDOW", "OpenGL | ReadyDev", 400, 400, 0, 0
	};

	sGCamera* lCamera = &lChild->m_camera;
	*lCamera = (sGCamera){
		45.0, 0.1, 100.0
	};
	sGCameraView* lCameraView = &lChild->m_cameraView;
	*lCameraView = (sGCameraView){
		{0.0, 0.0, 2.0},
		{0.0, 0.0, 0.0},
		{0.0, -1.0, 0.0},
		{0.0, 0.0, -1.0}
	};

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLTexture_Delete;
	lParent->Run = GProcessOpenGLTexture_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLTexture_Delete() {
	GProcess_Delete(m_GProcessOpenGLTextureO);
	m_GProcessOpenGLTextureO = 0;
}
//===============================================
GProcessO* GProcessOpenGLTexture() {
	if(m_GProcessOpenGLTextureO == 0) {
		m_GProcessOpenGLTextureO = GProcessOpenGLTexture_New();
	}
	return m_GProcessOpenGLTextureO;
}
//===============================================
static void GProcessOpenGLTexture_Run(int argc, char** argv) {
	GProcessOpenGLTextureO* lProcess = m_GProcessOpenGLTextureO->m_child;
	sGWindow* lWindow = &lProcess->m_window;
	sGShader* lShader = &lProcess->m_shader;
	sGShaderVAO* lShaderVAO = &lProcess->m_shaderVAO;
	sGShaderVBO* lVertexVBO = &lProcess->m_vertexVBO;
	sGShaderVBO* lTextureVBO = &lProcess->m_textureVBO;
	sGShaderAttrib* lVertexAttrib = &lProcess->m_vertexAttrib;
	sGShaderAttrib* lTextureAttrib = &lProcess->m_textureAttrib;
	sGTexture* lTexture = &lProcess->m_texture;

	GGLFW()->Init();
	GGLFW()->CreateWindow2(lWindow);
	GGLFW()->MakeContext(lWindow->name);

	GOpenGL()->Enable(GL_LINE_SMOOTH);
	GOpenGL()->Hint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	GOpenGL()->Enable(GL_POINT_SMOOTH);
	GOpenGL()->Hint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	GOpenGL()->Enable(GL_BLEND);
	GOpenGL()->BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GGLew()->Experimental(TRUE);
	GGLew()->Init();

	GProcessOpenGLTexture_Init();

	while(1) {
		int lRes = GGLFW()->WindowClose(lWindow->name);
		if(lRes == 1) break;

		GProcessOpenGLTexture_Update();

		GGLFW()->SwapBuffers(lWindow->name);
		GGLFW()->PollEvents();
	}

	GShader()->DisableVertexAttribArray(lVertexAttrib);
	GShader()->DisableVertexAttribArray(lTextureAttrib);
	GShader()->DeleteBuffer(lVertexVBO);
	GShader()->DeleteBuffer(lTextureVBO);
	GShader()->DeleteVertexArray(lShaderVAO);
	GShader()->DeleteProgram(lShader);
	GTexture()->DeleteTexture(lTexture);

	GGLFW()->DestroyWindow(lWindow->name);
	GGLFW()->Terminate();
}
//===============================================
static void GProcessOpenGLTexture_Init() {
	GProcessOpenGLTextureO* lProcess = m_GProcessOpenGLTextureO->m_child;
	sGShader* lShader = &lProcess->m_shader;
	sGShaderVAO* lShaderVAO = &lProcess->m_shaderVAO;
	sGShaderVBO* lVertexVBO = &lProcess->m_vertexVBO;
	sGShaderVBO* lTextureVBO = &lProcess->m_textureVBO;
	sGShaderAttrib* lVertexAttrib = &lProcess->m_vertexAttrib;
	sGShaderAttrib* lTextureAttrib = &lProcess->m_textureAttrib;
	sGTexture* lTexture = &lProcess->m_texture;

	sGShaderItem lVertexShader = {
			"../data/shader/transform.vert", 0, 0, GL_VERTEX_SHADER
	};
	sGShaderItem lFragmentShader = {
			"../data/shader/texture.frag", 0, 0, GL_FRAGMENT_SHADER
	};
	*lShader = (sGShader){
		0,
		&lVertexShader,
		&lFragmentShader
	};
	sGTextureImage lTextureImage = {
			"../data/texture/texture.png", 0, 0, 0, SOIL_LOAD_RGBA
	};
	*lTexture = (sGTexture){
		lTextureImage,
		1, 0, GL_RGBA
	};
	*lShaderVAO = (sGShaderVAO){
		1, 0
	};
	sGShaderUniform lMatrixUniform = {
			&lShader->programId, 0, "MVP"
	};
	sGShaderUniform lTextureUniform = {
			&lShader->programId, 0, "textureSampler"
	};
	double lVertexData[] = {
			-0.5, -0.5, 0.0,
			0.5, -0.5, 0.0,
			0.5, 0.5, 0.0,
			-0.5, -0.5, 0.0,
			0.5, 0.5, 0.0,
			-0.5, 0.5, 0.0
	};
	double lTextureData[]= {
			1.0, 0.0,
			0.0, 0.0,
			0.0, 1.0,
			1.0, 0.0,
			0.0, 1.0,
			1.0, 1.0
	};
	*lVertexVBO = (sGShaderVBO){
		1, 0, lVertexData, sizeof(lVertexData)
	};
	*lTextureVBO = (sGShaderVBO){
		1, 0, lTextureData, sizeof(lTextureData)
	};
	sGTextureActive lTextureActive = {
			&lTexture->textureId, &lTextureUniform.uniformId
	};
	*lVertexAttrib = (sGShaderAttrib){
		&lShader->programId,
		"vertexPosition_modelspace",
		0, 3, &lVertexVBO->vboId
	};
	*lTextureAttrib = (sGShaderAttrib){
		&lShader->programId,
		"vertexUV",
		0, 2, &lTextureVBO->vboId
	};

	GShader()->LoadShader(lShader);
	GTexture()->LoadTexture(lTexture);
	GShader()->GetUniformLocation(&lMatrixUniform);
	GShader()->GetUniformLocation(&lTextureUniform);
	GShader()->BindVertexArray(lShaderVAO);
	GShader()->BindBuffer(lVertexVBO);
	GShader()->BindBuffer(lTextureVBO);
	GTexture()->ActiveTexture(&lTextureActive);
	GShader()->EnableVertexAttribArray(lVertexAttrib);
	GShader()->EnableVertexAttribArray(lTextureAttrib);
	GShader()->UseProgram(lShader);
}
//===============================================
static void GProcessOpenGLTexture_Update() {
	GOpenGL()->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GOpenGL()->ClearColor(0.0, 0.0, 0.0, 1.0);

	GProcessOpenGLTexture_UpdateView();

	sGShaderArray lShaderArray = {
			GL_TRIANGLES, 0, 6
	};

	GOpenGL()->DrawArray(lShaderArray);
}
//===============================================
static void GProcessOpenGLTexture_UpdateView() {
	GProcessOpenGLTextureO* lProcess = m_GProcessOpenGLTextureO->m_child;
	sGWindow* lWindow = &lProcess->m_window;
	sGCamera* lCamera = &lProcess->m_camera;
	sGCameraView* lCameraView = &lProcess->m_cameraView;
	sGProjection* lProjection = &lProcess->m_projection;

	GCamera()->SetRatio(lWindow->name, lCamera);
	GCamera()->SetCenter(lCameraView);
	GProjection()->SetModel(lProjection, GLM_MAT4_IDENTITY);
	GProjection()->SetProjection(lProjection, lCamera);
	GProjection()->SetView(lProjection, lCameraView);
	GProjection()->SetMVP(lProjection);
}
//===============================================
