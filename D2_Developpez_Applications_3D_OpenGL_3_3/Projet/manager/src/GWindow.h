//================================================
#ifndef _GWindow_
#define _GWindow_
//================================================
#include <iostream>
#include <string>
//================================================
#include <SDL2/SDL.h>
#include <GL/glew.h>
#define GL3_PROTOTYPES 1
//#include <GL3/gl3.h>
//================================================
using namespace std;
//================================================
class GWindow {
public:
	GWindow();
	~GWindow();
	
public:
	static GWindow* Instance();
	void initSdl();
	void initGlew();
	void createWindow();
	void createContext();
	void run();
	void release();
	
private:
	static GWindow* m_instance;
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
