//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include <iostream>
#include <string>
//===============================================
using namespace std;
//===============================================
class GWindow {
public:
    GWindow();
    ~GWindow();

public:
    static GWindow* Instance();
    virtual void show(int* argc=0, char** argv=0) = 0;

private:
    static GWindow* m_instance;
};
//===============================================
#endif
//===============================================
