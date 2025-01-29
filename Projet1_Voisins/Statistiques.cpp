#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "Statistiques.h"

using namespace std;

/// <summary>
/// M�thode qui calcul la moyenne des valeurs re�ues
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
/// M�thode qui calcul la m�diane des valeurs re�ues
/// </summary>
/// <param name="tableau">Tableau de nombre</param>
/// <returns>La m�diane des nombres</returns>
float CalculerMediane(vector<float> tableau)
{

    //Mettre les valeurs en ordre croissant
    for (int i = 0; i < tableau.size() - 1; ++i) //prend une valeur � comparer
    {
        for (int j = i + 1; j < tableau.size(); ++j) //parcourt les valeurs apr�s celle � comparer
        {
            //si la premi�re valeur est plus grande que celle avec laquelle elle est compar�e
            if (tableau[i] > tableau[j])
            {
                //on les �changes
                swap(tableau[i], tableau[j]); 
            }
        }
    }

    int taille = tableau.size();

    //si la taille est impaire, la m�diane est l'�l�ment en plein milieu
    if (taille % 2 != 0)
    {
        return tableau[taille / 2];
    }
    //sinon, c'est paire, donc la m�diane est la moyenne des deux �l�ments du centre
    else
    {
        int milieu = taille / 2;
        return (tableau[milieu - 1] + tableau[milieu]) / 2.0f;
    }
}
/// <summary>
/// M�thode qui calcul l'�crat type des valeurs re�ues
/// </summary>
/// <param name="tableau">Le vector de valeurs</param>
/// <returns>l'�crat type calcul�</returns>
float CalculerEcartType(vector<float> tableau)
{
    float moyenne = CalculerMoyenne(tableau);

    //Calculer la somme des �carts de chaque valeur par rapport � la moyenne, au carr�.
    float sommeDesEcartsAuCarre = 0.0f;
    for (float valeur : tableau)
    {
        sommeDesEcartsAuCarre += pow(valeur - moyenne, 2); //pow calcul l'exposant sp�cifi� (ici, 2)
    }

    //On divise la somme par le nombre total d'�l�ments
    float divisionSommeEcartNombre = sommeDesEcartsAuCarre / tableau.size();

    //On retourne la racine
    return sqrt(divisionSommeEcartNombre);
}
/// <summary>
/// M�thode qui calcule la distance Euclidienne entre dux points.
/// </summary>
/// <param name="">coordonn�es du premier point</param>
/// <param name="">coordonn�es du deuxieme point</param>
/// <returns>La distance Euclidienne</returns>
float CalculerDistanceEuclidienne(const vector<float> point1, const vector<float> point2)
{
    // V�rifier si les deux points ont la m�me dimension (2D, 3D, etc.)

    float distance = 0.0f;
    //pour chaque axe des points (x,y,z, etc.)
    for (int i = 0; i < point1.size(); ++i)
    {
        distance += pow(point1[i] - point2[i], 2); //on prend la distance entre chaque position des points (sur le m�me axe), on fait le carr� de la distance et aditionne le tout.
    }

    //retourner la distance Euclidienne
    return sqrt(distance); //racine carr� de la distance
}

/// <summary>
/// M�thode qui calcul la distance de Manhattan entre deux points
/// </summary>
/// <param name="point1">coordonn�es du premier point</param>
/// <param name="point2">coordonn�es du deuxi�me point</param>
/// <returns>La distance de Manhattan</returns>
float CalculerDistanceManhattan(const vector<float> point1, const vector<float> point2)
{
    float distance = 0.0f;
    //pour chaque axe des coordonn�es des points
    for (int i = 0; i < point1.size(); ++i)
    {
        //fabs() set la valeur absolue du nombre (sa valeur sans signe (pas de n�gatif))
        distance += fabs(point1[i] - point2[i]); //on calcul la diff�rence de distance.
    }

    return distance;
}
