//================================================
#ifdef WIN32
#include <GL/glew.h>
#else
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>
#endif
#include <SDL2/SDL.h>
#include <iostream>
//================================================
int main(int argc, char **argv)
{
	// Notre fen�tre
	SDL_Window* fenetre(0);
	SDL_GLContext contexteOpenGL(0);
	SDL_Event evenements;
	bool terminer(false);
	// Initialisation de la SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : "
		<< SDL_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}
	// Version d'OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	// Cr�ation de la fen�tre
	fenetre = SDL_CreateWindow("Test SDL 2.0",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
	SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(fenetre == 0)
	{
		std::cout << "Erreur lors de la creation de la fenetre : "
		<< SDL_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}
	// Cr�ation du contexte OpenGL
	contexteOpenGL = SDL_GL_CreateContext(fenetre);
	if(contexteOpenGL == 0)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(fenetre);
		SDL_Quit();
		return -1;
	}
#ifdef WIN32
	// On initialise GLEW
	GLenum initialisationGLEW( glewInit() );
	// Si l'initialisation a �chou�e :
	if(initialisationGLEW != GLEW_OK)
	{
		// On affiche l'erreur gr�ce � la fonction : glewGetErrorString(GLenum code)
		std::cout << "Erreur d'initialisation de GLEW : " <<
		glewGetErrorString(initialisationGLEW) << std::endl;
		// On quitte la SDL
		SDL_GL_DeleteContext(contexteOpenGL);
		SDL_DestroyWindow(fenetre);
		SDL_Quit();
		return -1;
	}
#endif
	// Vertices et coordonn�es
	float vertices[] = {
		0.0, 0.0, 0.5, 0.0, 0.0, 0.5, // Triangle 1
		-0.8, -0.8, -0.3, -0.8, -0.8, -0.3}; // Triangle 2
	// Boucle principale
	while(!terminer)
	{
		// Gestion des �v�nements
		SDL_WaitEvent(&evenements);
		if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
		terminer = true;
		// Nettoyage de l'�cran
		glClear(GL_COLOR_BUFFER_BIT);
		// On remplie puis on active le tableau Vertex Attrib 0
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);
		// On affiche le triangle
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// On d�sactive le tableau Vertex Attrib puisque l'on n'en a plus besoin
		glDisableVertexAttribArray(0);
		// Actualisation de la fen�tre
		SDL_GL_SwapWindow(fenetre);
	}
	// On quitte la SDL
	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}
//================================================
