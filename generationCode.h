/*
generationCode.h
GASTON Clément

Ensemble des protytpes de fonction du generationCode.c
*/

#ifndef GENERATIONCODE_H_INCLUDED
#define GENERATIONCODE_H_INCLUDED
#define NOM_FICHIER "param.h"

// Fonction générant le fichier param.h (qui lui même permet de gerer le réglage du coeur en LEDS)
void generationParamH (int param, int VPIN, int SPIN, int cardioParam);

#endif // GENERATIONCODE_H_INCLUDED
