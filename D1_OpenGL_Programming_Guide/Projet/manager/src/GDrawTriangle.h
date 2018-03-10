//================================================
#ifndef _GDrawTriangle_
#define _GDrawTriangle_
//================================================
#include "GDraw.h"
//================================================
class GDrawTriangle : public GDraw {
public:
	GDrawTriangle();
	~GDrawTriangle();
	
public:
	static GDrawTriangle* Instance();
	void drawShape();
	
private:
	static GDrawTriangle* m_instance;
};
//================================================
#endif
//================================================
