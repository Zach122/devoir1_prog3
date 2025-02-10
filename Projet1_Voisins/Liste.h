#pragma once
#include <vector>
#include "Noeud.h"

/// <summary>
/// Classe représentant la liste de noeud.
/// </summary>
class Liste
{
private:
	Noeud* m_premierNoeud;
public:
	Liste();
	~Liste();
	void ajouter(vector<float>);
	int tailleListe();
	const std::vector<std::vector<float>>& getDonnees();
	//Noeud* getPremierPointeur();
};


