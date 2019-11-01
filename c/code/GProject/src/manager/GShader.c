//===============================================
#include "GShader.h"
#include "GFile2.h"
#include "GConsole.h"
//===============================================
typedef char* GCHAR_PTR;
typedef sGShaderItem* GSHADERITEM_PTR;
//===============================================
GDECLARE_MAP(GShader, GCHAR_PTR, GSHADERITEM_PTR)
GDEFINE_MAP(GShader, GCHAR_PTR, GSHADERITEM_PTR)
//===============================================
static GShaderO* m_GShaderO = 0;
//===============================================
static void GShader_SetShader(char* shaderName, sGShaderItem* shader);
static void GShader_SetProgramId(int* programId);
static void GShader_LoadCode(char* shaderName);
static void GShader_CompileCode(char* shaderName);
static void GShader_CheckCompileCode(char* shaderName);
static void GShader_CreateProgram();
static void GShader_LinkProgram(char* vertexName, char* fragmentName);
static void GShader_CheckLinkProgram();
static void GShader_DeleteShader(char* shaderName);
static void GShader_LoadShader(char* vertexName, char* fragmentName);
//===============================================
#if defined(__WIN32)
static int GShader_MapEqual(char* key1, char* key2);
#endif
//===============================================
GShaderO* GShader_New() {
    GShaderO* lObj = (GShaderO*)malloc(sizeof(GShaderO));

    lObj->m_shaderMap = GMap_New_GShader_GCHAR_PTR_GSHADERITEM_PTR();

    lObj->Delete = GShader_Delete;
    lObj->SetShader = GShader_SetShader;
    lObj->SetProgramId = GShader_SetProgramId;
    lObj->LoadCode = GShader_LoadCode;
    lObj->CompileCode = GShader_CompileCode;
    lObj->CheckCompileCode = GShader_CheckCompileCode;
    lObj->CreateProgram = GShader_CreateProgram;
    lObj->LinkProgram = GShader_LinkProgram;
    lObj->CheckLinkProgram = GShader_CheckLinkProgram;
    lObj->DeleteShader = GShader_DeleteShader;
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
static void GShader_SetShader(char* shaderName, sGShaderItem* shader) {
    GMapO(GShader, GCHAR_PTR, GSHADERITEM_PTR)* lShaderMap = m_GShaderO->m_shaderMap;
    lShaderMap->SetData(lShaderMap, shaderName, shader, GShader_MapEqual);
}
//===============================================
static void GShader_SetProgramId(int* programId) {
    m_GShaderO->m_programId = programId;
}
//===============================================
static void GShader_LoadCode(char* shaderName) {
    GMapO(GShader, GCHAR_PTR, GSHADERITEM_PTR)* lShaderMap = m_GShaderO->m_shaderMap;
    sGShaderItem* lShader = lShaderMap->GetData(lShaderMap, shaderName, GShader_MapEqual);
    GFile2()->Exist(lShader->filename);
    GFile2()->Open(shaderName, lShader->filename, "r");
    int lSize = GFile2()->fSize(shaderName);
    char* lData = (char*)malloc(sizeof(char)*(lSize + 1));
    GFile2()->fRead(shaderName, lData, lSize);
    GFile2()->Close(shaderName);
    lShader->shaderCode = lData;
}
//===============================================
static void GShader_CompileCode(char* shaderName) {
    GMapO(GShader, GCHAR_PTR, GSHADERITEM_PTR)* lShaderMap = m_GShaderO->m_shaderMap;
    sGShaderItem* lShader = lShaderMap->GetData(lShaderMap, shaderName, GShader_MapEqual);
    const char* lShaderCode = lShader->shaderCode;
    int lShaderId = lShader->shaderId;
    glShaderSource(lShaderId, 1, &lShaderCode, 0);
    glCompileShader(lShaderId);
}
//===============================================
static void GShader_CheckCompileCode(char* shaderName) {
    GMapO(GShader, GCHAR_PTR, GSHADERITEM_PTR)* lShaderMap = m_GShaderO->m_shaderMap;
    sGShaderItem* lShader = lShaderMap->GetData(lShaderMap, shaderName, GShader_MapEqual);
    int lResult;
    int lLength;
    int lShaderId = lShader->shaderId;
    glGetShaderiv(lShaderId, GL_COMPILE_STATUS, &lResult);
    glGetShaderiv(lShaderId, GL_INFO_LOG_LENGTH, &lLength);
    if(lLength > 0) {
        char* lErrorMsg = (char*)malloc(sizeof(char)*(lLength + 1));
        glGetShaderInfoLog(lShaderId, lLength, NULL, lErrorMsg);
        GConsole()->Print("Error GShader_Check: %s\n", lErrorMsg);
        free(lErrorMsg);
        exit(0);
    }
}
//===============================================
static void GShader_DeleteShader(char* shaderName) {
    GMapO(GShader, GCHAR_PTR, GSHADERITEM_PTR)* lShaderMap = m_GShaderO->m_shaderMap;
    sGShaderItem* lShader = lShaderMap->GetData(lShaderMap, shaderName, GShader_MapEqual);
    int lShaderId = lShader->shaderId;
	glDeleteShader(lShaderId);
	free(lShader->shaderCode);
}
//===============================================
static void GShader_CreateProgram() {
    int lProgramId = glCreateProgram();
    *m_GShaderO->m_programId = lProgramId;
}
//===============================================
static void GShader_LinkProgram(char* vertexName, char* fragmentName) {
    GMapO(GShader, GCHAR_PTR, GSHADERITEM_PTR)* lShaderMap = m_GShaderO->m_shaderMap;
    sGShaderItem* lVertexShader = lShaderMap->GetData(lShaderMap, vertexName, GShader_MapEqual);
    sGShaderItem* lFragmentShader = lShaderMap->GetData(lShaderMap, fragmentName, GShader_MapEqual);
    int lVertexId = lVertexShader->shaderId;
    int lFragmentId = lFragmentShader->shaderId;
    int lProgramId = *m_GShaderO->m_programId;
    glAttachShader(lProgramId, lVertexId);
    glAttachShader(lProgramId, lFragmentId);
    glLinkProgram(lProgramId);
}
//===============================================
static void GShader_CheckLinkProgram() {
    int lProgramId = *m_GShaderO->m_programId;
    int lResult;
    int lLength;
    glGetProgramiv(lProgramId, GL_LINK_STATUS, &lResult);
    glGetProgramiv(lProgramId, GL_INFO_LOG_LENGTH, &lLength);
	if(lLength > 0) {
		char* lErrorMsg = (char*)malloc(sizeof(char)*(lLength + 1));
		glGetProgramInfoLog(lProgramId, lLength, NULL, lErrorMsg);
		GConsole()->Print("Error GShader_CheckLinkProgram: %s\n", lErrorMsg);
		free(lErrorMsg);
		exit(0);
	}

}
//===============================================
static void GShader_LoadShader(char* vertexName, char* fragmentName) {
	GShader()->LoadCode(vertexName);
	GShader()->CompileCode(vertexName);
	GShader()->CheckCompileCode(vertexName);

	GShader()->LoadCode(fragmentName);
	GShader()->CompileCode(fragmentName);
	GShader()->CheckCompileCode(fragmentName);

	GShader()->CreateProgram();
	GShader()->LinkProgram(vertexName, fragmentName);
	GShader()->CheckLinkProgram();

	GShader()->DeleteShader(vertexName);
	GShader()->DeleteShader(fragmentName);
}
//===============================================
#if defined(__WIN32)
static int GShader_MapEqual(char* key1, char* key2) {
    int lStrcmp = strcmp(key1, key2);
    if(lStrcmp == 0) return TRUE;
    return FALSE;
}
#endif
//===============================================
