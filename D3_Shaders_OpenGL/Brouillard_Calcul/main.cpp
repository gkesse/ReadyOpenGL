//===============================================
// Calcul d'un brouillard linéaire
Fog = (gl_Fod.end - gl_FogFragCoord) * gl_Fog.scale ;
//===============================================
// Calcul du brouillard exponentiel (première méthode)
Fog = exp(-gl_Fog.density * gl_FogFragCoord) ;
//===============================================
// Calcul du brouillard exponentiel (seconde méthode)
Fog = exp(-gl_Fog.density * gl_FogFragCoord * gl_Fog.density * gl_FogFragCoord
//===============================================
// Limitation du brouillard
fog = clamp(fog, 0.0,1.0);
//===============================================
// Application du brouillard
couleur = mix(vec3(gl_Fog.color), couleur, fog);
//===============================================
