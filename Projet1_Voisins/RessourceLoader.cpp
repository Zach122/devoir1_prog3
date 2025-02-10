#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "RessourceLoader.h"
#include "Liste.h"
#include "Noeud.h"

/// <summary>
/// Méthode permettant de convertir un vecteur de chaine de charactères en vecteur de float.
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
/// Méthode me permettant de retourner les données entrainées sous forme de liste chainée depuis mon fichier csv.
/// </summary>
/// <param name="ratio">Le ratio désiré. C'est un float. </param>
/// <param name="donnees">Les données que l'on veut entrainer.</param>
/// <returns>On retourne le tableau des données entrainées.</returns>
Liste GetTrainDataLinked(float ratio, const std::string& cheminFichier) {
    
    std::vector<std::vector<std::string>> donnees = ImportationDonnees(cheminFichier); // Je vais chercher les données.
    
    Liste liste;

    size_t tailleEntrainement = static_cast<size_t>(donnees.size() * ratio); // On va chercher la taille des données désirées selon le ratio.

    for (size_t i = 0; i < tailleEntrainement; ++i) { // On parcour les données en se fiant sur la taille trouvée.
        liste.ajouter(ConvertirLigneAFloat(donnees[i]));
    }

    return liste;
}

/// <summary>
/// Méthode me permettant de retourner les données à tester sous forme de liste chainée depuis mon fichier csv.
/// </summary>
/// <param name="ratio">Le ratio désiré. C'est un float. </param>
/// <param name="donnees">Les données que l'on veut tester.</param>
/// <returns>On retourne le tableau des données testées.</returns>
Liste GetTestDataLinked(float ratio, const std::string& cheminFichier) {

    std::vector<std::vector<std::string>> donnees = ImportationDonnees(cheminFichier); // On va chercher la taille des données désirées selon le ratio.

    Liste liste;

    size_t tailleTest = static_cast<size_t>(donnees.size() * ratio); // On va chercher la taille des données désirées selon le ratio.

    for (size_t i = tailleTest; i > 0; --i) { // Je parcours mes données en commençant par la fin.
        liste.ajouter(ConvertirLigneAFloat(donnees[i - 1]));
    }

    return liste;
}

/// <summary>
/// Méthode nous permettant d'importer les données des vins depuis mon fichier .csv.
/// </summary>
std::vector<std::vector<std::string>> ImportationDonnees(const std::string& cheminFichier) {

    std::vector<std::vector<std::string>> donnees;
    std::ifstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
        return donnees;
    }

    std::string ligne;

    while (std::getline(fichier, ligne)) { // Ici, il faut prendre tout les cellules des vecteurs !sauf la dernière.
        std::stringstream ss(ligne);
        std::string cellule, derniereCellule; // Double déclaration, mais deux variables différentes quand même.
        std::vector<std::string> ligneDonnees;

        while (std::getline(ss, cellule, ',')) {

            if (!derniereCellule.empty()) { // Si je ne suis pas à la première cellule, "push" ma dernière cellule.
                ligneDonnees.push_back(derniereCellule);
            }

            derniereCellule = cellule; 
        }

        donnees.push_back(ligneDonnees); //Après avoir poussser mes cellules dans ma ligne, je pousse ma ligne dans mes données.
    }

    fichier.close();
    return donnees;
}

