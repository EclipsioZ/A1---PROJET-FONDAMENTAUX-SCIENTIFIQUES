#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

typedef struct cardio cardio;

struct cardio{
    int battement;
    int temps;
    cardio *nextEtape;
};

cardio* chargeFichier(int tailleFichier);
void afficherLigne(cardio *ligneActuel);
void afficherFichier(cardio *ligneActuel);

#endif // DONNEES_H_INCLUDED
