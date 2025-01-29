#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "Statistiques.h"

using namespace std;

/// <summary>
/// Méthode qui calcul la moyenne des valeurs reçues
/// </summary>
/// <param name="tableau">Tableau de nombres</param>
/// <returns>La moyenne des nombres</returns>
float CalculerMoyenne(vector<float> tableau)
{
    float somme = 0.0f;

    for (int i = 0; i < tableau.size(); ++i)
    {
        somme += tableau[i];
    }

    return somme / tableau.size();
}

/// <summary>
/// Méthode qui calcul la médiane des valeurs reçues
/// </summary>
/// <param name="tableau">Tableau de nombre</param>
/// <returns>La médiane des nombres</returns>
float CalculerMediane(vector<float> tableau)
{

    //Mettre les valeurs en ordre croissant
    for (int i = 0; i < tableau.size() - 1; ++i) //prend une valeur à comparer
    {
        for (int j = i + 1; j < tableau.size(); ++j) //parcourt les valeurs après celle à comparer
        {
            //si la première valeur est plus grande que celle avec laquelle elle est comparée
            if (tableau[i] > tableau[j])
            {
                //on les échanges
                swap(tableau[i], tableau[j]); 
            }
        }
    }

    int taille = tableau.size();

    //si la taille est impaire, la médiane est l'élément en plein milieu
    if (taille % 2 != 0)
    {
        return tableau[taille / 2];
    }
    //sinon, c'est paire, donc la médiane est la moyenne des deux éléments du centre
    else
    {
        int milieu = taille / 2;
        return (tableau[milieu - 1] + tableau[milieu]) / 2.0f;
    }
}
/// <summary>
/// Méthode qui calcul l'écrat type des valeurs reçues
/// </summary>
/// <param name="tableau">Le vector de valeurs</param>
/// <returns>l'écrat type calculé</returns>
float CalculerEcartType(vector<float> tableau)
{
    float moyenne = CalculerMoyenne(tableau);

    //Calculer la somme des écarts de chaque valeur par rapport à la moyenne, au carré.
    float sommeDesEcartsAuCarre = 0.0f;
    for (float valeur : tableau)
    {
        sommeDesEcartsAuCarre += pow(valeur - moyenne, 2); //pow calcul l'exposant spécifié (ici, 2)
    }

    //On divise la somme par le nombre total d'éléments
    float divisionSommeEcartNombre = sommeDesEcartsAuCarre / tableau.size();

    //On retourne la racine
    return sqrt(divisionSommeEcartNombre);
}
/// <summary>
/// Méthode qui calcule la distance Euclidienne entre dux points.
/// </summary>
/// <param name="">coordonnées du premier point</param>
/// <param name="">coordonnées du deuxieme point</param>
/// <returns>La distance Euclidienne</returns>
float CalculerDistanceEuclidienne(const vector<float> point1, const vector<float> point2)
{
    // Vérifier si les deux points ont la même dimension (2D, 3D, etc.)

    float distance = 0.0f;
    //pour chaque axe des points (x,y,z, etc.)
    for (int i = 0; i < point1.size(); ++i)
    {
        distance += pow(point1[i] - point2[i], 2); //on prend la distance entre chaque position des points (sur le même axe), on fait le carré de la distance et aditionne le tout.
    }

    //retourner la distance Euclidienne
    return sqrt(distance); //racine carré de la distance
}

/// <summary>
/// Méthode qui calcul la distance de Manhattan entre deux points
/// </summary>
/// <param name="point1">coordonnées du premier point</param>
/// <param name="point2">coordonnées du deuxième point</param>
/// <returns>La distance de Manhattan</returns>
float CalculerDistanceManhattan(const vector<float> point1, const vector<float> point2)
{
    float distance = 0.0f;
    //pour chaque axe des coordonnées des points
    for (int i = 0; i < point1.size(); ++i)
    {
        //fabs() set la valeur absolue du nombre (sa valeur sans signe (pas de négatif))
        distance += fabs(point1[i] - point2[i]); //on calcul la différence de distance.
    }

    return distance;
}
