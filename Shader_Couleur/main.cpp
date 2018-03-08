//================================================
Shader shaderCouleur("Shaders/couleur2D.vert", "Shaders/couleur2D.frag");
shaderCouleur.charger();
//================================================
// Activation du shader
glUseProgram(shaderCouleur.getProgramID());
// Envoi des données et affichage
....
// Désactivation du shader
glUseProgram(0);
//================================================
// On définie les couleurs
float couleurs[] = {
	0.0, 204.0 / 255.0, 1.0, 
	0.0, 204.0 / 255.0,	1.0, 
	0.0, 204.0 / 255.0, 1.0
};
while(...)
{
	....
	// Activation du shader
	glUseProgram(shaderCouleur.getProgramID());
	// Envoi des vertices
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glEnableVertexAttribArray(0);
	// On rentre les couleurs dans le tableau Vertex Attrib 1
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, couleurs);
	glEnableVertexAttribArray(1);
	....
	// Désactivation du shader
	glUseProgram(0);
	....
}
//================================================
void SceneOpenGL::bouclePrincipale()
{
	// Variables
	bool terminer(false);
	float vertices[] = {-0.5, -0.5, 0.0, 0.5, 0.5, -0.5};
	float couleurs[] = {
		0.0, 204.0 / 255.0, 1.0, 
		0.0, 204.0 / 255.0, 1.0, 
		0.0, 204.0 / 255.0, 1.0
	};
	// Shader
	Shader shaderCouleur("Shaders/couleur2D.vert", "Shaders/couleur2D.frag");
	shaderCouleur.charger();
	// Boucle principale
	while(!terminer)
	{
		// Gestion des évènements
		SDL_WaitEvent(&m_evenements);
		if(m_evenements.window.event == SDL_WINDOWEVENT_CLOSE)
		terminer = true;
		// Nettoyage de l'écran
		glClear(GL_COLOR_BUFFER_BIT);
		// Activation du shader
		glUseProgram(shaderCouleur.getProgramID());
		// Envoi des vertices
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0,
		vertices);
		glEnableVertexAttribArray(0);
		// Envoi des couleurs
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,
		couleurs);
		glEnableVertexAttribArray(1);
		// Affichage du triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// Désactivation des tableaux Vertex Attrib
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(0);
		// Désactivation du shader
		glUseProgram(0);
		// Actualisation de la fenêtre
		SDL_GL_SwapWindow(m_fenetre);
	}
}
//================================================
