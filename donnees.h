<<<<<<< HEAD
/*
donnees.h
GASTON Clément

Ensemble des protytpes de fonction du donnees.c
*/

#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED
#define NOM_FICHIER_LECTURE "Battements.csv"

// Création d'un nouveau type "struct cardio"
typedef struct cardio cardio;

// Stucture "cardio" possèdant 3 types de données
struct cardio{
    int battement;
    int temps;
    cardio *donneeSuivante;
};

// Charge le fichier .csv ligne par ligne
cardio* chargeFichier();

// Permert de créer chaque élément de la liste chaînée
cardio* creerLigne(int temps, int battement);

// Permet de rajouter un nouvel élément à la fin de la liste
void ajouterLigneListe(cardio *nouvelleLigne, cardio *derniereLigne);

// Parcout la liste chaînée pour l'afficher
void afficherFichier(cardio *premiereLigne);

// Permet l'affichage d'une ligne précise
void afficherLigne (cardio *ligneActuel);

// Permet de sauvegarder le dernier tri réalisé dans un nouveau fichier .txt
int sauvegardeFichier(cardio *premiereLigne);
=======
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
>>>>>>> master

#endif // DONNEES_H_INCLUDED
