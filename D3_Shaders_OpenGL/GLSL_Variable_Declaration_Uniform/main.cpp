//===============================================
uniform type nom;
// sont des variables qui sont constantes 
// pour toutes les instances du shader.
// ne doit pas être dans une fonction du shader
//===============================================
// envoyer à partir de notre programme OpenGL
GLint glGetUniformLocation (GLuint program, const GLchar * name)
program : // contient l'identifiant du Program Shader
name : // le nom de la variable dans le shader.
// retourne un identifiant pour la variable contenu dans le shader.
//===============================================
void glUniform* (GLint location, …)
location : // l'identifiant que l'on a obtenu avec glGetUniformLocation()
//===============================================
// La fonction 
glGetUniformLocation() 
// demande le programme shader sur lequel nous voulons envoyer 
// la variable ainsi que le nom de la variable. 
// Elle va nous retourner un ID sur cette variable que 
// nous pourrons utiliser dans une des fonctions 
glUniform(), 
// pour remplir la variable en question.
//===============================================
// vérifier s'il y a eu une erreur, à l'aide de 
glGetError()
//===============================================


