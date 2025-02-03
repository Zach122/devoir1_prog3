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
	//Noeud* getPremierPointeur();
};


