//================================================
#ifdef WIN32
#include <GL/glew.h>
//================================================
// On initialise GLEW
GLenum initialisationGLEW( glewInit() );
// Si l'initialisation a échouée :
if(initialisationGLEW != GLEW_OK)
{
	// On affiche l'erreur grâce à la fonction :
	glewGetErrorString(GLenum code)
	std::cout << "Erreur d'initialisation de GLEW : " <<
	glewGetErrorString(initialisationGLEW) << std::endl;
	// On quitte la SDL
	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return -1;
}
//================================================
