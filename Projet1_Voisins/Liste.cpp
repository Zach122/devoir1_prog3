#include <vector>
#include "Liste.h"
#include "Noeud.h"
#include <iostream>  // Assure-toi que cet en-t�te est inclus


using namespace std;

Liste::Liste()
{
	m_premierNoeud = nullptr;
}

Liste::~Liste()
{	
	Noeud* courant = m_premierNoeud;
	while (courant != nullptr) {
		Noeud* temp = courant;
		courant = courant->suivant;
		delete temp;  // Lib�re chaque Noeud
	}
	m_premierNoeud = nullptr; // Bonne pratique
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
	//Reste � lib�rer la m�moire
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


// M�thode pour acc�der aux donn�es
const std::vector<std::vector<float>>& Liste::getDonnees() {
	static std::vector<std::vector<float>> donneeTotale;
	donneeTotale.clear();  // Assurer qu'on vide les donn�es � chaque appel

	Noeud* courant = m_premierNoeud;
	while (courant != nullptr) {
		donneeTotale.push_back(courant->donnee);  // Ajouter chaque donn�e de la liste
		courant = courant->suivant;
	}
	return donneeTotale;
}

/*Retourner la t�te de la liste
Noeud* getPremierPointeur() {
	Noeud* m_premierNoeud;
	return m_premierNoeud;
}*/ 