//================================================
#ifndef _GWindow_
#define _GWindow_
//================================================
#include <iostream>
#include <string>
//================================================
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
//================================================
using namespace std;
//================================================
class GWindow {
public:
	GWindow();
	~GWindow();
	
public:
	static GWindow* Instance();
	void initGlfw();
	void createWindow();
	void createContext();
	void initGl3w();
	void run();
	void release();
	
private:
	static GWindow* m_instance;
	string m_title;
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	GLFWwindow* m_window;
	bool m_run;
};
//================================================
#endif
//================================================
