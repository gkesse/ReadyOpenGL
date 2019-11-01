//===============================================
#ifndef _GShader_
#define _GShader_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GShaderO GShaderO;
typedef struct _GMapO_GShader_GCHAR_PTR_GSHADERITEM_PTR GMapO_GShader_GCHAR_PTR_GSHADERITEM_PTR;
//===============================================
struct _GShaderO {
	void (*Delete)();
	void (*SetShader)(char* shaderName, sGShaderItem* shader);
	void (*SetProgramId)(int* programId);
	void (*LoadCode)(char* shaderName);
	void (*CompileCode)(char* shaderName);
	void (*CheckCompileCode)(char* shaderName);
	void (*CreateProgram)();
	void (*LinkProgram)(char* vertexName, char* fragmentName);
	void (*CheckLinkProgram)();
	void (*DeleteShader)(char* shaderName);
	void (*LoadShader)(char* vertexName, char* fragmentName);
	GMapO(GShader, GCHAR_PTR, GSHADERITEM_PTR)* m_shaderMap;
	int* m_programId;
};
//===============================================
GShaderO* GShader_New();
void GShader_Delete();
GShaderO* GShader();
//===============================================
#endif
//===============================================
