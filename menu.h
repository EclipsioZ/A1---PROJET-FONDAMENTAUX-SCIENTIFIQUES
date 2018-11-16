/*
menu.h
GASTON Cl�ment

Ensemble des protytpes de fonction du menu.c
*/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "generationCode.h"
#include "donnees.h"

// Fonction permettant de colorer du texte
void Color(int couleurDuTexte, int couleurDeFond);

// Menu g�rant le mode d'affichage du coeur en LED
int menuCoeur(int choixMenu,int *param,int *VPIN,int *SPIN);

// Menu g�rant la lecture des diff�rentes donn�es r�colt�s sur le module Cardio
int menuPoul(int choixMenu,int *param,int *VPIN,int *SPIN);

// Menu g�rant la lecture des donn�es du module Cardio
int menuCardio(int choixMenu, int *cardioParam);

// Menu permettant de choisir le type de trier � r�aliser
int menuTrier (int *choix);

<<<<<<< HEAD
// Menu permettant d'enregistrer le tri effectue
void menuSauveFichier(int choixMenu, cardio *fichier);
=======
/*int param = 0;
int VPIN = 0;
int SPIN = 0;
int choixMenu = 1;*/
int menuCoeur(int choixMenu,int *param,int *VPIN,int *SPIN);
int menuPoul(int choixMenu,int *param,int *VPIN,int *SPIN);
void Color(int couleurDuTexte, int couleurDeFond);
>>>>>>> master

#endif // MENU_H_INCLUDED
