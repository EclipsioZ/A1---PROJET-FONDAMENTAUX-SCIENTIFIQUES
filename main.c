Skip to content
 
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 @clementgaston31 Sign out
0
0 0 EclipsioZ/A1---PROJET-FONDAMENTAUX-SCIENTIFIQUES
 Code  Issues 0  Pull requests 0  Projects 0  Wiki  Insights
A1---PROJET-FONDAMENTAUX-SCIENTIFIQUES/main.c
67b0e8f  42 minutes ago
@EclipsioZ EclipsioZ Update main.c
@EclipsioZ @clementgaston31
     
47 lines (41 sloc)  1.09 KB
/* Cartouche
*/
#include <stdio.h>
#include "menu.h"
int main ()
{
    do
    {
        printf("**** Module Cardio ****\n\n");
        printf("Que souhaitez-vous faire?\n\n");
        printf("(1)     Modifier l'affichage des LEDS du coeur\n");
        printf("(2)     Lire les donnees du module cardio\n");
        printf("(autre) Quitter?\n");

        choixMenu = 0;
        scanf("%d",&choixMenu);

        switch(choixMenu)
		{
		    //Appel du menu gérant le mode d'affichage du coeur en LED
			case 1 :
            {
                //menuCoeur ();
                generationCode (param, VPIN, SPIN);
                system ("cls");
                break;
            }

            //Appel du menu gérant la lecture des différentes données récoltés sur le module Cardio
            case 2 :
            {
                //menuPoul();
                //actions ?
                break;
            }
            default :
            {
                return 0;
            }
        }
    }
    while ((choixMenu > 0) && (choixMenu < 3));
    return 0;
}
© 2018 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
Press h to open a hovercard with more details.
