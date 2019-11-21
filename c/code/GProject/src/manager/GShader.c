//===============================================
#include "GShader.h"
#include "GFile2.h"
#include "GConsole.h"
//===============================================
static GShaderO* m_GShaderO = 0;
//===============================================
static void GShader_LoadCode(sGShaderItem* shader);
static void GShader_CreateShader(sGShaderItem* shader);
static void GShader_CompileCode(sGShaderItem* shader);
static void GShader_CheckCompileCode(sGShaderItem* shader);
static void GShader_CreateProgram(sGShader* shader);
static void GShader_LinkProgram(sGShader* shader);
static void GShader_CheckLinkProgram(sGShader* shader);
static void GShader_DeleteShader(sGShader* shader);
static void GShader_UseProgram(sGShader* shader);
static void GShader_BindFragDataLocation(sGShaderFrag* shaderFrag);
static void GShader_GetUniformLocation(sGShaderUniform* shader);
static void GShader_BindVertexArray(sGShaderVAO* shader);
static void GShader_BindBuffer(sGShaderVBO* shader);
static void GShader_EnableVertexAttribArray(sGShaderAttrib* shader);
static void GShader_LoadShader(sGShader* shader);
//===============================================
GShaderO* GShader_New() {
	GShaderO* lObj = (GShaderO*)malloc(sizeof(GShaderO));
	lObj->Delete = GShader_Delete;
	lObj->LoadCode = GShader_LoadCode;
	lObj->CreateShader = GShader_CreateShader;
	lObj->CompileCode = GShader_CompileCode;
	lObj->CheckCompileCode = GShader_CheckCompileCode;
	lObj->CreateProgram = GShader_CreateProgram;
	lObj->LinkProgram = GShader_LinkProgram;
	lObj->CheckLinkProgram = GShader_CheckLinkProgram;
	lObj->DeleteShader = GShader_DeleteShader;
	lObj->UseProgram = GShader_UseProgram;
	lObj->BindFragDataLocation = GShader_BindFragDataLocation;
	lObj->GetUniformLocation = GShader_GetUniformLocation;
	lObj->BindVertexArray = GShader_BindVertexArray;
	lObj->BindBuffer = GShader_BindBuffer;
	lObj->EnableVertexAttribArray = GShader_EnableVertexAttribArray;
	lObj->LoadShader = GShader_LoadShader;
	return lObj;
}
//===============================================
void GShader_Delete() {
	GShaderO* lObj = GShader();
	if(lObj != 0) {
		free(lObj);
	}
	m_GShaderO = 0;
}
//===============================================
GShaderO* GShader() {
	if(m_GShaderO == 0) {
		m_GShaderO = GShader_New();
	}
	return m_GShaderO;
}
//===============================================
static void GShader_LoadCode(sGShaderItem* shader) {
	GFile2()->Exist(shader->filename);
	GFile2()->Open("SHADER", shader->filename, "r");
	int lSize = GFile2()->fSize("SHADER");
	char* lData = (char*)malloc(sizeof(char)*(lSize + 1));
	GFile2()->fRead("SHADER", lData, lSize);
	GFile2()->Close("SHADER");
	shader->shaderCode = lData;

}
//===============================================
static void GShader_CreateShader(sGShaderItem* shader) {
	shader->shaderId = glCreateShader(shader->shaderType);

}
//===============================================
static void GShader_CompileCode(sGShaderItem* shader) {
	const char* lShaderCode = shader->shaderCode;
	glShaderSource(shader->shaderId, 1, &lShaderCode, 0);
	glCompileShader(shader->shaderId);

}
//===============================================
static void GShader_CheckCompileCode(sGShaderItem* shader) {
	int lResult;
	int lLength;
	glGetShaderiv(shader->shaderId, GL_COMPILE_STATUS, &lResult);
	glGetShaderiv(shader->shaderId, GL_INFO_LOG_LENGTH, &lLength);
	if(lLength > 0) {
		char* lErrorMsg = (char*)malloc(sizeof(char)*(lLength + 1));
		glGetShaderInfoLog(shader->shaderId, lLength, NULL, lErrorMsg);
		GConsole()->Print("glGetShaderInfoLog: %s: %s\n", "SHADER", lErrorMsg);
		free(lErrorMsg);
	}
}
//===============================================
static void GShader_CreateProgram(sGShader* shader) {
	shader->programId = glCreateProgram();
}
//===============================================
static void GShader_LinkProgram(sGShader* shader) {
	glAttachShader(shader->programId, shader->vert->shaderId);
	glAttachShader(shader->programId, shader->frag->shaderId);
	glLinkProgram(shader->programId);
}
//===============================================
static void GShader_CheckLinkProgram(sGShader* shader) {
	int lResult;
	int lLength;
	glGetProgramiv(shader->programId, GL_LINK_STATUS, &lResult);
	glGetProgramiv(shader->programId, GL_INFO_LOG_LENGTH, &lLength);
	if(lLength > 0) {
		char* lErrorMsg = (char*)malloc(sizeof(char)*(lLength + 1));
		glGetProgramInfoLog(shader->programId, lLength, NULL, lErrorMsg);
		GConsole()->Print("glGetProgramInfoLog: %s\n", lErrorMsg);
		free(lErrorMsg);
	}
}
//===============================================
static void GShader_DeleteShader(sGShader* shader) {
	glDeleteShader(shader->vert->shaderId);
	glDeleteShader(shader->frag->shaderId);
	free(shader->vert->shaderCode);
	free(shader->frag->shaderCode);
}
//===============================================
static void GShader_UseProgram(sGShader* shader) {
	glUseProgram(shader->programId);
}
//===============================================
static void GShader_BindFragDataLocation(sGShaderFrag* shaderFrag) {
	glBindFragDataLocation(*shaderFrag->programId, shaderFrag->colorNumber, shaderFrag->colorName);
}
//===============================================
static void GShader_GetUniformLocation(sGShaderUniform* shader) {
	shader->uniformId = glGetUniformLocation(shader->programId, shader->uniformName);
}
//===============================================
static void GShader_BindVertexArray(sGShaderVAO* shaderVAO) {
	glGenVertexArrays(shaderVAO->nVAO, &shaderVAO->vaoId);
	glBindVertexArray(shaderVAO->vaoId);
}
//===============================================
static void GShader_BindBuffer(sGShaderVBO* shaderVBO) {
	glGenBuffers(shaderVBO->nVBO, &shaderVBO->vboId);
	glBindBuffer(GL_ARRAY_BUFFER, shaderVBO->vboId);
	glBufferData(GL_ARRAY_BUFFER, shaderVBO->vboSize, shaderVBO->vboData, GL_STATIC_DRAW);
}
//===============================================
static void GShader_EnableVertexAttribArray(sGShaderAttrib* shader) {
	shader->attribId = glGetAttribLocation(*shader->programId, shader->attribName);
	glEnableVertexAttribArray(shader->attribId);
	glBindBuffer(GL_ARRAY_BUFFER, *shader->vboId);
	glVertexAttribPointer(shader->attribId, shader->attribSize, GL_DOUBLE, GL_FALSE, 0, GPOINTER_NULL);
}
//===============================================
static void GShader_LoadShader(sGShader* shader) {
	GShader()->LoadCode(shader->vert);
	GShader()->LoadCode(shader->frag);
	GShader()->CreateShader(shader->vert);
	GShader()->CreateShader(shader->frag);
	GShader()->CompileCode(shader->vert);
	GShader()->CompileCode(shader->frag);
	GShader()->CheckCompileCode(shader->vert);
	GShader()->CheckCompileCode(shader->frag);
	GShader()->CreateProgram(shader);
	GShader()->LinkProgram(shader);
	GShader()->CheckLinkProgram(shader);
	GShader()->DeleteShader(shader);
}
//===============================================
