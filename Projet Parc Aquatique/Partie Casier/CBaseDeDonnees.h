#ifndef BASE_DE_DONNEES_H
#define BASE_DE_DONNEES_H
#include <mysql/mysql.h> // Inclusion du fichier d'en-tête "mysql.h"
#include <string> // Inclusion de la bibliothèque string
class BaseDeDonnees {
private:
 MYSQL mysql; // Structure MYSQL pour la gestion de la base de données
 MYSQL *maBase; // Pointeur vers la connexion à la base de données
 MYSQL_RES *res; // Pointeur vers le résultat d'une requête
public:
 BaseDeDonnees(); // Constructeur
 ~BaseDeDonnees(); // Destructeur
 bool connexion(char *server, char *user, char *password, char *database); // Méthode
pour établir une connexion à la base de données
 bool deconnexion(); // Méthode pour se déconnecter de la base de données
 bool envoyerRequete(char *requete); // Méthode pour envoyer une requête SQL à la base
de données
 MYSQL_RES *GetResponse(); // Méthode pour obtenir le résultat d'une requête
};
#endif // BASE_DE_DONNEES_H