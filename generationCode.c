/*
generationCode.c
GASTON Cl�ment

Fichier permettant la cr�ation du fichier param.h permettant le r�glage du coeur en LEDS
*/

#include <stdio.h>
#include "generationCode.h"

<<<<<<< HEAD
// Fonction g�n�rant le fichier param.h (qui lui m�me permet de gerer le r�glage du coeur en LEDS)
void generationParamH (int param, int VPIN, int SPIN, int cardioParam)
{
    FILE *f;
    int verifFermeture = 1;
=======
void generationCode (int param, int VPIN, int SPIN)
{
    FILE *f;
    int checkCloture = 1;
>>>>>>> master

    f = fopen(NOM_FICHIER, "w");
    if(f == NULL)
    {
        printf("Echec d'ouverture du fichier\n");
    }
    else
    {
        fprintf(f, "#define param %d\n", param);
        fprintf(f, "#define VPIN %d\n", VPIN);
        fprintf(f, "#define SPIN %d\n", SPIN);
<<<<<<< HEAD
        fprintf(f, "#define CARDIO %d\n", cardioParam);
    }

    verifFermeture = fclose(f);
    if( verifFermeture != 0)
    {
=======
    }
    checkCloture = fclose(f);
    if( checkCloture == 0)
    {
        //printf("Succes fermeture du fichier\n");
    }
    else
    {
>>>>>>> master
        printf("Echec fermeture du fichier\n");
    }
    return ;
}
