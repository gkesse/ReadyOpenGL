//===============================================
#include "GWindow.h"
#include "GConfig.h"
//===============================================
int main(int argc, char** argv) {
    GConfig::Instance()->setData("WINDOW_TYPE", "OPENGL_SDL");
    GWindow::Instance()->show();
    return 0;
}
//===============================================
