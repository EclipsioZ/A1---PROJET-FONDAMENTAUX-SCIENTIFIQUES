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
            lastEtape = creerLigne(temps, battement);
            ajouterLigneListe(lastEtape, currEtape);
            currEtape = lastEtape;
            tailleFichier++;
            printf ("%d \n", tailleFichier);
        }
    }
    checkCloture = fclose(f);
    if( checkCloture == 0)
    {
        //printf("Succes fermeture du fichier\n");
    }
    else
    {
        printf("Echec fermeture du fichier\n");
    }
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
    {
        printf("Fichier vide. \n\n");
        return;
    }
    while(ligneActuel != NULL)
    {
        afficherLigne(ligneActuel);
        ligneActuel = ligneActuel->nextEtape;
    }
}
