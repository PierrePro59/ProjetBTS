ifndef SERRURE_H
#define SERRURE_H
#include <wiringPi.h>
#include <stdio.h>
#define RELAY_PIN 29 // numéro de la broche GPIO utilisée pour le module relais
#define LOCK_TIME 2000 // durée de verrouillage/déverrouillage (en millisecondes)
class Serrure {
public:
 Serrure(); // constructeur
 void unlock(); // méthode pour déverrouiller la serrure
 //void lock();
private:
 int relay_pin; // numéro de la broche GPIO utilisée pour le module relais
};
#endif