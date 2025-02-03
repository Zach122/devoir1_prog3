#include <vector>
#include "Liste.h"
#include "Noeud.h"

using namespace std;

Liste::Liste()
{
	m_premierNoeud = nullptr;
}

void Liste::ajouter(vector<float> donnee) {
	Noeud* nouveau = new Noeud{ donnee, nullptr };

	if (m_premierNoeud == nullptr) {
		m_premierNoeud = nouveau;
	}
	else {
		Noeud* iterateur = m_premierNoeud;
		while (iterateur->suivant != nullptr) {
			iterateur = iterateur->suivant;
		}
		iterateur->suivant = nouveau;
	}
	//Reste à libérer la mémoire
}

int Liste::tailleListe() {
	int taille = 0;
	Noeud* courant = m_premierNoeud;

	while (courant != nullptr) {
		taille++;
		courant = courant->suivant;
	}
	return taille;
}

/*Retourner la tête de la liste
Noeud* getPremierPointeur() {
	Noeud* m_premierNoeud;
	return m_premierNoeud;
}*/ 