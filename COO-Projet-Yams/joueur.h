#pragma once
#include <string>
#include <list>
#include "figure.h"

class joueur
{
	//Attributs
	std::string nom;
	int points;
	std::list<figure> listeFigures;

public:
	//Signatures des constructeurs
	joueur();
	joueur(const std::string& nom);

	//Signature du destructeur
	~joueur();

	//Signatures des fonctions
	bool jouer();
};

