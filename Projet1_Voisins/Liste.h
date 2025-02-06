#pragma once
#include <vector>
#include "Noeud.h"
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


