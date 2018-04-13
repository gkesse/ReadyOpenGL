//================================================
#ifndef _GDraw_
#define _GDraw_
//================================================
#include <iostream>
#include <string>
//================================================
#include <GL/glew.h>
//================================================
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
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
	void setWindowSize(const int& w, const int& h);
	
private:
	static GDraw* m_instance;
	
protected:
	int m_w;
	int m_h;
};
//================================================
#endif
//================================================
