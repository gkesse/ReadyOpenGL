//===============================================
char checkShaderCompilation(GLuint shaderID) {
	GLint compilationStatus = 0;
	// Vérification de la compilation pour le vertex shader
	glGetShaderiv(vertexID, GL_COMPILE_STATUS, &compilationStatus);
	if ( compilationStatus != GL_TRUE ) {
		printf("Echec compilation\n");
		return 0;
	}
	return 1; // Pas d'erreur
}
//===============================================
