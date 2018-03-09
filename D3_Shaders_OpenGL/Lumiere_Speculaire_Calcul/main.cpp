//===============================================
// Calcul de la position de la camera
Vec3 oeil = matrice_inverser_vue * vertex;
//===============================================
// Calcul du vecteur de lumière
Vec3 ray = lumiere.position - vertex;
//===============================================
// Calcul de la lumière spéculaire
vec3 couleurSpeculaire = 
pow(dot(normale,(oeil-ray)),lumiere.shininess) *
lumiere.couleurSpeculaire;
//===============================================
