<<<<<<< HEAD
/*
donnees.c
GASTON Clément

Ensemble des fonctions permettant d'afficher ou de rechercher des données dans le fichier .csv
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "generationCode.h"

// Charge le fichier .csv ligne par ligne
cardio* chargeFichier()
{
    FILE *f;
    cardio *premiereDonnee = NULL;
    cardio *derniereDonnee = NULL;
    cardio *donneeActuel = NULL;

    int temps;
    int battement;
    int verificationFermeture = 1;
    char line[255];

    premiereDonnee = malloc(sizeof(cardio));
    donneeActuel = premiereDonnee;
    premiereDonnee->donneeSuivante = NULL;

    f = fopen(NOM_FICHIER_LECTURE, "r");
=======
#include "donnees.h"
#include "generationCode.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

cardio* creerLigne(int temps, int battement)
{
    cardio *creerLigne ;

    creerLigne = malloc(sizeof(cardio));
    creerLigne->temps = temps;
    creerLigne->battement = battement;
    creerLigne->nextEtape = NULL;
    return creerLigne;
}

void ajouterLigneListe(cardio *etapeAAjouter, cardio *derniereEtapeDeLaListe)
{
    derniereEtapeDeLaListe->nextEtape = etapeAAjouter;
}

cardio* chargeFichier(int *tailleFichier)
{
    FILE *f;
    cardio *listeEtape = NULL;
    cardio *lastEtape = NULL;
    cardio *currEtape = NULL;

    int temps;
    int battement;
    int checkCloture = 1;
    char line[255];

    listeEtape = malloc(sizeof(cardio));
    currEtape = listeEtape;
    listeEtape->nextEtape = NULL;

    f = fopen("batt.txt", "r");
>>>>>>> master
    if( f == NULL)
    {
        printf("Echec d'ouverture du fichier\n");
    }
    else
        {
        //printf("Succes ouverture du fichier\n");
        memset(line, '\0', 255);
        while(fgets(line, 255, f))
        {
            sscanf(line,"%d;%d\n", &temps, &battement);
<<<<<<< HEAD
            derniereDonnee = creerLigne(temps, battement);
            ajouterLigneListe(derniereDonnee, donneeActuel);
            donneeActuel = derniereDonnee;
        }
    }
    verificationFermeture = fclose(f);
    if( verificationFermeture == 0)
=======
            lastEtape = creerLigne(temps, battement);
            ajouterLigneListe(lastEtape, currEtape);
            currEtape = lastEtape;
            tailleFichier++;
            printf ("%d \n", tailleFichier);
        }
    }
    checkCloture = fclose(f);
    if( checkCloture == 0)
>>>>>>> master
    {
        //printf("Succes fermeture du fichier\n");
    }
    else
    {
        printf("Echec fermeture du fichier\n");
    }
<<<<<<< HEAD
    return premiereDonnee;
}



// Permert de créer chaque élément de la liste chaînée
cardio* creerLigne(int temps, int battement)
{
    cardio *creerLigne ;

    creerLigne = malloc(sizeof(cardio));
    creerLigne->temps = temps;
    creerLigne->battement = battement;
    creerLigne->donneeSuivante = NULL;
    return creerLigne;
}



// Permet de rajouter un nouvel élément à la fin de la liste
void ajouterLigneListe(cardio *nouvelleLigne, cardio *derniereLigne)
{
    derniereLigne->donneeSuivante = nouvelleLigne;
}



// Parcout la liste chaînée pour l'afficher
void afficherFichier(cardio *premiereLigne)
{
    cardio *ligneActuel = premiereLigne->donneeSuivante;

    if (premiereLigne->donneeSuivante == NULL)
=======
    return listeEtape, *tailleFichier;
}

//Affiche ligne par ligne
void afficherLigne(cardio *ligneActuel)
{

    printf("Temps : %d Battement : %d\n",
            ligneActuel->temps,
            ligneActuel->battement);
}

//Affiche la liste des étapes
void afficherFichier(cardio *premiereLigne)
{
    cardio *ligneActuel = premiereLigne->nextEtape;

    if (premiereLigne->nextEtape == NULL)
>>>>>>> master
    {
        printf("Fichier vide. \n\n");
        return;
    }
    while(ligneActuel != NULL)
    {
        afficherLigne(ligneActuel);
<<<<<<< HEAD
        ligneActuel = ligneActuel->donneeSuivante;
    }
}



// Permet l'affichage d'une ligne précise
void afficherLigne (cardio *ligneActuel)
{
    printf("Temps : %d Battement : %d\n", ligneActuel->temps, ligneActuel->battement);
}



// Permet de sauvegarder le dernier tri réalisé dans un nouveau fichier .txt
int sauvegardeFichier(cardio *premiereLigne)
{
    FILE *f;
    int verificationFermeture = 1;

    f = fopen(NOM_FICHIER_LECTURE, "w");
    if(f == NULL)
    {
        printf("Echec d'ouverture du fichier\n");
    }
    else
        {
        //printf("Succes ouverture du fichier\n");
        if (premiereLigne->donneeSuivante != NULL)
        {
            premiereLigne = premiereLigne->donneeSuivante;
            do
            {
                fprintf(f, "%d;%d\n", premiereLigne->temps, premiereLigne->battement);
                premiereLigne = premiereLigne->donneeSuivante;
            }
            while(premiereLigne != NULL);
        }
    }

    verificationFermeture = fclose(f);
    if( verificationFermeture == 0)
    {
        //printf("Succes fermeture du fichier\n");
    }
    else
    {
        printf("Echec fermeture du fichier\n");
    }
    return 1;
=======
        ligneActuel = ligneActuel->nextEtape;
    }
>>>>>>> master
}
