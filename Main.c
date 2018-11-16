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
        printf("**** Module Cardio ****\n\n");
        printf("Que souhaitez-vous faire?\n\n");
        printf("(1)     Modifier l'affichage des LEDS du coeur\n");
        printf("(2)     Lire les donnees du module cardio\n");
        printf("(3)     Choisir le mode de lecture du module cardio\n");
        printf("(autre) Quitter? \n");
        printf("Choix : ");

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
