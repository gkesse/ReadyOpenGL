//===============================================
// Calcul de la distance entre la lumière et l'objet
Vec3 vLumObj = lumiere.position - vertex ;
float distance = length(vLumObj);
//===============================================
// Calcul de l'atténuation selon la distance
float attenuation = lumiere.attenuationConstante +
lumiere.attenuationLineaire * d +
lumiere.attenuationQuadratique * d * d;
//===============================================
// Calcul de l'angle entre le l'objet et la lampe 
// et l'objet de la direction de la lampe
float angle = dot(-vLumObj, normalize(lumiere.direction));
//===============================================
// Atténuation selon l'angle
float spotAttenuation = 0.0f
if ( angle >= lumiere.limite )
{
	spotAttenuation = pow(angle,lumiere.exposition);
}
//===============================================
// Application de l'atténuation
attenuation *= spotAttenuation;
//===============================================
// Calcul de la lumière selon l'atténuation du spot
couleurAmbiante = couleurAmbiante * attenuation ;
couleurDiffuse = couleurDiffuse * attenuation ;
couleurSpeculaire = couleurSpeculaire * attenuation;
//===============================================

//===============================================

//===============================================

//===============================================
