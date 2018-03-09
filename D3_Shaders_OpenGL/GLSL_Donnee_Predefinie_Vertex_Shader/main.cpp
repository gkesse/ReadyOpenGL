//===============================================
// Variables de sorties (LECTURE et ECRITURE) :
vec4 gl_Position : 
// position du vertex dans l'espace écran. 
// Votre vertex shader est obligé d'écrire quelque
// chose dans cette variable.
float gl_PointSize : 
// détermine la taille des points à dessiner. 
// Le programme doit avoir GL_VERTEX_PROGRAM_POINT_SIZE d'activé.
vec4 gl_ClipVertex : 
// doit être rempli par la position du vertex, 
// afin d'effectuer les opérations de découpage (clipping). 
// Explication détaillée dans la section 4.A.4.
//===============================================
// Variables d'attributs (LECTURE UNIQUEMENT) :
attribute vec4 gl_Vertex : // position du vertex.
attribute vec4 gl_Normal : // normal du vertex.
attribute vec4 gl_Color : // couleur du vertex.
attribute vec4 gl_SecondaryColour : // couleur secondaire du vertex.
attribute vec4 gl_MultiTexCoord0 : // coordonnées de la texture 0 
// (le 0 peut être remplacé par un chiffre de 0 à 7 compris).
attribute float gl_FogCoord : // coordonnées du brouillard.
//===============================================
// Variables 'varying' (LECTURE et ECRITURE) :
varying vec4 gl_FrontColor : // couleur de la face avant.
varying vec4 gl_BackColor : // couleur de la face arrière 
// (GL_VERTEX_PROGRAM_TWO_SIDE doit être activé).
varying vec4 gl_FrontSecondaryColor : // couleur secondaire de la face avant.
varying vec4 gl_BackSecondaryColor : // couleur secondaire de la face arrière.
varying vec4 gl_TexCoord[] : // tableau des coordonnées de texture. 
// La taille du tableau maximum est : gl_MaxTextureCoords.
varying float gl_FogFragCoord : // coordonnée du brouillard.
//===============================================
