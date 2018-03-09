//===============================================
void loadShader()
{
	// Lecture des fichiers
	// Certaines personnes aiment avoir le fichier du vertex shader avec l'extension .vert
	// et le fichier du fragment shader avec l'extension .frag
	GLchar* vertexSource = (GLchar*)readFile("data/simple.vert");
	GLchar* fragmentSource = (GLchar*)readFile("data/simple.frag");
	GLint programState = 0;
	GLint vertexSize = 0;
	GLint fragmentSize = 0;
	
	// Création des IDs
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	
	// Chargement des sources dans OpenGL
	vertexSize = strlen(vertexSource);
	fragmentSize = strlen(fragmentSource);
	
	glShaderSource(vertexID, 1, (const GLchar**)(&vertexSource), &vertexSize);
	glShaderSource(fragmentID, 1, (const GLchar**)(&fragmentSource), &fragmentSize);
	
	// Compilation du vertex shader
	glCompileShader(vertexID);
	glCompileShader(fragmentID);

	// Creation de l'ID pour le programme
	programID = glCreateProgram();
	
	// On attache les shaders ensemble
	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);
	
	// On peut enfin passer aux liage.
	glLinkProgram(programID);
	
	// Et encore une fois on vérifie si tout se passe bien
	glGetProgramiv(programID , GL_LINK_STATUS , &programState);

	// Voilà, nous sommes prêt
	glUseProgram(programID);
}
//===============================================
