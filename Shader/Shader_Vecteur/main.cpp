//===============================================
vec2 : vecteur à 2 coordonnées
vec3 : vecteur à 3 coordonnées
vec4 : vecteur à 4 coordonnées
//===============================================
void main()
{
	// Vecteur à 2 coordonnées
	vec2 monVecteur;
	// Accès aux coordonnées
	monVecteur.x = 1.0;
	monVecteur.y = 2.0;
}
//===============================================
void main()
{
	// Vecteurs à 3 et 4 coordonnées
	vec3 monVecteur;
	vec4 monGrandVecteur;
	// Accès aux coordonnées du premier vecteur
	monVecteur.x = 1.0;
	monVecteur.y = 2.0;
	monVecteur.z = 3.0;
	// Accès aux coordonnées du second vecteur
	monGrandVecteur.x = 1.0;
	monGrandVecteur.y = 2.0;
	monGrandVecteur.z = 3.0;
	monGrandVecteur.w = 4.0;
}
//===============================================
void main()
{
	// Vecteurs
	vec3 position, orientation;
	// Affectation de valeur
	position.x = 10.0;
	orientation.x = 5.0;
	....
	// Opérations
	vec3 resultat = position + orientation;
	resultat *= 0.5;
}
//===============================================
void main()
{
	// Vecteurs
	vec4 vecteur1, vecteur2;
	// Tableau
	vec4 montableau[2] = {vecteur1, vecteur2};
}
//===============================================
