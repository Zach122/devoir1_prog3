#include <vector>
#include "Liste.h"
#include "Noeud.h"
#include <iostream>

using namespace std;

/// <summary>
/// Constructeur pour notre Liste.
/// </summary>
Liste::Liste()
{
	m_premierNoeud = nullptr; //Le premier Noeud (la structure cr��e).
}

/// <summary>
/// D�structeur de la liste parcourant et supprimant tout les noeuds � l'aide du pointeur.
/// </summary>
Liste::~Liste()
{	
	Noeud* courant = m_premierNoeud;

	while (courant != nullptr) { // Tant que le noeud courrant a des donn�es, je vais supprimer le noeud courant et je vais chercher le prochain.
		Noeud* temp = courant;
		courant = courant->suivant;
		delete temp;
	}

	m_premierNoeud = nullptr; // Pour r�initialiser notre liste.
}

/// <summary>
/// M�thode nous permettant d'ajouter un vecteur de donn�es (float) (notre noeud) � notre liste.
/// </summary>
/// <param name="donnee">Un vecteur de float repr�sentant un noeud.</param>
void Liste::ajouter(vector<float> donnee) {

	Noeud* nouveau = new Noeud{ donnee, nullptr }; // Je vais chercher pointeur du noeud que je cr�e.

	if (m_premierNoeud == nullptr) { // Si je suis au premier noeud, je lui assigne mon nouveau noeud.
		m_premierNoeud = nouveau;
	}
	else { // Sinon, je vais chercher le pointeur de mon premier noeud pour pouvoir aller chercher tout les pointeurs suivants jusqu'� la derni�re donn�e (nullptr)
		Noeud* iterateur = m_premierNoeud;

		while (iterateur->suivant != nullptr) {
			iterateur = iterateur->suivant;
		}

		iterateur->suivant = nouveau;
	}

	delete nouveau;
}

/// <summary>
/// M�thode permettant de compter le nombre de donn�es dans notre liste (Pour les testes.).
/// </summary>
/// <returns>Un integer repr�sentan la taille de la liste.</returns>
int Liste::tailleListe() {
	int taille = 0;
	Noeud* courant = m_premierNoeud;

	while (courant != nullptr) { // Je parcours tout la liste et j'additionne "1" � mon nombre de donn�es.
		taille++;
		courant = courant->suivant;
	}
	return taille;
}


/// <summary>
/// M�thode me permettant de me retourner la liste de noeuds sous forme de vector de vector de float.
/// </summary>
/// <returns>Un vecteur de vecteur de float repr�sentant nos donn�es.</returns>
const vector<vector<float>>& Liste::getDonnees() {

	static vector<vector<float>> donneeTotale;

	donneeTotale.clear();

	Noeud* courant = m_premierNoeud;

	while (courant != nullptr) {
		donneeTotale.push_back(courant->donnee);
		courant = courant->suivant;
	}

	return donneeTotale;
}

/*Retourner la t�te de la liste
Noeud* getPremierPointeur() {
	Noeud* m_premierNoeud;
	return m_premierNoeud;
}*/ 