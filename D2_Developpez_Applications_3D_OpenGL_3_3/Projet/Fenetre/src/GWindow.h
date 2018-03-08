//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include <iostream>
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
	void init();
	void attribute();
	void create();
	void context();
	void glew();
	void draw();
	void run();
	void release();
	
private:
	static GWindow* m_instance;
	SDL_Window* m_window;
	string m_title;
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	Uint32 m_flags;
	SDL_GLContext m_context;
	SDL_Event m_events;
	bool m_run;
};
//===============================================
#endif
//===============================================
