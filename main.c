/* Cartouche


*/
#include <stdio.h>

int main ()
{
    int param = 0;
    do
    {
        printf("**** PLANIFICATEUR DE TRAJET ****\n\n");
        printf("Que souhaitez-vous faire?\n\n");
        printf("(1)     Afficher le  trajet en cours\n");
        printf("(2)     Ajouter une etape\n");
        printf("(3)     Supprimer une etape\n");
        printf("(4)     Supprimer la liste\n");
        printf("(autre) Quitter?\n");

        scanf("%d",&param);

        switch(param)
		{
		    //Affichage du trajet en cours
			case 1 :
            {
                generationCode (param);
            }
            default :
            {
                return 0;
            }






        }
    }
    while (param < 10);
    return 0;








}
