/*
main.c
GASTON Clément

Programme permettant de : - modifier l'allumage du coeurs en LEDS
                          - lire et traiter les données du fichier .csv sortant du module Cardio
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#define LARGEUR_CONSOLE 120
// Fonction permetant de centrer le texte sur la console
void printf_center(const char* str)
{
	unsigned int n;
	for (n = 0; n < (LARGEUR_CONSOLE - strlen(str)) / 2; n++)
	{
		putchar(' ');
	}
	printf("%s", str);
}
// Fonction principal du programme
int main ()
{
    int param = 0;
    int VPIN = 0;
    int SPIN = 0;
    int cardioParam = 0;
    int choixMenu;
    cardio *fichier = NULL;
    fichier = chargeFichier();

    do
    {
		printf_center("\n");
		Color(4, 0);
        printf_center("******** Hexart Care ********\n\n");
        printf_center("Que souhaitez-vous faire?\n\n");
        printf_center("(1) Modifier l'affichage des LEDS du coeur\n");
        printf_center("(2) Lire les donnees du module cardio\n");
        printf_center("(3)	Choisir le mode de lecture du module cardio\n");
        printf_center("(autre) Quitter? \n");
        printf_center("Choix : ");
		Color(15, 0);

        choixMenu = 0;
        scanf("%d",&choixMenu);

        switch(choixMenu)
		{
		    //Appel du menu gérant le mode d'affichage du coeur en LED
			case 1 :
            {
                system("cls");
                menuCoeur (choixMenu, &param, &VPIN, &SPIN);
                generationParamH (param, VPIN, SPIN, cardioParam);
                break;
            }

            //Appel du menu gérant la lecture des différentes données récoltés sur le module Cardio
            case 2 :
            {
                system("cls");
                if (fichier -> donneeSuivante == NULL)
                {
                    printf("Fichier vide. \n\n");
                    break ;
                }
                menuPoul(choixMenu, &param, &VPIN, &SPIN);
                break;
            }

            //Appel du menu gérant la lecture des différentes données récoltés sur le module Cardio
            case 3 :
            {
                system("cls");
                menuCardio(choixMenu, &cardioParam);
                generationParamH (param, VPIN, SPIN, cardioParam);
                break;
            }

            // Sortir du programme
            default :
            {
                return 0;
            }
        }
    }
    while ((choixMenu > 0) && (choixMenu < 4));
    return 0;
}
