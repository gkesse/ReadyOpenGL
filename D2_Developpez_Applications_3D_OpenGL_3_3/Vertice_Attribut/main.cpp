//================================================
void glVertexAttribPointer(GLuint index, GLuint size, GLenum type,
GLboolean normalized, GLsizei stride, const GLvoid *pointer);
//================================================
*index : c'est le numéro du tableau, son identifiant.
*size : c'est le nombre de coordonnées par vertex. En 2D ce sera 2 et en 3D ce sera 3.
*type : c'est le type de données (float, int, ...).
*normalized : booléen permettant à OpenGL de normaliser les données (comme les vecteurs).
*stride : paramètre spécial, on le mettra à zéro tout le temps, nous ne l'utiliserons pas.
*pointer : c'est le pointeur sur nos données, ici nos coordonnées.
//================================================
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
//================================================
