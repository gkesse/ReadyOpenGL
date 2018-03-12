//================================================
#ifndef _GDrawTriangleDouble_
#define _GDrawTriangleDouble_
//================================================
#include "GDraw.h"
//================================================
class GDrawTriangleDouble : public GDraw {
public:
	GDrawTriangleDouble();
	~GDrawTriangleDouble();
	
public:
	static GDrawTriangleDouble* Instance();
	void initDraw();
	void drawShape();
	
private:
	static GDrawTriangleDouble* m_instance;
};
//================================================
#endif
//================================================
