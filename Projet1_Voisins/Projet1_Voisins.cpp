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
    std::string cheminFichier = "C:/Users/zacha/Desktop/Session Hiver 2025/Prog 3/binary-winequality-white.csv";
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
