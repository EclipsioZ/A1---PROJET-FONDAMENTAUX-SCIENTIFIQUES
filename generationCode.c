#include "generationCode.h"
#include <stdio.h>

void generationCode (int param, int VPIN, int SPIN)
{
    FILE *f;
    int checkCloture = 1;

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
    return ;
}
