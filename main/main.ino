/*
main.ino
ROSSI Florian

Programme permettant de : - modifier l'allumage du coeurs en LEDS
                          - Modifier les parametre du capteur cardio
*/
#include <stdio.h>
#include <stdlib.h>
#include "Coeur.h"
#include "cardio.h"
#include "param.h"
int valeurPrecedente = 0;
long tempsPrecedent = 0;
int battement = 60;
long times;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (CARDIO >= 0 && CARDIO <= 5)
  {
 cardio();
  }
  if (CARDIO == 6)
  {
  int valeurActuelle, valeurSeuil;
  long tempsDetection;
  int frequence;
  int pulsation;
  valeurActuelle = analogRead(0);
  valeurSeuil = 270;

  if (valeurActuelle > valeurSeuil) {  // on est dans la zone max
    if (valeurPrecedente <= valeurSeuil) {  // est-ce qu'on vient d'y entrer?
      tempsDetection = millis();
      times = millis();
      if (tempsDetection > (tempsPrecedent + 200)){  // ce n'est pas seulement du bruit?
        frequence = (1000.0 * 60.0) / (tempsDetection - tempsPrecedent);
        coeur();
        Serial.print(times);
        Serial.print(";");
        Serial.println(((1000.0 * 60.0) / (tempsDetection - tempsPrecedent)),0);
        tempsPrecedent = tempsDetection;
        pulsation = (frequence/60)*1000;
        battement = (1000000/pulsation);
        delay (battement/2);
      }
      }
    }

  valeurPrecedente = valeurActuelle;
  }
}
