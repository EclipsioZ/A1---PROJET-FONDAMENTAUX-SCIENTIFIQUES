#include "Coeur.h"
#include "cardio.h"
#include "param.h"
int RandomMin;
int RandomMax;
long time;

int cardio()

// Simulation coeur d'un Nouveau-ne
{
if (CARDIO == 0)
{
  RandomMin = 1500;
  RandomMax = 3167;
}

// Simulation coeur d'un bebe de un a deux ans
if (CARDIO == 1)
{
  RandomMin = 1167;
  RandomMax = 2500;
}

// Simulation coeur d'un enfant de trois a cinq ans
if (CARDIO == 2)
{
  RandomMin = 1167;
  RandomMax = 2333;
}

// Simulation coeur d'un enfant de six a douze ans
if (CARDIO == 3)
{
  RandomMin = 1083;
  RandomMax = 2083;
}

// Simulation coeur d'un adolescent ou d'un adulte
if (CARDIO == 4)
{
  RandomMin = 1000;
  RandomMax = 1333;
}

// Simulation coeur d'une personne agee
if (CARDIO == 5)
{
  RandomMin = 1000;
  RandomMax = 1167;
}
if (CARDIO >= 0 && CARDIO <= 5)
{
  int freq = 0;
  float puls = 0;
  for(int i=0; i<61; i++)
  {
    
  puls = random(RandomMin,RandomMax);
  freq = (puls/1000)*60;
  time = millis();
  Serial.print(time);
  Serial.print(";");
  Serial.println(freq);
  battement = (1000000/puls);
  coeur();
  delay(battement/2);
  }
  
  }
}
