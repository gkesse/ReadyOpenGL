//================================================
#ifndef _GDraw_
#define _GDraw_
//================================================
#include <iostream>
#include <string>
//================================================
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
//================================================
using namespace std;
//================================================
#define BUFFER_OFFSET(a) ((void*)(a))
//================================================
class GDraw {
public:
	GDraw();
	~GDraw();
	
public:
	static GDraw* Instance();
	void draw();
	void drawBackground();
	virtual void drawShape() = 0;
	
private:
	static GDraw* m_instance;
};
//================================================
#endif
//================================================
