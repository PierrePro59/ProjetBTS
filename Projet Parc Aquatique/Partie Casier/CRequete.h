#ifndef REQUETE_H
#define REQUETE_H
#include <string> // Inclusion de la bibliothèque string
#include <vector> // Inclusion de la bibliothèque vector
#include "BaseDeDonnees.h" // Inclusion du fichier d'en-tête "BaseDeDonnees.h"
class Requete {
private:
 BaseDeDonnees* m_bdd; // Pointeur vers l'objet BaseDeDonnees
public:
 Requete(BaseDeDonnees* bdd); // Constructeur prenant en paramètre un objet
BaseDeDonnees
 ~Requete(); // Destructeur
 bool verifierExistenceId(long long int numerobadge); // Méthode pour vérifier
l'existence d'un ID dans la base de données
 MYSQL_RES *REPONSE(); // Méthode pour obtenir le résultat d'une requête
};
#endif // REQUETE_H