//================================================
glDrawArrays(GLenum mode, GLint first, GLsizei count);
//================================================
*mode : C'est la forme finale (nous verrons cela juste après).
*first : C'est l'indice de notre premier vertex à afficher(nous lui donnerons un int).
*count : C'est le nombre de vertices à afficher depuis first (nous lui donnerons également un int).
//================================================
Valeur 				| Définition
GL_TRIANGLES 		| Avec ce mode, chaque groupe de 3 vertices formera un triangle. C'est le mode le plus utilisé.
GL_POLYGON 			| Tous les vertices s'assemblent pour former un polygone de type convexe (Hexagone, Heptagone, ...).
GL_LINES 			| Chaque duo de vertices formera une ligne.
GL_TRIANGLE_STRIP 	| Ici les triangles s'assembleront. Les deux derniers vertices d'un triangle s'assembleront avec un 4ième
					| vertex pour former un nouveau triangle.
//================================================
glDrawArrays(GL_TRIANGLES, 0, 3);
//================================================
// Vertices et coordonnées
float vertices[] = {-0.5, -0.5, 0.0, 0.5, 0.5, -0.5};
// Boucle principale
while(!terminer)
{
// Gestion des évènements
....
// On remplie puis on active le tableau Vertex Attrib 0
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
glEnableVertexAttribArray(0);
// On affiche le triangle
glDrawArrays(GL_TRIANGLES, 0, 3);
// On désactive le tableau Vertex Attrib puisque l'on en a plus
besoin
glDisableVertexAttribArray(0);
// Actualisation de la fenêtre
....
}
//================================================
	