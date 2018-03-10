//================================================
#ifndef _GWindowDraw_
#define _GWindowDraw_
//================================================
#include "GWindow.h"
//================================================
class GWindowDraw : public GWindow {
public:
	GWindowDraw();
	~GWindowDraw();
	
public:
	static GWindowDraw* Instance();
	void draw();
	
private:
	static GWindowDraw* m_instance;
};
//================================================
#endif
//================================================
