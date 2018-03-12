//================================================
#ifndef _GDrawLine_
#define _GDrawLine_
//================================================
#include "GDraw.h"
//================================================
class GDrawLine : public GDraw {
public:
	GDrawLine();
	~GDrawLine();
	
public:
	static GDrawLine* Instance();
	void drawShape();
	
private:
	static GDrawLine* m_instance;
};
//================================================
#endif
//================================================
