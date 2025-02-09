#include "serrure.h"
Serrure::Serrure() {
 wiringPiSetup(); // initialiser la bibliothèque wiringPi
 pinMode(RELAY_PIN, OUTPUT); // configurer la broche GPIO comme une sortie
 relay_pin = RELAY_PIN;
}
void Serrure::unlock() {
 printf("La serrure est déverrouillée.\n");
 digitalWrite(relay_pin, HIGH); // activer le module relais (serrure déverrouillée)
 delay(LOCK_TIME); // attendre
 digitalWrite(relay_pin, LOW); // désactiver le module relais (serrure verrouillée)
 printf("La serrure est verrouillée.\n");
}