#ifndef CLECTEURRFID_H
#define CLECTEURRFID_H
#include "CMFRC522.h" // Inclusion du fichier d'en-tête "CMFRC522.h"
#include <pigpio.h> // Inclusion du fichier d'en-tête "pigpio.h"
class ClecteurRFID
{
public:
 ClecteurRFID(); // Constructeur
 ~ClecteurRFID(); // Destructeur
 void fermerportspi(); // Méthode pour fermer le port SPI
 long long int lirebadge(); // Méthode pour lire le badge RFID
private:
 CMFRC522 mfrc522; // Instance de la classe CMFRC522 pour interagir avec le lecteur RFID
};
#endif // CLECTEURRFID_H