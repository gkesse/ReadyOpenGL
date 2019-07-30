//================================================
#ifndef _GGLfw_
#define _GGLfw_
//================================================
#include "GInclude.h"
//================================================
class GGLfw {
private:
	GGLfw();
	
public:
	~GGLfw();
	static GGLfw* Instance();
    void init();
    void createWindow(const string& windowName, const string& title, const int& w, const int& h);
    void makeContext(const string& windowName);
    bool closeWindow(const string& windowName);
    void frameBufferSize(const string& windowName, int* width, int* height);
    double getTime();
    void swapBuffers(const string& windowName);
    void pollEvents();
    void destroyWindow(const string& windowName);
    void terminate();

private:
	static GGLfw* m_instance;
    map<string, GLFWwindow*> m_windowMap;
};
//================================================
#endif
//================================================
