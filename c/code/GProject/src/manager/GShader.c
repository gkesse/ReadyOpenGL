//===============================================
#include "GShader.h"
#include "GFile2.h"
#include "GConsole.h"
//===============================================
static GShaderO* m_GShaderO = 0;
//===============================================
static void GShader_LoadCode(sGShader* shader);
static void GShader_CreateShader(sGShader* shader);
static void GShader_CompileCode(sGShader* shader);
static void GShader_CheckCompileCode(sGShader* shader);
static void GShader_CreateProgram(sGShader* shader);
static void GShader_LinkProgram(sGShader* shader);
static void GShader_CheckLinkProgram(sGShader* shader);
static void GShader_DeleteShader(sGShader* shader);
static void GShader_UseProgram(sGShader* shader);
static void GShader_BindVertexArray(sGShader* shader);
static void GShader_BindBuffer(sGShader* shader);
static void GShader_AttribPointer(sGShader* shader);
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
	lObj->BindVertexArray = GShader_BindVertexArray;
	lObj->BindBuffer = GShader_BindBuffer;
	lObj->AttribPointer = GShader_AttribPointer;
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
static void GShader_LoadCode(sGShader* shader) {
	GConsole()->Print("GShader_LoadCode\n");
	int i = 0;
	while(1) {
		sGShaderItem* lShader = &shader->shaderItem[i++];
		if(lShader->onFlag == FALSE) break;
		GFile2()->Exist(lShader->filename);
		GFile2()->Open(lShader->shaderName, lShader->filename, "r");
		int lSize = GFile2()->fSize(lShader->shaderName);
		char* lData = (char*)malloc(sizeof(char)*(lSize + 1));
		GFile2()->fRead(lShader->shaderName, lData, lSize);
		GFile2()->Close(lShader->shaderName);
		lShader->shaderCode = lData;
		GConsole()->Print("%s:\n%s\n", lShader->shaderName, lShader->shaderCode);
	}
}
//===============================================
static void GShader_CreateShader(sGShader* shader) {
	int i = 0;
	while(1) {
		sGShaderItem* lShader = &shader->shaderItem[i++];
		if(lShader->onFlag == FALSE) break;
		lShader->shaderId = glCreateShader(lShader->shaderType);
	}
}
//===============================================
static void GShader_CompileCode(sGShader* shader) {
	int i = 0;
	while(1) {
		sGShaderItem* lShader = &shader->shaderItem[i++];
		if(lShader->onFlag == FALSE) break;
		const char* lShaderCode = lShader->shaderCode;
		glShaderSource(lShader->shaderId, 1, &lShaderCode, 0);
		glCompileShader(lShader->shaderId);
	}
}
//===============================================
static void GShader_CheckCompileCode(sGShader* shader) {
	int i = 0;
	while(1) {
		sGShaderItem* lShader = &shader->shaderItem[i++];
		if(lShader->onFlag == FALSE) break;
		int lResult;
		int lLength;
		glGetShaderiv(lShader->shaderId, GL_COMPILE_STATUS, &lResult);
		glGetShaderiv(lShader->shaderId, GL_INFO_LOG_LENGTH, &lLength);
		if(lLength > 0) {
			char* lErrorMsg = (char*)malloc(sizeof(char)*(lLength + 1));
			glGetShaderInfoLog(lShader->shaderId, lLength, NULL, lErrorMsg);
			GConsole()->Print("glGetShaderInfoLog: %s: %s\n", lShader->shaderName, lErrorMsg);
			free(lErrorMsg);
		}
	}
}
//===============================================
static void GShader_CreateProgram(sGShader* shader) {
	shader->programId = glCreateProgram();
}
//===============================================
static void GShader_LinkProgram(sGShader* shader) {
	int i = 0;
	while(1) {
		sGShaderItem* lShader = &shader->shaderItem[i++];
		if(lShader->onFlag == FALSE) break;
		glAttachShader(shader->programId, lShader->shaderId);
	}
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
	int i = 0;
	while(1) {
		sGShaderItem* lShader = &shader->shaderItem[i++];
		if(lShader->onFlag == FALSE) break;
		glDeleteShader(lShader->shaderId);
		free(lShader->shaderCode);
		lShader->shaderCode = 0;
	}
}
//===============================================
static void GShader_UseProgram(sGShader* shader) {
	int i = 0;
	while(1) {
		sGShaderFrag* lShaderFrag = &shader->shaderFrag[i++];
		if(lShaderFrag->onFlag == FALSE) break;
		glBindFragDataLocation(shader->programId, lShaderFrag->colorNumber, lShaderFrag->colorName);
	}
	glUseProgram(shader->programId);
}
//===============================================
static void GShader_BindVertexArray(sGShader* shader) {
	int i = 0;
	while(1) {
		sGShaderVAO* lShaderVAO = &shader->shaderVAO[i++];
		if(lShaderVAO->onFlag == FALSE) break;
		uint lArray;
		glGenVertexArrays(lShaderVAO->nVertex, &lArray);
		glBindVertexArray(lArray);
	}
}
//===============================================
static void GShader_BindBuffer(sGShader* shader) {
	int i = 0;
	while(1) {
		sGShaderVBO* lShaderVBO = &shader->shaderVBO[i++];
		if(lShaderVBO->onFlag == FALSE) break;
		glGenBuffers(lShaderVBO->nBuffer, &lShaderVBO->bufferId);
		glBindBuffer(GL_ARRAY_BUFFER, lShaderVBO->bufferId);
		glBufferData(GL_ARRAY_BUFFER, lShaderVBO->bufferSize, lShaderVBO->bufferData, GL_STATIC_DRAW);
	}
}
//===============================================
static void GShader_AttribPointer(sGShader* shader) {
	int i = 0;
	while(1) {
		sGShaderAttrib* lShaderAttrib = &shader->shaderAttrib[i++];
		if(lShaderAttrib->onFlag == FALSE) break;
	    lShaderAttrib->attribId = glGetAttribLocation(shader->programId, lShaderAttrib->attribName);
	    glEnableVertexAttribArray(lShaderAttrib->attribId);
		glBindBuffer(GL_ARRAY_BUFFER, *lShaderAttrib->bufferId);
		glVertexAttribPointer(lShaderAttrib->attribId, lShaderAttrib->attribSize, GL_DOUBLE, GL_FALSE, 0, GPOINTER_NULL);
	}
}
//===============================================
static void GShader_LoadShader(sGShader* shader) {
	GShader()->LoadCode(shader);
	GShader()->CreateShader(shader);
	GShader()->CompileCode(shader);
	GShader()->CheckCompileCode(shader);
	GShader()->CreateProgram(shader);
	GShader()->LinkProgram(shader);
	GShader()->CheckLinkProgram(shader);
	GShader()->DeleteShader(shader);
	GShader()->UseProgram(shader);
	GShader()->BindVertexArray(shader);
	GShader()->BindBuffer(shader);
	GShader()->AttribPointer(shader);
}
//===============================================
