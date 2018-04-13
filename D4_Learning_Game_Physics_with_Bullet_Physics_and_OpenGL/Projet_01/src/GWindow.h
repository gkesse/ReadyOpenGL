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
    static void runDisplay();

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
