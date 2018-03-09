//===============================================
// À la déclaration de la variable (en dehors des fonctions) :
uniform : 	indique que la variable est une donnée venant du programme OpenGL pour le vertex shader et/ou
			le fragment shader. (LECTURE UNIQUEMENT).
attribute : indique une variable par vertex, venant du programme OpenGL. Ne peut être placée que dans le
			vertex shader. (LECTURE UNIQUEMENT). 
			Obsolète à partir de la version 150 du GLSL, remplacé par 'in'.
varying : 	donnée en sortie du vertex shader (LECTURE et ECRITURE), envoyée au fragment shader après
			avoir été interpolé (LECTURE UNIQUEMENT). 
			Obsolète à partir de la version 150 du GLSL, remplacé par 'out'.
const : 	indique une variable qui est constante (LECTURE UNIQUEMENT).
//===============================================
// Dans la déclaration des fonctions :
in : 	la variable est initialisée en entrée, 
		mais n'est pas copié en retour (qualificatifs par défaut)
out : 	la variable est copiée en retour, 
		mais non initialisée en entrée.
inout : la variable est initialisée en entrée, 
		copiée en retour.
const : variable d'entrée constante.
//===============================================
