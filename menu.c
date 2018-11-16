<<<<<<< HEAD
/*
menu.c
ROSSI Florian

Menu permettant d'accèder aux multiples possibilités du programme
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

// Fonction permettant de colorer du texte
=======
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "menu.h"

>>>>>>> master
void Color(int couleurDuTexte, int couleurDeFond) // fonction d'affichage de couleurs
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}
<<<<<<< HEAD



// Menu gérant le mode d'affichage du coeur en LED
int menuCoeur(int choixMenu,int *param,int *VPIN,int *SPIN)
{
    Color(6, 0);
    printf("Quelles sont les parametres que vous voulez definir pour l'affichage du coeur ?\n\n");
    Color(12, 0);
    printf("(1) Allumer toutes les leds suivant les battements du coeur\n");
    printf("(2) Allumer une LED sur deux suivant les battements du coeur\n");
    printf("(3) Allumer une LED sur X suivant les battements du coeur\n");
    printf("(4) Allumer une seule LED suivant les battements de coeur\n");
    printf("(5) Allumer une seule LED en chenille suivant les battements de coeur\n");
    printf("(6) Allumer toutes les LEDS a la chaine puis s'eteignent a la chaines\n");
    printf("(7) Allumer toutes les LEDS a la chaine par 5 puis s'eteignent a la chaines\n");;
    printf("(Autres) Revenir au menu principal\n");
    printf("Choix : ");
    Color(15, 0);

    scanf("%d", &choixMenu);

    switch (choixMenu)
    {
        // Allumer toutes les leds suivant les battements du coeur
        case 1:
        {
            *param = 0;
            system("cls");
            break;
        }

        // Allumer une LED sur deux suivant les battements du coeur
        case 2:
        {
            *param = 1;
            system("cls");
            break;
        }

        // Allumer une LED sur X suivant les battements du coeur
        case 3:
        {
            *param = 2;
            system("cls");
            int X = 0;
            do
            {
                Color(3, 0);
                printf("Donner la valeur du nombre X comprise entre 3 et 10 pour le nombre de LED allume : ");
                scanf("%d", &X);
                if ((X < 3) || (X > 10))
                {
                    system("cls");
                    Color(4, 0);
                    printf("Erreur : Vous n'avez pas rentre une valeur comprise entre 3 et 10 !\n");
                }
            } while ((X < 3) || (X > 10));
            *VPIN = X;
            system("cls");
            break;
        }

        // Allumer une seule LED suivant les battements de coeur
        case 4:
        {
            *param = 3;
            system("cls");
            int placeLED = 1;
            do
            {
                Color(3, 0);
                printf("Donner une valeur comprise entre 1 et 10 pour la LED : ");
                Color(9, 0);
                scanf("%d", &placeLED);
                if (placeLED >= 1 && placeLED <= 10)
                {
                    *SPIN = placeLED + 2;
                    break;
                }
                else
                {
                    system("cls");
                    Color(4, 0);
                    printf("Erreur : Vous n'avez pas rentre une valeur comprise entre 1 et 10 !\n");
                }
            } while ((placeLED < 1) || (placeLED > 10));
            system("cls");
            break;
        }

        // Allumer une seule LED en chenille suivant les battements de coeur
        case 5:
        {
            *param = 4;
            system("cls");
            break;
        }

        // Allumer toutes les LEDS a la chaine puis s'eteignent a la chaines
        case 6:
        {
            *param = 5;
            system("cls");
            break;
        }

        // Allumer toutes les LEDS a la chaine par 5 puis s'eteignent a la chaines
        case 7:
        {
            *param = 6;
            system("cls");
            break;
        }

        // Revenir au menu principal
        default:
        {
            system("cls");
        }
    }
	return 0;
}



// Menu gérant la lecture des différentes données récoltés sur le module Cardio
int menuPoul(int choixMenu,int *param,int *VPIN,int *SPIN)
{
    cardio *fichier = NULL;
    fichier = chargeFichier();

    Color(1, 0);
    printf("Que souhaitez-vous faire?\n\n");
    Color(9, 0);
    printf("(1)  Afficher les donnees dans l'ordre du fichier .CSV\n");
    Color(3, 0);
    printf("(2)  Afficher les donnees en ordre croissant/decroissant\n");
    Color(2, 0);
    printf("(3)  Rechercher et afficher les donnees pour un temps particulier\n");
    Color(10, 0);
    printf("(4)  Afficher la moyenne de pouls dans une plage de temps donnee\n");
    Color(6, 0);
    printf("(5)  Afficher le nombre de lignes de donnees actuellement en memoire\n");
    Color(12, 0);
    printf("(6)  Rechercher et afficher les max/min de pouls\n");
    Color(4, 0);
    printf("(Autres) Revenir au menu principal\n");
    Color(15, 0);
    printf("Choix : ");

    scanf("%d", &choixMenu);

    switch (choixMenu)
    {
        // Afficher les donnees dans l'ordre du fichier .CSV
        case 1:
        {
            system("cls");
            afficherFichier(fichier);
            printf("\n");
            break;
        }

        // Afficher les donnees en ordre croissant/decroissan
        case 2:
        {
            system("cls");
            int choix = 0;
            menuTrier (&choix);
            trieFichier(fichier, choix);
            if (choix <= 0 || choix >= 5)
            {
                return 0;
            }
            afficherFichier(fichier);
            menuSauveFichier(choixMenu, fichier);
            break;
        }

        // Rechercher et afficher les donnees pour un temps particulier
        case 3:
        {
            system("cls");
            int temps = 0;
            int battement = 0;
            printf("Temps du battement ? : ");
            scanf("%d", &temps);
            battementTempsPrecis(fichier, &temps, &battement);
            printf("Le battement de %d millisecondes est : %d \n\n", temps, battement);
            break;
        }

        // Afficher la moyenne de pouls dans une plage de temps donnee
        case 4:
        {
            system("cls");
            int tempsInitial = 0;
            int tempsFinal = 0;
            float poulTotal = 0;
            printf("\nTemps initial : ");
            scanf("%d", &tempsInitial);
            printf("Temps final : ");
            scanf("%d", &tempsFinal);
            moyennePoul (fichier, &tempsInitial, &tempsFinal, &poulTotal);
            printf("Battements moyen entre %d et %d millisecondes(compris) et de : %f \n\n", tempsInitial, tempsFinal, poulTotal);
            break;
        }

        // Afficher le nombre de lignes de donnees actuellement en memoire
        case 5:
        {
            system("cls");
            int nombreLigne = 0;
            tailleFichier(fichier, &nombreLigne);
            printf("Le fichier possede : %d lignes\n\n", nombreLigne);
            break;
        }

        // Rechercher et afficher les max/min de pouls
        case 6:
        {
            system("cls");
            poulMinMax(fichier);
            break;
        }

        // Revenir au menu principa
        default:
        {
            system("cls");
        }
    }
	return 0;
}



// Menu gérant la lecture des données du module Cardio
int menuCardio(int choixMenu, int *cardioParam)
{
    Color(1, 0);
    printf("Que souhaitez-vous faire?\n\n");
    Color(9, 0);
    printf("(1)  Simulation du coeur d'un nouveau ne\n");
    Color(3, 0);
    printf("(2)  Simulation du coeur d'un bebe de 1 a 2ans\n");
    Color(2, 0);
    printf("(3)  Simulation du coeur d'un bebe de 3 a 5ans\n");
    Color(10, 0);
    printf("(4)  Simulation du coeur d'un enfant de 6 a 12ans\n");
    Color(6, 0);
    printf("(5)  Simulation du coeur d'un adulte\n");
    Color(12, 0);
    printf("(6)  Simulation du coeur d'une personne agees\n");
    Color(4, 0);
    printf("(7)  Battement depuis le module cardio\n");
    Color(3, 0);
    printf("(Autres) Revenir au menu principal\n");
    Color(15, 0);
    printf("Choix : ");

    scanf("%d", &choixMenu);

    system("cls");
    if (choixMenu <= 0 || choixMenu >= 8)
    {
        return 0;
    }
    else
    {
        *cardioParam = choixMenu - 1;
    }
	return 0;
}



// Menu permettant de choisir le type de trier à réaliser
int menuTrier (int *choix)
{
    int choixMenu =0;
    printf("Que souhaitez-vous faire?\n\n");
    printf("(1)     Trier dans l'ordre croissant des battements\n");
    printf("(2)     Trier dans l'ordre decroissant des battements\n");
    printf("(3)     Trier dans l'odre croissant du temps\n");
    printf("(4)     Trier dans l'odre decroissant du temps\n");
    printf("(autre) Quitter? \n");
    printf("Choix : ");

    scanf("%d",&choixMenu);
    *choix = choixMenu;

    system("cls");
    return (int)choix;
}



// Menu permettant d'enregistrer le tri effectue
void menuSauveFichier(int choixMenu, cardio *fichier)
{
printf("\n Que souhaitez-vous faire?\n\n");
    printf("(1)     Sauvegarder le dernier tri effectue dans le fichier ?\n");
    printf("(autre) Non \n");
    printf("Choix : ");

    scanf("%d",&choixMenu);
    system("cls");
    if (choixMenu == 1)
    {
        sauvegardeFichier(fichier);
    }
    else
    {
        return;
    }
=======
int menuPoul(int choixMenu,int *param,int *VPIN,int *SPIN)
{
	while ((choixMenu > 0) && (choixMenu < 8))
	{
		Color(1, 0);
		printf("Que souhaitez-vous faire?\n\n");
		Color(9, 0);
		printf("(1)  Afficher les donnees dans l'ordre du fichier .CSV\n");
		Color(3, 0);
		printf("(2)  Afficher les donnees en ordre croissant/decroissant\n");
		Color(2, 0);
		printf("(3)  Rechercher et afficher les donnees pour un temps particulier\n");
		Color(10, 0);
		printf("(4)  Afficher la moyenne de pouls dans une plage de temps donnee\n");
		Color(6, 0);
		printf("(5)  Afficher le nombre de lignes de donnees actuellement en memoire\n");
		Color(12, 0);
		printf("(6)  Rechercher et afficher les max/min de pouls\n");
		Color(4, 0);
		printf("(7)  Modifier les parametres des LEDS du coeur\n");
		Color(5, 0);
		printf("(Autres) Quitter l'application\n");
		Color(15, 0);

		scanf("%d", &choixMenu);

		switch (choixMenu)
		{
		case 1:
		{

			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{
			system("cls");
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			system("cls");
			menuCoeur(choixMenu, &param, &VPIN, &SPIN);
			choixMenu = 1;
			break;
		}
		default:
		{
			printf("CIAO !");
		}
		}
	}
	printf("CIAO !");
	return 0;
}
int menuCoeur(int choixMenu,int *param,int *VPIN,int *SPIN) {
	while ((choixMenu > 0) && (choixMenu < 8))
	{
		Color(6, 0);
		printf("Quelles sont les parametres que vous voulez definir pour l'affichage du coeur ?\n\n");
		Color(12, 0);
		printf("(1)  Allumer toutes les leds suivant les battements du coeur\n");
		printf("(2)  Allumer une LED sur deux suivant les battements du coeur\n");
		printf("(3)  Allumer une LED sur X suivant les battements du coeur\n");
		printf("(4)  Allumer une seule LED suivant les battements de coeur\n");
		printf("(5)  Allumer une seule LED en chenille suivant les battements de coeur\n");
		printf("(6)  Allumer toutes les LEDS a la chaine puis s'eteignent a la chaines\n");
		printf("(7)  Allumer toutes les LEDS a la chaine par 5 puis s'eteignent a la chaines\n");;
		printf("(Autres) Quitter l'application\n");
		Color(15, 0);

		scanf("%d", &choixMenu);

		switch (choixMenu)
		{
		case 1:
		{
			*param = 0;
			choixMenu = 0;
			system("cls");
			break;
		}
		case 2:
		{
			*param = 1;
			choixMenu = 0;
			system("cls");
			break;
		}
		case 3:
		{
			*param = 2;
			system("cls");
			Color(3, 0);
			int z = 1;
			int y = 0;
			while (z = 1)
			{
				Color(3, 0);
				printf("Donner la valeur du nombre X comprise entre 3 et 10 pour le nombre de LED allume : ");
				Color(9, 0);
				scanf("%d", &y);
				*VPIN = y;
				if (y >= 3 && y <= 10)
				{
					break;
				}
				else
				{
					Color(4, 0);
					printf("Erreur : Vous n'avez pas rentre une valeur comprise entre 3 et 10 !\n");
					Color(15, 0);
					system("pause");
					system("cls");
				}
			}
			Color(15, 0);
			choixMenu = 0;
			system("cls");
			break;
		}
		case 4:
		{
			*param = 3;
			system("cls");
			Color(3, 0);
			int z = 1;
			int y = 1;
			while (z = 1)
			{
				Color(3, 0);
				printf("Donner une valeur comprise entre 1 et 10 pour la LED : ");
				Color(9, 0);
				scanf("%d", &y);
				if (y >= 1 && y <= 10)
				{
					*SPIN = y + 2;
					break;
				}
				else
				{
					Color(4, 0);
					printf("Erreur : Vous n'avez pas rentre une valeur comprise entre 1 et 10 !\n");
					Color(15, 0);
					system("pause");
					system("cls");
				}
			}
			Color(15, 0);
			choixMenu = 0;
			system("cls");
			break;
		}
		case 5:
		{
			*param = 4;
			choixMenu = 0;
			printf ("%d\n", &param);
			system("pause");
			break;
		}
		case 6:
		{
			*param = 5;
			choixMenu = 0;
			system("cls");
			break;
		}
		case 7:
		{
			*param = 6;
			choixMenu = 0;
			system("cls");
			break;
		}
		default:
		{
			system("cls");
		}
		}
	}
	return param;
>>>>>>> master
}
