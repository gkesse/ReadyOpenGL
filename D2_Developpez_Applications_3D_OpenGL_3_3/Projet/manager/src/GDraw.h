//================================================
#ifndef _GDraw_
#define _GDraw_
//================================================
#include <iostream>
#include <string>
//================================================
#include <GL/glew.h>
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
	virtual void initDraw() = 0;
	virtual void drawShape() = 0;
	
private:
	static GDraw* m_instance;
};
//================================================
#endif
//================================================
