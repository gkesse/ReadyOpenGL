//===============================================
// Calcul du vecteur entre le vertex et la lumière
Vec3 rayon = lumiere.position - vertex;
//===============================================
 // Calcul de l'angle entre le rayon de la lumière 
 // et la normale de l'objet
float angleLumiere = dot(normal, rayon);
//===============================================
// Calcul de la lumière diffuse
Vec3 couleurDiffuse = lumiere.diffuse * angleLumiere;
//===============================================
