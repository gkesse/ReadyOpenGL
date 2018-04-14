//===============================================
#include "GWindow.h"
#include "GConfig.h"
//===============================================
int main(int argc, char** argv) {
    GConfig::Instance()->setData("WINDOW_TYPE", "OPENGL_GLUT");
    GWindow::Instance()->show(&argc, argv);
    return 0;
}
//===============================================
