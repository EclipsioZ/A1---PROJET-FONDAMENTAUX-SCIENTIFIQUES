/*
Coeur.ino
ROSSI Florian

Programme permettant de : - modifier l'allumage du coeurs en LEDS
                        
*/
#include <stdio.h>
#include <stdlib.h>
#include "coeur.h"
#include "param.h"
int PIN = 2;           // Valeur du premier PIN ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â  ne pas modifier
int VAR = 1;           // Valeur pour le paramÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¨tre 6 et 7 ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â  ne pas modifier
bool a = true;         // Valeur boolÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©enne ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â  ne pas modifier
         // Valeur qui varie selon la rapiditÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â© du battement de coeur

// Toutes les leds s'allument suivant le battement de coeur
int clignote()
  {
  pinMode(PIN, OUTPUT);
  for (PIN=2 ; PIN<12 ;PIN++)
    {
      pinMode(PIN, OUTPUT);
      digitalWrite (PIN, HIGH);
    }
  delay (battement/4);
  for (PIN=2 ; PIN<12 ;PIN++)
    {
      pinMode(PIN, OUTPUT);
      digitalWrite (PIN, LOW);
    }
  delay (battement/4);
}

// Une LED sur deux s'allume suivant le battement de coeur
int unesurdeux()
{
  if (a == true)
  {
  a = false;
  pinMode(PIN, OUTPUT);
  for (PIN=2 ; PIN<12 ; PIN = PIN + 2)
    {
      pinMode(PIN, OUTPUT);
      digitalWrite (PIN, LOW);
    }
  }
  else
  {
  a = true;
  pinMode(PIN, OUTPUT);
  for (PIN=2 ; PIN<12 ; PIN = PIN + 2)
    {
      pinMode(PIN, OUTPUT);
      digitalWrite (PIN, HIGH);
    }
  }
  delay (battement/2);
}

// Une LED sur X s'allume suivant le nombre donner par l'utilisateur et les battements de coeur
int unesurX()
{
  if (a == true)
  {
  a = false;
  pinMode(PIN, OUTPUT);
  for (PIN=2 ; PIN<12 ;PIN = PIN + VPIN)
    {
      pinMode(PIN, OUTPUT);
      digitalWrite (PIN, LOW);
    }
  }
  else
  {
  a = true;
  pinMode(PIN, OUTPUT);
  for (PIN=2 ; PIN<12 ;PIN = PIN + VPIN)
    {
      pinMode(PIN, OUTPUT);
      digitalWrite (PIN, HIGH);
    }
  }
  delay (battement/2);
}

// Une seule LED s'allume suivant le pin donner par l'utilisateur et les battements de coeur
int unePIN()
{
  pinMode(SPIN, OUTPUT);
  digitalWrite (SPIN, HIGH);
  delay (battement/4);
  pinMode(PIN, OUTPUT);
  digitalWrite (SPIN, LOW);
  delay (battement/4);
}

// Une seule LED s'allume en chenille suivant les battements de coeur
int chenille()
{
  pinMode(PIN, OUTPUT);
  if (PIN >= 2 && PIN <= 12)
  {
    digitalWrite (PIN, HIGH);
    delay(battement/4);
    digitalWrite (PIN, LOW);
    delay(battement/4);
  }
  else
  {
    PIN = 1;
  }
  PIN ++;
  }
  
  // Les LEDS s'allument toutes ÃƒÆ’Ã‚Â  la chaine puis s'ÃƒÆ’Ã‚Â©teignent ÃƒÆ’Ã‚Â  la chaines
int chaine()
{
  pinMode(PIN, OUTPUT);
  if (VAR == 1 && PIN <= 12)
  {
    digitalWrite (PIN, HIGH);
    delay(battement/2);
    if (PIN == 11)
    {
      VAR = 2;
      PIN = 1;
    }
  }
  else
  {
    if (VAR == 2 && PIN <= 12)
    {
      digitalWrite (PIN, LOW);
      delay(battement/2);
      if (PIN == 11)
      {
        VAR = 1;
        PIN = 1;
      }
    }
  }
  PIN ++;
}

// Les LEDS s'allument toutes ÃƒÆ’Ã‚Â  la chaine par 5 puis s'ÃƒÆ’Ã‚Â©teignent ÃƒÆ’Ã‚Â  la chaines
int chainecinq(){
  pinMode(PIN, OUTPUT);
  pinMode(PIN+5, OUTPUT);
  if (VAR == 1 && PIN <= 7)
  {
    digitalWrite (PIN, HIGH);
    digitalWrite (PIN + 5, HIGH);
    delay(battement/2);
    if (PIN == 6)
      {
        VAR = 2;
        PIN = 1;
      }
  }
  else
  {
    pinMode(PIN, OUTPUT);
    pinMode(PIN+5, OUTPUT);
    if (VAR == 2 && PIN <= 7)
    {
      digitalWrite (PIN, LOW);
      digitalWrite (PIN + 5, LOW);
      delay(battement/2);
      if (PIN == 6)
      {
        VAR = 1;
        PIN = 1;
      }
    }
  }
  PIN ++; 
}
int coeur() {
  if (param==0)
  {clignote();}      // Toutes les leds s'allument suivant le battement de coeur
  if (param==1)
  {unesurdeux();}      // Une LED sur deux s'allume suivant le battement de coeur
  if (param==2)
  {unesurX();}      // Une LED sur X s'allume suivant le nombre donner par l'utilisateur et les battements de coeur
  if (param==3)
  {unePIN();}      // Une seule LED s'allume suivant le pin donner par l'utilisateur et les battements de coeur
  if (param==4)
  {chenille();}      // Une seule LED s'allume en chenille suivant les battements de coeur
  if (param==5)
  {chaine();}      // Les LEDS s'allument toutes ÃƒÆ’Ã‚Â  la chaine puis s'ÃƒÆ’Ã‚Â©teignent ÃƒÆ’Ã‚Â  la chaines
  if (param==6)
  {chainecinq();}      // Les LEDS s'allument toutes ÃƒÆ’Ã‚Â  la chaine par 5 puis s'ÃƒÆ’Ã‚Â©teignent ÃƒÆ’Ã‚Â  la chaines
  pinMode(PIN, OUTPUT);

}
