#include <iostream>
#include <string>
#include <vector>

#include "Statistiques.h"
#include "RessourceLoader.h"

using namespace std;

class dataset {
public:
    dataset(float aciditeFixe, float acideVolatile, float acideCitrique, float sucreResiduel, float chlorureSodium, float dioxydeSoufreLibre, float dioxydeSoufreTotal, float densite, float pH, float sulfatePotassium, float alcool, float bon)
    {
        m_aciditeFixe = aciditeFixe; // (grammes d’acide tartrique / dm3)
        m_acideVolatile = acideVolatile; // (grammes d’acide acétique / dm3)
        m_acideCitrique = acideCitrique; // (g / dm3)
        m_sucreResiduel = sucreResiduel; // (g / dm3)
        m_chlorureSodium = chlorureSodium; // (g / dm3)
        m_dioxydeSoufreLibre = dioxydeSoufreLibre; // (mg / dm3)
        m_dioxydeSoufreTotal = dioxydeSoufreTotal; // (mg / dm3)
        m_densite = densite; // (g / cm3)
        m_pH = pH;
        m_sulfatePotassium = sulfatePotassium; // (g / dm3)
        m_alcool = alcool; // (vol.%)
        m_bon = bon;
    }

private:
    float m_aciditeFixe;
    float m_acideVolatile;
    float m_acideCitrique;
    float m_sucreResiduel;
    float m_chlorureSodium;
    float m_dioxydeSoufreLibre;
    float m_dioxydeSoufreTotal;
    float m_densite;
    float m_pH;
    float m_sulfatePotassium;
    float m_alcool;
    float m_bon;
};

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

    //    // Chemin vers le fichier CSV
    //std::string cheminFichier = "C:/Users/zacha/Downloads/binary-winequality-white.csv";
    //std::ifstream fichier(cheminFichier);

    //// Vérifier si le fichier s'ouvre correctement
    //if (!fichier.is_open()) {
    //    std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
    //    return 1;
    //}

    //std::string ligne;
    //std::vector<std::vector<std::string>> donnees; // Stocke toutes les lignes et colonnes


    //// Lire le fichier ligne par ligne
    //while (std::getline(fichier, ligne)) {
    //    std::stringstream ss(ligne); // Convertit la ligne en stream
    //    std::string cellule;
    //    std::vector<std::string> ligneActuelle;

    //    // Diviser la ligne en colonnes en utilisant ',' comme délimiteur
    //    while (std::getline(ss, cellule, ',')) {
    //        ligneActuelle.push_back(cellule);
    //    }
    //    donnees.push_back(ligneActuelle);
    //}

    //fichier.close();

    //// Afficher les données pour vérifier
    //for (const auto& ligne : donnees) {
    //    for (const auto& cellule : ligne) {
    //        std::cout << cellule << " ";
    //    }
    //    std::cout << std::endl;
    //}

    //return 0;
}
