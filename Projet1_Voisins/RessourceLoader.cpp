#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "RessourceLoader.h"

/// <summary>
/// M�thode permettant de conveertir un vecteur de chaine de charact�res en vecteur de float.
/// </summary>
/// <param name="rangee">La rang�e. Le vecteur de chaine de caract�res.</param>
/// <returns>Un vecteur de nombre flotant. </returns>
std::vector<std::vector<std::string>> ImportationDonnees(const std::string cheminFichier) {
    std::ifstream fichier(cheminFichier);
    std::vector<std::vector<std::string>> donnees; // Stocke toutes les lignes et colonnes


    // V�rifier si le fichier s'ouvre correctement
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
        return donnees;
    }

    std::string ligne;


    // Lire le fichier ligne par ligne
    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne); // Convertit la ligne en stream
        std::string cellule;
        std::vector<std::string> ligneActuelle;

        // Diviser la ligne en colonnes en utilisant ',' comme d�limiteur
        while (std::getline(ss, cellule, ',')) {
            ligneActuelle.push_back(cellule);
        }
        donnees.push_back(ligneActuelle);
    }

    fichier.close();

    return donnees;
}


/// <summary>
/// M�thode permettant de conveertir un vecteur de chaine de charact�res en vecteur de float.
/// </summary>
/// <param name="rangee">La rang�e. Le vecteur de chaine de caract�res.</param>
/// <returns>Un vecteur de nombre flotant. </returns>
std::vector<float> ConvertirLigneAFloat(const std::vector<std::string>& rangee) {
    std::vector<float> floatRangee;

    for (const auto& cellule : rangee) { // Pour chaque cellule en r�f�rence (qui ne peut pas �tre modifi� et "auto" permet au compilateur de d�duire automatiquement le type d'une variable)
        try {
            float valeur = std::stof(cellule); // Convertire la cellule en float.
            floatRangee.push_back(valeur); // L'ajouter � la fin du tableau.
        }
        catch (const std::invalid_argument& e) { // S'il y a une erreur.
            throw std::runtime_error("Incapable de convertir la cellule: " + cellule); // Je l'affiche.
        }
    } 
    return floatRangee;
}


/// <summary>
/// M�thode me permettant de retourner les donn�es entrain�es de mon fichier csv.
/// </summary>
/// <param name="ratio">Le ratio d�sir�. C'est un float. </param>
/// <param name="donnees">Les donn�es que l'on veut entrainer.</param>
/// <returns>On retourne le tableau des donn�es entrain�es.</returns>
std::vector<std::vector<float>> GetTrainData(float ratio, const std::vector<std::vector<std::string>>& donnees) {
    std::vector<std::vector<float>> donneesEntrainees;

    size_t tailleEntrainement = static_cast<size_t>(donnees.size() * ratio); // On va chercher la taille des donn�es d�sir�es.

    for (size_t i = 0; i < tailleEntrainement; ++i) { // On parcour les donn�es en se fiant sur la taille trouv�e.
        donneesEntrainees.push_back(ConvertirLigneAFloat(donnees[i]));
    }

    return donneesEntrainees;
}

/// <summary>
/// M�thode me permettant de retourner les donn�es � tester de mon fichier csv.
/// </summary>
/// <param name="ratio">Le ratio d�sir�. C'est un float. </param>
/// <param name="donnees">Les donn�es que l'on veut tester.</param>
/// <returns>On retourne le tableau des donn�es test�es.</returns>
std::vector<std::vector<float>> GetTestData(float ratio, const std::vector<std::vector<std::string>>& donnees) {

    std::vector<std::vector<float>> donneesTests;

    size_t tailleTest = static_cast<size_t>(donnees.size() * ratio); // On va chercher la taille des donn�es d�sir�es.

    for (size_t i = static_cast<size_t>(donnees.size() * ratio); i < donnees.size(); ++i) {
        donneesTests.push_back(ConvertirLigneAFloat(donnees[i]));
    }

    return donneesTests;
}
