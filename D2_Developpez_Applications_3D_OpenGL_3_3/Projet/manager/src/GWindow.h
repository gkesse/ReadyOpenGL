//================================================
#ifndef _GWindow_
#define _GWindow_
//================================================
#include <iostream>
#include <string>
//================================================
#include <SDL2/SDL.h>
#include <GL/glew.h>
//================================================
using namespace std;
//================================================
class GWindow {
public:
	GWindow();
	~GWindow();
	
public:
	void initSdl();
	void initGlew();
	void initAttribute();
	void createWindow();
	void createContext();
	void run();
	virtual void draw() = 0;
	void release();
	
protected:
	string m_title;
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	SDL_Window* m_window;
	SDL_Event m_events;
	SDL_GLContext m_context;
	bool m_run;
};
//================================================
#endif
//================================================
