//===============================================
struct Lumiere
{
	vec3 position;
	vec4 couleurAmbiante;
	vec4 couleurDiffuse;
	vec4 couleurSpeculaire;
	float shininess ; // Seulement pour la lumière spéculaire
	// Spécifique aux spots et points
	float attenuationConstante ;
	float attenuationLineaire ;
	float attenuationQuadratique ;
	// Spécifique aux spots
	vec3 direction ;
	float angle ;
	float exposition;
	float limite;
}
//===============================================
