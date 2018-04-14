//===============================================
#include "GWindow.h"
#include "GWindowSDL.h"
#include "GWindowGLUT.h"
#include "GConfig.h"
//===============================================
GWindow::GWindow() {

}
//===============================================
GWindow::~GWindow() {

}
//===============================================
GWindow* GWindow::Instance() {
    string m_windowType = GConfig::Instance()->getData("WINDOW_TYPE");
    if(m_windowType == "OPENGL_GLUT") return GWindowGLUT::Instance();
    if(m_windowType == "OPENGL_SDL") return GWindowSDL::Instance();
    return 0;
}
//===============================================
