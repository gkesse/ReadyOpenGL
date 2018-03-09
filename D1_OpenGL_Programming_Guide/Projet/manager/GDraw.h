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
class GDraw {
public:
	GDraw();
	~GDraw();
	
public:
	static GDraw* Instance();
	void draw(const int& index = 0);
	void drawBackground();
	void drawTriangle();
	
private:
	static GDraw* m_instance;
};
//================================================
#endif
//================================================
