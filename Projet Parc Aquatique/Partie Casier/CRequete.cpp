#include "requete.h" // Inclusion du fichier d'en-tête "requete.h"
#include "BaseDeDonnees.h" // Inclusion du fichier d'en-tête "BaseDeDonnees.h"
#include <iostream> // Inclusion de la bibliothèque iostream
#include "CMFRC522.h" // Inclusion du fichier d'en-tête "CMFRC522.h"
#include <chrono> // Inclusion de la bibliothèque chrono
Requete::Requete(BaseDeDonnees* bdd) {
 m_bdd = bdd; // Assignation de l'objet BaseDeDonnees passé en paramètre
}
Requete::~Requete() {}
bool Requete::verifierExistenceId(long long int numerobadge) {
 char req[500];
 sprintf(req, "SELECT ID FROM visiteur WHERE ID='%lld'", numerobadge); // Création de la
requête SQL pour vérifier l'existence de l'ID dans la table "visiteur"
 printf("La requete est %s\n", req);
 if (m_bdd->envoyerRequete(req)) { // Envoi de la requête à la base de données
 MYSQL_RES* resultat = REPONSE(); // Récupération du résultat de la requête
 if (resultat != NULL) {
 MYSQL_ROW row = mysql_fetch_row(resultat); // Récupération de la première ligne
du résultat
 mysql_free_result(resultat); // Libération de la mémoire occupée par le
résultat
 if (row != NULL) {
 return true; // L'ID existe dans la base de données
 }
 }
 }
 return false; // L'ID n'existe pas dans la base de données
}