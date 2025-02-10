#pragma once
#include <vector>
using namespace std;

/// <summary>
/// Structure du noeud pour notre liste.
/// </summary>
struct Noeud {
    vector<float> donnee; // L'enregistrement
    Noeud* suivant;       // Pointeur vers le nœud suivant
};