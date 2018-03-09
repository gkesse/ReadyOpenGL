//===============================================
// Chargement des shaders
...
// Récupération de programID
...
// Récupération de uniformId (couleurBleu)
uniformId = glGetUniformLocation(programID, "couleurBleu");
// Voilà, nous sommes prêt
// Utilisation de programID
glUseProgram(programID);
// Initialisation de couleurBleu
...
// Envoi de couleurBleu
glUniform1f(uniformId,couleurBleu);
//===============================================
// Fragment shader associé
uniform float couleurBleu = 0.0;
void main(void)
{
	gl_FragColor = vec4(gl_Color.xy,couleurBleu,1.0);
}
//===============================================
