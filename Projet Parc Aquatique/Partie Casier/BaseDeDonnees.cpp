#include "BaseDeDonnees.h" // Inclusion du fichier d'en-tête "BaseDeDonnees.h"
#include <iostream> // Inclusion de la bibliothèque iostream
#include "requete.h" // Inclusion du fichier d'en-tête "requete.h"
BaseDeDonnees::BaseDeDonnees() {}
BaseDeDonnees::~BaseDeDonnees() {}
bool BaseDeDonnees::connexion(char *server, char *user, char *password, char *database) {
 //printf(Base;;connexion())
 mysql_init(&mysql); // Initialisation de la structure MYSQL
 maBase = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0); //
Connexion à la base de données
 if (maBase == NULL) {
 return false;
 }
 return true;
}
bool BaseDeDonnees::deconnexion() {
 mysql_close(maBase); // Fermeture de la connexion à la base de données
 return true;
}
bool BaseDeDonnees::envoyerRequete(char *requete) {
 int query_state;
 query_state = mysql_query(&mysql, requete); // Envoi de la requête SQL à la base de
données
 if (query_state != 0) {
 return false;
 }
 res = mysql_store_result(maBase); // Stockage du résultat de la requête
 return true;
}
MYSQL_RES *BaseDeDonnees::GetResponse() {
 return res; // Renvoie le résultat de la requête
}