//================================================
#ifndef _GShader_
#define _GShader_
//================================================
#include <iostream>
#include <string>
//================================================
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
//================================================
using namespace std;
//================================================
typedef struct {
    GLenum type;
    string filename;
    GLuint shader;
} GShaderInfo;
//================================================
class GShader {
public:
	GShader();
	~GShader();
	
public:
	static GShader* Instance();
	GLuint loadShader(GShaderInfo* shaderInfo);
	GLchar* readShader(const string& filename);
	
private:
	static GShader* m_instance;
};
//================================================
#endif
//================================================
