//================================================
#include "GWindowDraw.h"
//================================================
int main(int argc, char **argv) {
	cout << "### Start GProject\n";
	GWindowDraw::Instance()->initSdl();
	GWindowDraw::Instance()->initAttribute();
	GWindowDraw::Instance()->createWindow();
	GWindowDraw::Instance()->createContext(); 
	GWindowDraw::Instance()->initGlew();
	GWindowDraw::Instance()->run();
	GWindowDraw::Instance()->release();
	cout << "### End GProject\n";
	return 0;
}
//================================================
