#include <iostream>
#include <string>
#include <vector>

#include "Statistiques.h"
#include "RessourceLoader.h"

using namespace std;

int main()
{
    //Point 1 Statistiques Test
    vector<float> valeurs = { 5.0f, 2.0f, 10.0f, 7.0f, 3.0f };

    float moyenne = CalculerMoyenne(valeurs);
    float mediane = CalculerMediane(valeurs);
    float ecartType = CalculerEcartType(valeurs);
    
    cout << "Le resultat est : " << mediane;

    //Point 2 Statistiques Test

    vector<float> point1 = { 1.0f, 2.0f, 9.0f, 3.6f };
    vector<float> point2 = { 4.0f, 6.0f, 6.9f, 6.9f };

    float distanceEuclidienne = CalculerDistanceEuclidienne(point1, point2);
    float distanceManhattan = CalculerDistanceManhattan(point1, point2);
    cout << "\nDistance : " << distanceManhattan;


}
