#pragma once
#include <string>
#include <vector>
#include "figure.h"

class joueur
{
	//Attributs
	std::string nom;
	int pointsMin;
	int pointsMaj;
	std::vector<figure*> listeSimples;
	std::vector<figure*> listeFigures;

public:
	//Signatures des constructeurs
	joueur();
	joueur(const std::string& nom);
	joueur(const joueur& j);

	//Signature du destructeur
	~joueur();

	//Signatures des fonctions
	void jouer();
	std::string getNom();
	int getPoints();
};

