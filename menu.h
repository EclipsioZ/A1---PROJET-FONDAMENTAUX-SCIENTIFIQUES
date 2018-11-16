/*
menu.h
GASTON Clément

Ensemble des protytpes de fonction du menu.c
*/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "generationCode.h"
#include "donnees.h"

// Fonction permettant de colorer du texte
void Color(int couleurDuTexte, int couleurDeFond);

// Menu gérant le mode d'affichage du coeur en LED
int menuCoeur(int choixMenu,int *param,int *VPIN,int *SPIN);

// Menu gérant la lecture des différentes données récoltés sur le module Cardio
int menuPoul(int choixMenu,int *param,int *VPIN,int *SPIN);

// Menu gérant la lecture des données du module Cardio
int menuCardio(int choixMenu, int *cardioParam);

// Menu permettant de choisir le type de trier à réaliser
int menuTrier (int *choix);

// Menu permettant d'enregistrer le tri effectue
void menuSauveFichier(int choixMenu, cardio *fichier);

#endif // MENU_H_INCLUDED
