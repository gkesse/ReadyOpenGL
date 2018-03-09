//===============================================
#define NOM définition 
// définie une macro 'NOM' avec pour valeur 'définition' 
// pour le préprocesseur.
// Si 'NOM' est appelé dans le code, 
// 'définition' va être copié à la place de 'NOM' 
// lors de la lecture par le préprocesseur.
#undef NOM
// permet d'enlever la déclaration de 'NOM' effectué avec #define
#if Test
// test logique
#ifdef NOM 
// teste si 'NOM' est défini.
#ifndef NOM
// teste si 'NOM' n'est pas défini
#else
// sinon, pour le #if
#elif Test
// sinon si, suivi d'un test logique
#endif
// fin de test (pour fermer le bloc commencé par #if)
#error
// provoque une erreur lors de la compilation
#pragma
// actionne une commande qui dépend de l'implémentation.
#line
// modifie le compteur de ligne du compilateur
// (pour changer le numéro de ligne du rapport d'erreurs)
__LINE__
// macro qui sera remplacée par le numéro de ligne courante.
__FILE__ 
// macro indiquant le fichier courant.
__VERSION__ 
// macro indiquant la version actuelle du GLSL
#version 'numéro_de_version'
// indique au compilateur la version de GLSL 
// nécessaire (ou voulue) pour ce shader.
//===============================================
// Pour forcer le GLSL en version 1.50
#version 150
//===============================================
#extension {nom_de_l_extension | all} : {require | enable | warn |disable}
// permet de connaître si une extension est présente, 
// mais aussi de compiler que si celle ci est présente. 
// Par défaut, toutes les extensions sont désactivées 
// (#extension all : disable). 
//===============================================
#extension GL_EXT_gpu_shader4 : enable
//===============================================
