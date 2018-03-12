//================================================
#include "GWindowDraw.h"
//================================================
int main(int argc, char** argv) {
	cout << "### Start GProject\n";
	GWindowDraw::Instance()->initGlfw();
	GWindowDraw::Instance()->createWindow();
	GWindowDraw::Instance()->createContext();
	GWindowDraw::Instance()->initGl3w();
	GWindowDraw::Instance()->run();
	GWindowDraw::Instance()->release();
	cout << "### End GProject\n";
	return 0;
}
//================================================
