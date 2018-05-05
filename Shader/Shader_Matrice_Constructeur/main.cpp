//===============================================
void main()
{
	// Initialisation d'un vecteur à 3 coordonnées
	vec3 vecteur = vec3(1.0, 2.0, 3.0);
}
//===============================================
void main()
{
	// Initialisation d'un vecteur à 3 coordonnées
	vec3 vecteur;
	vecteur.x = 1.0;
	vecteur.y = 2.0;
	vecteur.z = 3.0;
}
//===============================================
void main()
{
	// Initialisation d'un vecteur nul
	vec4 vecteur = vec4(0.0);
}
//===============================================
void main()
{
	// Initialisation d'une matrice
	mat3 matrice = mat3(
	0.0, 3.0, 6.0,
	1.0, 4.0, 7.0,
	2.0, 5.0, 8.0);
}
//===============================================
void main()
{
	// Matrice nulle
	mat4 matrice = mat4(0.0);
}
//===============================================
void main()
{
	// Matrice d'identité
	mat4 matrice = mat4(1.0);
}
//===============================================
void main()
{
	// Vecteur
	vec2 petitVecteur = vec2(1.0, 2.0);
	// Initialisation à partir d'un autre vecteur
	vec4 grandVecteur = vec4(petitVecteur);
}
//===============================================
void main()
{
	// Vecteur
	vec2 petitVecteur = vec2(1.0, 2.0);
	// Initialisation à partir d'un autre vecteur
	vec4 grandVecteur;
	grandVecteur.x = petitVecteur.x;
	grandVecteur.y = petitVecteur.y;
}
//===============================================
void main()
{
	// Vecteur
	vec2 petitVecteur = vec2(1.0, 2.0);
	// Initialisation à partir de la variable
	vec4 grandVecteur = vec4(petitVecteur, 3.0, 4.0);
}
//===============================================
void main()
{
	// Vecteur position
	vec2 vecteur = vec2(1.0, 2.0);
	// Vecteur
	vec4 vecteur2 = vec4(3.0, 4.0, vecteur);
}
//===============================================
void main()
{
	// Vecteur
	vec2 petitVecteur = vec2(1.0, 2.0);
	// Autre vecteur
	vec4 grandVecteur;
	grandVecteur.x = 3.0;
	grandVecteur.y = 4.0;
	grandVecteur.z = petitVecteur.x;
	grandVecteur.w = petitVecteur.y;
}
//===============================================
void main()
{
	// Vecteur
	vec2 petitVecteur = vec2(5.0, 8.0);
	// Autre vecteur
	vec4 grandVecteur;
	grandVecteur.x = 7.0;
	grandVecteur.y = petitVecteur.x;
	grandVecteur.z = petitVecteur.y;
	grandVecteur.w = 2.0;
}
//===============================================
void main()
{
	// Vecteur
	vec2 petitVecteur = vec2(5.0, 8.0);
	// Autre vecteur
	vec4 grandVecteur = vec4(7.0, petitVecteur, 2.0);
}
//===============================================
