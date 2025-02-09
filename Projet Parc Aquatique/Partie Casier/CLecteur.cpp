#include "ClecteurRFID.h" // Inclusion du fichier d'en-tête "ClecteurRFID.h"
#include <iostream> // Inclusion de la bibliothèque iostream
#include <sstream> // Inclusion de la bibliothèque sstream
#include <math.h> // Inclusion de la bibliothèque math.h
#include "pigpio.h" // Inclusion du fichier d'en-tête "pigpio.h"
#include <unistd.h> // Inclusion de la bibliothèque unistd.h
#include <wiringPi.h> // Inclusion de la bibliothèque wiringPi
ClecteurRFID::ClecteurRFID()
{
 // Constructeur
}
ClecteurRFID::~ClecteurRFID()
{
 // Destructeur
}
void ClecteurRFID::fermerportspi()
{
 gpioTerminate(); // Terminaison de la bibliothèque GPIO
}
long long int ClecteurRFID::lirebadge()
{
 long long int decimalValue = 0; // Variable pour stocker la valeur décimale du badge
 int rep = 1; // Variable pour contrôler la boucle
 mfrc522.PCD_Init(); // Initialisation du lecteur RFID
 while (rep == 1) {
 if (mfrc522.isNewCardPresent() == 0) { // Détection d'un badge RFID au niveau du
lecteur
 // std::cout << "Nouveau badge detecté..." << std::endl;
 delay(1000); // Attente de 1 seconde
 if (mfrc522.PICC_ReadCardSerial()); // Lecture de la carte RFID
 uint8_t nuidPICC[5]; // Tableau pour stocker l'identifiant du badge
 for (int i = 11; i < 16; ++i) {
 nuidPICC[i - 11] = mfrc522.uid.uidByte[i]; // Copie de l'identifiant du
badge dans le tableau
 }
 printf("\n");
 for (int i = 0; i < 4; ++i) {
 decimalValue += nuidPICC[i] << (8 * i); // Conversion de l'identifiant du
badge en valeur décimale
 }
 return decimalValue; // Retour de la valeur décimale du badge
 }
 }
}