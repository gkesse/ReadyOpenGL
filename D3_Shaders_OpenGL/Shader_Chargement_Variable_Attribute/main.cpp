//===============================================
attribute vec3 nom;
// sont des variables que l'on passe avec chaque sommet
// nous pouvons avoir une valeur différente pour chaque vertex
// vous pouvez ajouter des informations à vos sommets en complément 
// de la position (qui est obligatoire)
// la couleur, les coordonnées de texture
//===============================================
// récupérer un identifiant sur la variable que nous voulons remplir
GLint glGetAttribLocation (GLuint program, const GLchar * name)
program : // contient l'identifiant du Program Shader.
name : // contient le nom de la variable du shader.
// Retourne un identifiant sur la variable contenu dans le shader.
//===============================================
// Une fois que nous avons l'identifiant de notre attribut, 
// nous pouvons le remplir
void glVertexAttrib*(GLuint index)
index : // l'identifiant de la variable à remplir.
//===============================================
