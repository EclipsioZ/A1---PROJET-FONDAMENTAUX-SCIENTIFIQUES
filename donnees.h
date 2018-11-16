<<<<<<< HEAD
/*
donnees.h
GASTON Cl�ment

Ensemble des protytpes de fonction du donnees.c
*/

#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED
#define NOM_FICHIER_LECTURE "Battements.csv"

// Cr�ation d'un nouveau type "struct cardio"
typedef struct cardio cardio;

// Stucture "cardio" poss�dant 3 types de donn�es
struct cardio{
    int battement;
    int temps;
    cardio *donneeSuivante;
};

// Charge le fichier .csv ligne par ligne
cardio* chargeFichier();

// Permert de cr�er chaque �l�ment de la liste cha�n�e
cardio* creerLigne(int temps, int battement);

// Permet de rajouter un nouvel �l�ment � la fin de la liste
void ajouterLigneListe(cardio *nouvelleLigne, cardio *derniereLigne);

// Parcout la liste cha�n�e pour l'afficher
void afficherFichier(cardio *premiereLigne);

// Permet l'affichage d'une ligne pr�cise
void afficherLigne (cardio *ligneActuel);

// Permet de sauvegarder le dernier tri r�alis� dans un nouveau fichier .txt
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
