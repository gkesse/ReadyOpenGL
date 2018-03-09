//===============================================
// Variables de sorties (LECTURE et ECRITURE) :
vec4 gl_FragColor : // couleur du pixel.
vec4 gl_FragData[] : // donnée des buffers 
// (La taille du tableau maximum est : gl_MaxDrawBuffers.
float gl_FragDepth : // la profondeur du pixel 
// (par défaut : glFragCoord.z).
//===============================================
// Variables 'varying' (LECTURE UNIQUEMENT) :
varying vec4 gl_Color : // la couleur du pixel, 
// venant du vertex shader.
varying vec4 gl_SecondaryColor : // la couleur secondaire du pixel, 
// venant du vertex shader.
varying vec4 gl_TexCoord[] : // coordonnées des textures 
// (la taille maximale du tableau est gl_MaxTextureCoords).
varying float gl_FogFragCoord : // coordonnée du brouillard.
//===============================================
// Variables d'entrées (LECTURE UNIQUEMENT) :
vec4 gl_FragCoord : // coordonnées du pixel en coordonnées relatives à l'écran.
bool gl_FrontFacing : // true si nous voyons la face avant.
//===============================================
