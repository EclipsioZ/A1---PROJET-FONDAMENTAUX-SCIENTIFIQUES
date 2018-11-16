/*
actions.h
GASTON Clément

Ensemble des protytpes de fonction du actions.c
*/

#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

// Permet de trier le fichier dans l'odre qu'on veut
void trieFichier(cardio *listeDonnees, int choix);

// Permet de swap 2 lignes
void echange (cardio *encours , cardio *encoursGrand);

// Permet de calculer un poul moyen sur une plage de temps donnée
float moyennePoul (cardio *premiereLigne, int *tempsInitial, int *tempsFinal, float *poulTotal);

// Permet de calculer le nombre de ligne que possède le fichier .csv
int tailleFichier (cardio *premiereLigne, int *nombreLigne);

// Permet d'afficher le battement correspond aux temps depuis le lancement du programme
int battementTempsPrecis (cardio *premiereLigne, int *temps, int *battement);

// Permet l'affichage du poul minimum et maximum du fichier .csv
void poulMinMax(cardio *premiereLigne);

#endif // ACTIONS_H_INCLUDED
