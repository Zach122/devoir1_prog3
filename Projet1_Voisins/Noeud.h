#pragma once
#include <vector>
using namespace std;
struct Noeud {
    vector<float> donnee; // L'enregistrement
    Noeud* suivant;                  // Pointeur vers le nœud suivant
};