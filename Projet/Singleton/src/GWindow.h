//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include <iostream>
//===============================================
using namespace std;
//===============================================
class GWindow {
public:
	GWindow();
	~GWindow();
	
public:
	static GWindow* Instance();
	void showMessage();
	
private:
	static GWindow* m_window;
};
//===============================================
#endif
//===============================================
