//===============================================
vec4 convertirVecteur(vec2 vecteur);
// Surcharge
vec4 convertirVecteur(vec3 vecteur);
//===============================================
// Implémentation de la surcharge
vec4 convertirVecteur(vec3 vecteur)
{
	vec4 resultat = vec4(vecteur, 0.0);
	return resultat;
}
//===============================================
void main()
{
	// Vecteur
	vec3 monPetitVecteur = vec3(1.0, 2.0, 3.0);
	// Appel à la fonction de conversion
	vec4 monGrandVecteur = convertirVecteur(monPetitVecteur);
}
//===============================================
