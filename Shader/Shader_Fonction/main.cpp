//===============================================
// Prototype
vec4 convertirVecteur(vec2 vecteur);
// Fonction main
void main()
{
}
//===============================================
// Implémentation de la fonction
vec4 convertirVecteur(vec2 vecteur)
{
	vec4 resultat = vec4(vecteur, 0.0, 0.0);
	return resultat;
}
//===============================================
// Prototype
vec4 convertirVecteur(vec2 vecteur);
// Fonction main
void main()
{
}
// Implémentation
vec4 convertirVecteur(vec2 vecteur)
{
	vec4 resultat = vec4(vecteur, 0.0, 0.0);
	return resultat;
}
//===============================================
void main()
{
	// Vecteur
	vec2 monPetitVecteur = vec2(1.0, 2.0);
	// Appel à la fonction de conversion
	vec4 monGrandVecteur = convertirVecteur(monPetitVecteur);
}
//===============================================
