#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "generationCode.h"

/*int param = 0;
int VPIN = 0;
int SPIN = 0;
int choixMenu = 1;*/
int menuCoeur(int choixMenu,int *param,int *VPIN,int *SPIN);
int menuPoul(int choixMenu,int *param,int *VPIN,int *SPIN);
void Color(int couleurDuTexte, int couleurDeFond);

#endif // MENU_H_INCLUDED
