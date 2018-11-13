#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "menu.h"

void Color(int couleurDuTexte, int couleurDeFond) // fonction d'affichage de couleurs
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}
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
}
