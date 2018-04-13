//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include <GL/freeglut.h>
#include <QString>
//===============================================
class GWindow {
public:
    GWindow();
    ~GWindow();

public:
    static GWindow* Instance();
    void show(int* argc, char** argv);
    void setBackground();
    static void KeyboardFunc(unsigned char key, int w, int h);
    static void KeyboardUpFunc(unsigned char key, int w, int h);
    static void SpecialFunc(int key, int w, int h);
    static void SpecialUpFunc(int key, int w, int h);
    static void ReshapeFunc(int w, int h);
    static void IdleFunc();
    static void MouseFunc(int button, int state, int x, int y);
    static void MotionFunc(int x,int y);
    static void DisplayFunc();

private:
    static GWindow* m_instance;
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    QString m_title;
};
//===============================================
#endif
//===============================================
