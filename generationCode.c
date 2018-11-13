#include "generationCode.h"
#include <stdio.h>

void generationCode (int param)
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
        fprintf(f, "#Salut laetitia %d\n", param);
        fprintf(f, "#define VPIN %d\n", VPIN);
        fprintf(f, "#define SPIN %d\n", SPIN);
        fprintf(f, "#define battement %d\n", battement);
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
