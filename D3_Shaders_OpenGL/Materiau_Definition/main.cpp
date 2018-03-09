//===============================================
la couleur;
la couleur diffuse 
// (celle qui est renvoyé à l'oeil) ;
la couleur spéculaire 
// (une altération du reflet de la lumière, par le matériau).
//===============================================
// Structure des informations pour les matériaux
struct Materiaux
{
	vec4 ambiante;
	vec4 diffuse;
	vec4 speculaire;
}
//===============================================
// Calcul de la lumière en prenant en compte le matériau
couleurAmbiante = couleurAmbiante * mat.ambiante;
couleurDiffuse = couleurDiffuse * mat.diffuse;
couleurSpeculaire = couleurSpeculaire * mat.speculaire;
//===============================================
