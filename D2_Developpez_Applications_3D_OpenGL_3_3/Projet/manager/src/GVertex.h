//================================================
#ifndef _GVertex_
#define _GVertex_
//================================================
#include <iostream>
#include <string>
//================================================
#include <GL/gl.h>
//================================================
using namespace std;
//================================================
class GVertex {
public:
	GVertex();
	~GVertex();
	
public:
	static GVertex* Instance();
	void loadVertexGrid(GLfloat vertex[][2], const int& row);
	
private:
	static GVertex* m_instance;
};
//================================================
#endif
//================================================
