#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Statistiques.h"
#include "RessourceLoader.h"
#include "Noeud.h"

using namespace std;

int main()
{
    ////Point 1 Statistiques Test
    //vector<float> valeurs = { 5.0f, 2.0f, 10.0f, 7.0f, 3.0f };

    //float moyenne = CalculerMoyenne(valeurs);
    //float mediane = CalculerMediane(valeurs);
    //float ecartType = CalculerEcartType(valeurs);
    //
    //cout << "Le resultat est : " << mediane;

    ////Point 2 Statistiques Test

    //vector<float> point1 = { 1.0f, 2.0f, 9.0f, 3.6f };
    //vector<float> point2 = { 4.0f, 6.0f, 6.9f, 6.9f };

    //float distanceEuclidienne = CalculerDistanceEuclidienne(point1, point2);
    //float distanceManhattan = CalculerDistanceManhattan(point1, point2);
    //cout << "\nDistance : " << distanceManhattan;

    // Chemin vers le fichier CSV
    std::string cheminFichier = "C:/Users/pelch/OneDrive/Bureau/Prog3/Projet1/devoir1_prog3/binary-winequality-white.csv";
    std::ifstream fichier(cheminFichier);

    // Vérifier si le fichier s'ouvre correctement
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
        return 1;
    }

    std::string ligne;
    std::vector<std::vector<std::string>> donnees; // Stocke toutes les lignes et colonnes


    // Lire le fichier ligne par ligne
    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne); // Convertit la ligne en stream
        std::string cellule;
        std::vector<std::string> ligneActuelle;

        // Diviser la ligne en colonnes en utilisant ',' comme délimiteur
        while (std::getline(ss, cellule, ',')) {
            ligneActuelle.push_back(cellule);
        }
        donnees.push_back(ligneActuelle);
    }

    fichier.close();

    // Afficher les données pour vérifier
    for (const auto& ligne : donnees) {
        for (const auto& cellule : ligne) {
            std::cout << cellule << " ";
        }
        std::cout << std::endl;
    }

    return 0;

}
