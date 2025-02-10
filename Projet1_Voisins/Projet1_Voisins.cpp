#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Statistiques.h"
#include "RessourceLoader.h"
#include "Liste.h"

using namespace std;

int main()
{
     // Chemin vers le fichier CSV
    std::string cheminFichier = "../binary-winequality-white.csv"; // À tester voir si chemin fonctionne toujours
    float ratio = 0.8;

    std::vector<std::vector<std::string>> donnees;
    Liste listeDonneesEntrainees;
    Liste listeDonneesTestees;

    listeDonneesEntrainees = GetTrainDataLinked(ratio, cheminFichier);
    listeDonneesTestees = GetTestDataLinked(ratio, cheminFichier);
    int index = 0;

    // Afficher les données de listeDonneesEntrainees
    cout << "Données Entraînées :" << endl;
    for (const auto& ligne : listeDonneesEntrainees.getDonnees()) {
        for (const auto& valeur : ligne) {
            std::cout << valeur << " ";
        }
        std::cout << std::endl;
    }

    // Afficher les données de listeDonneesTestees
    cout << "\nDonnées Testées :" << endl;
    for (const auto& ligne : listeDonneesTestees.getDonnees()) {
        for (const auto& valeur : ligne) {
            std::cout << valeur << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
