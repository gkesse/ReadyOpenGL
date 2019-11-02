//===============================================
#ifndef _GShader_
#define _GShader_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GShaderO GShaderO;
//===============================================
struct _GShaderO {
	void (*Delete)();
	void (*LoadCode)(sGShader* shader);
	void (*CreateShader)(sGShader* shader);
	void (*CompileCode)(sGShader* shader);
	void (*CheckCompileCode)(sGShader* shader);
	void (*CreateProgram)(sGShader* shader);
	void (*LinkProgram)(sGShader* shader);
	void (*CheckLinkProgram)(sGShader* shader);
	void (*DeleteShader)(sGShader* shader);
	void (*UseProgram)(sGShader* shader);
	void (*BindVertexArray)(sGShader* shader);
	void (*GenBuffers)(sGShader* shader);
	void (*LoadShader)(sGShader* shader);
};
//===============================================
GShaderO* GShader_New();
void GShader_Delete();
GShaderO* GShader();
//===============================================
#endif
//===============================================
