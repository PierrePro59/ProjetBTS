#include <iostream> // Inclusion de la bibliothèque iostream
#include <unistd.h> // Inclusion de la bibliothèque unistd.h
#include "ClecteurRFID.h" // Inclusion du fichier d'en-tête "ClecteurRFID.h"
#include <wiringPi.h> // Inclusion de la bibliothèque wiringPi
#include "BaseDeDonnees.h" // Inclusion du fichier d'en-tête "BaseDeDonnees.h"
#include "requete.h" // Inclusion du fichier d'en-tête "requete.h"
#include "CMFRC522.h" // Inclusion du fichier d'en-tête "CMFRC522.h"
using namespace std;
void delay(int ms) {
#ifdef WIN32
 Sleep(ms);
#else
 usleep(ms * 1000);
#endif
}
int main(int argc, char *argv[]) {
 BaseDeDonnees bdd; // Instance de la classe BaseDeDonnees
 if (!bdd.connexion("172.29.21.52", "utilisateur", "root", "parc")) { // Connexion à la
base de données
 cerr << "Erreur de connexion à la base de données." << endl;
 return 1;
 } else {
 if (gpioInitialise() < 0) { // Initialisation du port SPI
 cerr << "Port SPI non initialisé." << endl;
 } else {
 ClecteurRFID monlecteur; // Instance de la classe ClecteurRFID
 int retourhaut = 1; // Variable pour contrôler la boucle
 while (retourhaut != 0) {
 long long int decimalValue = monlecteur.lirebadge(); // Lecture du badge
RFID
 if (decimalValue != 0) {
 printf("Numero de badge converti en base 10: %lli\n", decimalValue);
 Requete req(&bdd); // Instance de la classe Requete avec la base de
données en paramètre
 bool existe = req.verifierExistenceId(decimalValue); // Vérification de
l'existence de l'ID dans la base de données
 std::cout << "la valeur du booléen est : " << existe << std::endl;
 if (existe == true) {
 std::cout << "L'ID " << decimalValue << " existe dans la base de
données." << std::endl;
 } else {
 cerr << "L'ID " << decimalValue << " n'existe pas dans la base de
données." << endl;
 // break;
}
 }
 delay(1000); // Attente de 1 seconde
 retourhaut = 1;
 }
 monlecteur.fermerportspi(); // Fermeture du port SPI
 }
 }
 return 0;
}