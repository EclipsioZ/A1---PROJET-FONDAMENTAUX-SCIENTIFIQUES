/*
actions.c
GASTON Clément

Ensemble des fonctions permettant de manipuler (trier et calculer) des données du fichier .csv
*/

#include <stdio.h>
#include "donnees.h"
#include "actions.h"

// Permet de calculer un poul moyen sur une plage de temps donnée
float moyennePoul (cardio *premiereLigne, int *tempsInitial, int *tempsFinal, float *poulTotal)
{
    float poulTotal2 = 0;
    cardio *ligneActuel = premiereLigne->donneeSuivante;

    while (ligneActuel != NULL)
    {
        if ((ligneActuel->temps >= *tempsInitial) && (ligneActuel->temps <= *tempsFinal))
        {
            poulTotal2 = poulTotal2 + ligneActuel->battement;
        }
        ligneActuel = ligneActuel->donneeSuivante;
    }
    poulTotal2 = poulTotal2 / (*tempsFinal+1000 - *tempsInitial);
    *poulTotal = poulTotal2*1000;
    return *poulTotal;
}



// Permet de trier le fichier dans l'odre qu'on veut
void trieFichier(cardio *listeDonnees, int choix)
{
    int permutation;
    cardio *encours;
    cardio *encoursGrand;
    encoursGrand = NULL;

    switch(choix)
    {
        case 1 :
        {
            do
            {
                permutation  = 0 ;
                encours = listeDonnees->donneeSuivante;

                while (encours->donneeSuivante != encoursGrand)
                {
                    if (encours->battement > encours->donneeSuivante->battement)
                    {
                        echange(encours,encours->donneeSuivante);
                        permutation = 1 ;
                    }
                    encours = encours->donneeSuivante;
                }
                encours = encoursGrand;
            }
            while (permutation);
            break;
        }
        case 2 :
        {
            do
            {
                permutation  = 0 ;
                encours = listeDonnees->donneeSuivante;

                while (encours->donneeSuivante != encoursGrand)
                {
                    if (encours->battement < encours->donneeSuivante->battement)
                    {
                        echange(encours,encours->donneeSuivante);
                        permutation = 1 ;
                    }
                    encours = encours->donneeSuivante;
                }
                encours = encoursGrand;
            }
            while (permutation);
            break;
        }

        case 3 :
        {
            do
            {
                permutation  = 0 ;
                encours = listeDonnees->donneeSuivante;

                while (encours->donneeSuivante != encoursGrand)
                {
                    if (encours->temps > encours->donneeSuivante->temps)
                    {
                        echange(encours,encours->donneeSuivante);
                        permutation = 1 ;
                    }
                    encours = encours->donneeSuivante;
                }
                encours = encoursGrand;
            }
            while (permutation);
            break;
        }

        case 4 :
        {
            do
            {
                permutation  = 0 ;
                encours = listeDonnees->donneeSuivante;

                while (encours->donneeSuivante != encoursGrand)
                {
                    if (encours->temps < encours->donneeSuivante->temps)
                    {
                        echange(encours,encours->donneeSuivante);
                        permutation = 1 ;
                    }
                    encours = encours->donneeSuivante;
                }
                encours = encoursGrand;
            }
            while (permutation);
            break;
        }
    }
}



// Permet de swap 2 lignes
void echange (cardio *encours , cardio *encoursGrand)
{
   int temps;
   int pouls;

    pouls = encoursGrand->battement;
    encoursGrand->battement = encours->battement;
    encours->battement = pouls;

    temps = encoursGrand->temps;
    encoursGrand->temps = encours->temps;
    encours->temps = temps;
}




// Permet de calculer le nombre de ligne que possède le fichier .csv
int tailleFichier (cardio *premiereLigne, int *nombreLigne)
{
    cardio *ligneActuel = premiereLigne->donneeSuivante;

    if (premiereLigne->donneeSuivante == NULL)
    {
        return 0;
    }
    while(ligneActuel != NULL)
    {
        ligneActuel = ligneActuel->donneeSuivante;
        *nombreLigne = *nombreLigne + 1;
    }
    return (int)nombreLigne;
}



// Permet d'afficher le battement correspond aux temps depuis le lancement du programme
int battementTempsPrecis (cardio *premiereLigne, int *temps, int *battement)
{
    cardio *ligneActuel = premiereLigne -> donneeSuivante;

    while(ligneActuel != NULL)
    {
        if (ligneActuel->temps == *temps)
        {
            *battement = ligneActuel->battement;
            return *temps;
        }
        ligneActuel = ligneActuel->donneeSuivante;
    }
    return 0;
}



// Permet l'affichage du poul minimum et maximum du fichier .csv
void poulMinMax (cardio *premiereLigne)
{
    cardio *poulMax = premiereLigne->donneeSuivante;
    cardio *poulMin = premiereLigne->donneeSuivante;
    cardio *ligneActuel = premiereLigne->donneeSuivante;
    while (ligneActuel != NULL)
    {
        if ((ligneActuel->battement) < (poulMin->battement))
        {
            poulMin = ligneActuel;
        }
        if ((ligneActuel->battement) > (poulMax->battement))
        {
            poulMax = ligneActuel;
        }
        ligneActuel = ligneActuel->donneeSuivante;
    }
    printf("Le poul maximum est : %d atteint apres %d secondes.\n", poulMax->battement, poulMax->temps);
    printf("Le poul minimum est : %d atteint apres %d secondes.\n\n", poulMin->battement, poulMin->temps);
    return ;
}
