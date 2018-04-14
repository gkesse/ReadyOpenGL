//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include <iostream>
#include <string>
//===============================================
#include <SDL2/SDL.h>
#include <GL/glew.h>
//===============================================
using namespace std;
//===============================================
class GWindow {
public:
    GWindow();
    ~GWindow();

public:
    static GWindow* Instance();
    void show();
    void setBackground();

private:
    static GWindow* m_instance;
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    string m_title;
    SDL_Window* m_window;
};
//===============================================
#endif
//===============================================
