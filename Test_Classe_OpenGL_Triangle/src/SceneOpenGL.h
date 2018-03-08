//===============================================
#ifndef _SceneOpenGL_
#define _SceneOpenGL_
//===============================================
#include <iostream>
//===============================================
#include <SDL2/SDL.h>
#include <GL/glew.h>
//===============================================
using namespace std;
//===============================================
class SceneOpenGL 
{
public:
	SceneOpenGL(std::string titreFenetre, int largeurFenetre, int hauteurFenetre);
	~SceneOpenGL();
	bool initialiserFenetre();
	bool initGL();
	void bouclePrincipale();
	
private:
	std::string m_titreFenetre;
	int m_largeurFenetre;
	int m_hauteurFenetre;
	SDL_Window* m_fenetre;
	SDL_GLContext m_contexteOpenGL;
	SDL_Event m_evenements;
};
//===============================================
#endif
//===============================================
