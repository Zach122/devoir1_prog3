#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "RessourceLoader.h"
#include "Liste.h"
#include "Noeud.h"

/// <summary>
/// Méthode permettant de conveertir un vecteur de chaine de charactères en vecteur de float.
/// </summary>
/// <param name="rangee">La rangée. Le vecteur de chaine de caractères.</param>
/// <returns>Un vecteur de nombre flotant. </returns>
std::vector<float> ConvertirLigneAFloat(const std::vector<std::string>& rangee) {
    std::vector<float> floatRangee;

    for (const auto& cellule : rangee) { // Pour chaque cellule en référence (qui ne peut pas être modifié et "auto" permet au compilateur de déduire automatiquement le type d'une variable)
        try {
            float valeur = std::stof(cellule); // Convertire la cellule en float.
            floatRangee.push_back(valeur); // L'ajouter à la fin du tableau.
        }
        catch (const std::invalid_argument& e) { // S'il y a une erreur.
            throw std::runtime_error("Incapable de convertir la cellule: " + cellule); // Je l'affiche.
        }
    } 
    return floatRangee;
}


/// <summary>
/// Méthode me permettant de retourner les données entrainées de mon fichier csv.
/// </summary>
/// <param name="ratio">Le ratio désiré. C'est un float. </param>
/// <param name="donnees">Les données que l'on veut entrainer.</param>
/// <returns>On retourne le tableau des données entrainées.</returns>
std::vector<std::vector<float>> GetTrainData(float ratio, const std::vector<std::vector<std::string>>& donnees) {
    std::vector<std::vector<float>> donneesEntrainees;

    size_t tailleEntrainement = static_cast<size_t>(donnees.size() * ratio); // On va chercher la taille des données désirées.

    for (size_t i = 0; i < tailleEntrainement; ++i) { // On parcour les données en se fiant sur la taille trouvée.
        donneesEntrainees.push_back(ConvertirLigneAFloat(donnees[i]));
    }

    return donneesEntrainees;
}

/// <summary>
/// Méthode me permettant de retourner les données à tester de mon fichier csv.
/// </summary>
/// <param name="ratio">Le ratio désiré. C'est un float. </param>
/// <param name="donnees">Les données que l'on veut tester.</param>
/// <returns>On retourne le tableau des données testées.</returns>
std::vector<std::vector<float>> GetTestData(float ratio, const std::vector<std::vector<std::string>>& donnees) {

    std::vector<std::vector<float>> donneesTests;

    size_t tailleTest = static_cast<size_t>(donnees.size() * ratio); // On va chercher la taille des données désirées.

    for (size_t i = tailleTest - 1; i >= 0; --i) { // On parcour les données en se fiant sur la taille trouvée.
        donneesTests.push_back(ConvertirLigneAFloat(donnees[i]));
    }

    return donneesTests;
}

/// <summary>
/// Méthode me permettant de retourner les données entrainées de mon fichier csv.
/// </summary>
/// <param name="ratio">Le ratio désiré. C'est un float. </param>
/// <param name="donnees">Les données que l'on veut entrainer.</param>
/// <returns>On retourne le tableau des données entrainées.</returns>
void GetTrainDataLinked(float ratio, const std::vector<std::vector<std::string>>& donnees) {
    std::vector<std::vector<float>> donneesEntrainees;
    Liste liste;

    size_t tailleEntrainement = static_cast<size_t>(donnees.size() * ratio); // On va chercher la taille des données désirées.

    for (size_t i = 0; i < tailleEntrainement; ++i) { // On parcour les données en se fiant sur la taille trouvée.
        liste.ajouter(ConvertirLigneAFloat(donnees[i]));
    }

    /*Noeud* courant = liste.getPremierPointeur();
    while (courant != nullptr) {
        std::cout << courant->donnee;                        //Pas sûr
        courant = courant->suivant;
    }*/

}
