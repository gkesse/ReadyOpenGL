//===============================================
// la matrice de la texture : 
gl_TextureMatrix ;
// les coordonnées de la texture : 
gl_MultiTexCoord0 ;
// les coordonnées de la texture (interpolés) : 
gl_TexCoord[ gl_MaxTextureCoords ] ;
// l'échantillon de la texture (les couleurs), 
qui est une variable uniforme.
//===============================================
// La matrice de texture est un tableau, 
// ayant au maximum 
gl_MaxTextureCoords. 
//===============================================
gl_MultiTexCoord0 
// représente les coordonnées de la première texture, 
// pour le vertex actuel. 
// Le '0' peut être remplacé par un chiffre de 0 à 7.
//===============================================
// L'échantillon 'sampler' est un type qui représente 
// la texture dans le fragment shader.
//===============================================
Vertex shader : 
// transforme nos coordonnées de texture et 
// passe le résultat au fragment shader.
//===============================================
// Vertex shader d'application d'une texture
void main (void)
{
	gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
	gl_Position = ftransform();
	//gl_FrontColor = vec4(couleur,1.0);
}
//===============================================
// Fragment shader d'application d'une texture
uniform sampler2D tex;
void main(void)
{
	gl_FragColor = texture2D(tex,gl_TexCoord[0].st);
}
//===============================================
