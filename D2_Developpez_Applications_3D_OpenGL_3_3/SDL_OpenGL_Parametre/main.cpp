//================================================
// contexte OpenGL
SDL_GLContext contexteOpenGL;
//================================================
// spécifier des attributs OpenGL à la SDL
SDL_GL_SetAttribute(SDL_GLattr attr, int value);
//================================================
// spécifier à la SDL quelle version d'OpenGL on souhaite utiliser
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
//================================================
// activer le Double Buffuring avec OpenGL
SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
//================================================
// demande un pointeur SDL_Window pour y attacher le contexte OpenGL
SDL_GLContext SDL_GL_CreateContext(SDL_Window *window);
contexteOpenGL = SDL_GL_CreateContext(fenetre);
//================================================
// tester la valeur de la variable contexteOpenGL
// Création du contexte OpenGL
contexteOpenGL = SDL_GL_CreateContext(fenetre);
if(contexteOpenGL == 0)
{
	std::cout << SDL_GetError() << std::endl;
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return -1;
}
//================================================
// détruire le contexte lorsque nous n'en avons plus besoin
SDL_GL_DeleteContext(contexteOpenGL);
//================================================
