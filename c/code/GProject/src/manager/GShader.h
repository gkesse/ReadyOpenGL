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
	void (*LoadCode)(sGShaderItem* shader);
	void (*CreateShader)(sGShaderItem* shader);
	void (*CompileCode)(sGShaderItem* shader);
	void (*CheckCompileCode)(sGShaderItem* shader);
	void (*CreateProgram)(sGShader* shader);
	void (*LinkProgram)(sGShader* shader);
	void (*CheckLinkProgram)(sGShader* shader);
	void (*DeleteShader)(sGShader* shader);
	void (*UseProgram)(sGShader* shader);
	void (*DeleteProgram)(sGShader* shader);
	void (*BindFragDataLocation)(sGShaderFrag* shaderFrag);
	void (*GetUniformLocation)(sGShaderUniform* shader);
	void (*BindVertexArray)(sGShaderVAO* shader);
	void (*DeleteVertexArray)(sGShaderVAO* shader);
	void (*BindBuffer)(sGShaderVBO* shader);
	void (*DeleteBuffer)(sGShaderVBO* shader);
	void (*EnableVertexAttribArray)(sGShaderAttrib* shader);
	void (*DisableVertexAttribArray)(sGShaderAttrib* shader);
	void (*LoadShader)(sGShader* shader);
};
//===============================================
GShaderO* GShader_New();
void GShader_Delete();
GShaderO* GShader();
//===============================================
#endif
//===============================================
