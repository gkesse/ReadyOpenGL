//================================================
#include "GWindow.h"
#include "GShader.h"
//================================================
int main(int argc, char** argv) {
	cout << "### Start GProject\n";
	GWindow::Instance()->initGlfw();
	GWindow::Instance()->createWindow();
	GWindow::Instance()->createContext();
	GWindow::Instance()->initGl3w();
	GShader::Instance()->readShader();
	GWindow::Instance()->run();
	GWindow::Instance()->release();
	cout << "### End GProject\n";
	return 0;
}
//================================================
