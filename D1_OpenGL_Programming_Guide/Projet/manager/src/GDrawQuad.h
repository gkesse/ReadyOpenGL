//================================================
#ifndef _GDrawQuad_
#define _GDrawQuad_
//================================================
#include "GDraw.h"
//================================================
class GDrawQuad : public GDraw {
public:
	GDrawQuad();
	~GDrawQuad();
	
public:
	static GDrawQuad* Instance();
	void drawShape();
	
private:
	static GDrawQuad* m_instance;
};
//================================================
#endif
//================================================
