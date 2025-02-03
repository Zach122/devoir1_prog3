#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Statistiques.h"
#include "RessourceLoader.h"

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
    std::vector<std::vector<float>> donneesEntraine;
    std::vector<std::vector<float>> donneesTestes;

    donnees = ImportationDonnees(cheminFichier);
    donneesEntraine = GetTrainData(ratio, donnees);
    donneesTestes = GetTestData(ratio, donnees);
    int index = 0;


    for (const auto& ligne : donneesTestes) { // Parcours des lignes
        for (const auto& cellule : ligne) { // Parcours des colonnes
            std::cout << cellule << " "; // Affichage des cellules
        }
        std::cout << std::endl; // Retour à la ligne après chaque ligne de données
    }

    return 0;
}
