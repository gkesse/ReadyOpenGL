//================================================
#include "GWindow.h"
//================================================
int main(int argc, char **argv) {
	cout << "### Start GProject\n";
	GWindow::Instance()->init();
	GWindow::Instance()->attribute();
	GWindow::Instance()->create();
	GWindow::Instance()->context();
	GWindow::Instance()->glew();
	GWindow::Instance()->run();
	GWindow::Instance()->release();
	cout << "### End GProject\n";
	return 0;
}
//================================================
