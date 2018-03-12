//================================================
#include "GWindow.h"
//================================================
int main(int argc, char **argv) {
	cout << "### Start GProject\n";
	GWindow::Instance()->initSdl();
	GWindow::Instance()->initGlew();
	GWindow::Instance()->createWindow();
	GWindow::Instance()->createContext();
	GWindow::Instance()->run();
	GWindow::Instance()->release();
	cout << "### End GProject\n";
	return 0;
}
//================================================
