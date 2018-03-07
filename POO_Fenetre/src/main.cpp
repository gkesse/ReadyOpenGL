//================================================
#include "GWindow.h"
//================================================
int main(int argc, char **argv) {
	cout << "### Start GProject\n";
	GWindow::Instance()->print();
	GWindow::Instance()->create();
	GWindow::Instance()->run();
	cout << "### End GProject\n";
	return 0;
}
//================================================
