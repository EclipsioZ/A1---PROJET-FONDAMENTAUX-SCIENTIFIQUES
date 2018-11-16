//Programme permettant de transférer des données Arduino en .CVS grâce à Processing
//importation de la librairie "processing.serial.*"
import processing.serial.*;
// Declaration de la sortie d'écriture
PrintWriter output;
Serial udSerial;

void setup() {
//configuration du port série
  udSerial = new Serial(this, Serial.list()[0], 9600);
// création du document "Battements.csv"
  output = createWriter ("Battements.csv");
}
// Fonction pour écrire dans le fichier "battement.cvs"
  void draw() {
// Condition pour savoir si le nombre de port disponnible en série est supérieur a 0
    if (udSerial.available() > 0) 
    {
// Définition d'une variable en string qui est égale au résultat d'au moins un des différents port en série
      String SenVal = udSerial.readString();
// Si SenVal est différent de null alors on passe à l'écriture de SenVal
      if (SenVal != null)
      {
        // Ecriture de la valeur de SenVal dans "battement.csv"
        output.print(SenVal);
        
      }
    }
  }

// Fonction qui termine le programme quand une touche est appuyer
  void keyPressed(){
// Permet de vider le flux dans la sortie
    output.flush();
// Fermeture de la sortie
    output.close();
// Sortie du programme
    exit(); 
  }
