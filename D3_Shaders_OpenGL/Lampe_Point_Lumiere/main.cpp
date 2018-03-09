//===============================================
// Calcul de la distance des objets
Vec3 vLumObj = lumiere.position - vertex ;
float distance = length(vLumObj);
//===============================================
// Calcul de l'atténuation selon la distance
float attenuation = lumiere.attenuationConstante +
lumiere.attenuationLineaire * d +
lumiere.attenuationQuadratique * d * d;
//===============================================
// Calcul de la lumière selon l'atténuation du point de lumière
couleurAmbiante = couleurAmbiante * attenuation ;
couleurDiffuse = couleurDiffuse * attenuation ;
couleurSpeculaire = couleurSpeculaire * attenuation;
//===============================================
