#include "lecteurRFID.h"
#include "requete.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <wiringPi.h>
#include "serrure.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
 CRequete mesrequetes;
 int rep = 1;
 char nomutilisateur[30];
 char prenomutilisateur[30];
 char numerodebadge[30];
 MYSQL_ROW row;
 if (gpioInitialise() < 0) {
 printf("Port SPI non initialisé");
 }
 else {
 lecteurRFID monlecteur;
 printf("Port SPI initialisé");
 srand(time(NULL)); // initialiser le générateur de nombres aléatoires
 Serrure serrure;
 while (rep == 1) {
 long long int numerobadge = monlecteur.lirebadge();
 if (numerobadge != 0) {
 printf("numero de badge convertie en base 10: %lli", numerobadge);
 printf("\n");
 cout << "Bienvenue dans la base parc pour faire du CRUD sur la table
casier" << endl;
 if (mesrequetes.connexionBdd() == true) {
 printf("connexion ok\n");
 printf("afficher un badge %lli \n", numerobadge);
 if (mesrequetes.lireDonnees(numerobadge) == true) {
 printf("requete réussie \n");
 unsigned int num_champs = mysql_num_fields(mesrequetes.REPONSE());
 printf("\n nombre de champs %i.\n", num_champs);
 //Tant qu'il y a encore un résultat ...
while ((row = mysql_fetch_row(mesrequetes.REPONSE())))
 {
 //On fait une boucle pour avoir la valeur de chaque champs
for (int i = 0; i < num_champs; i++)
 {
 //On ecrit toutes les valeurs
 printf("-%s- ", row[i]);
 }
/*printf("\n");
strcpy(numerodebadge,row[1]);
strcpy(nomutilisateur,row[2]);
 strcpy(prenomutilisateur,row[3]);
 printf("\n Badge : %s, , %s , %s
\n",numerodebadge,nomutilisateur,prenomutilisateur);
 */
 }
 //Libération du jeu de résultat
mysql_free_result(mesrequetes.REPONSE());
 }
 }
 printf("Voulez vous continuer ? oui:1 non:0\n");
 scanf("%i", &rep);
 mesrequetes.deconnexionBdd();
 }
 int random_number = rand() % 2; // générer un nombre aléatoire entre 0 et 1
 if (random_number == 0) {
 serrure.unlock(); // déverrouiller la serrure
 }
 delay(5000); // attendre 5 secondes avant de vérifier à nouveau
 }
 monlecteur.fermerportspi();
 }
 return 0;
}