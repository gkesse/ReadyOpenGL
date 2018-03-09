//===============================================
// Chargement des shaders
...
// Récupération de programID
...
// Récupération de attributeId (couleur)
attributeId = glGetAttribLocation(programID, "couleur");
// Voilà, nous sommes prêt
// Utilisation de programID
glUseProgram(programID);
// Activation du vertex attributeId
glEnableVertexAttribArray(attributeId);
// Initialisation de cubeColours
...
// Envoi de cubeColours
glVertexAttribPointer(attributeId, 3, GL_FLOAT, GL_TRUE, 0, cubeColours);
// Désctivation du vertex attributeId
glDisableVertexAttribArray(attributeId);
//===============================================
// Vertex shader
attribute vec3 couleur = vec3(0.0f,1.0f,0.0f);
void main (void)
{
	gl_Position = ftransform();
	gl_FrontColor = vec4(couleur,1.0);
}
//===============================================
