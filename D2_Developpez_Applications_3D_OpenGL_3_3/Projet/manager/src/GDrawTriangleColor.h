//================================================
#ifndef _GDrawTriangleColor_
#define _GDrawTriangleColor_
//================================================
#include "GDraw.h"
//================================================
class GDrawTriangleColor : public GDraw {
public:
	GDrawTriangleColor();
	~GDrawTriangleColor();
	
public:
	static GDrawTriangleColor* Instance();
	void initDraw();
	void drawShape();
	
private:
	static GDrawTriangleColor* m_instance;
	float m_vertices[3][2];
	GLuint m_program;
};
//================================================
#endif
//================================================
