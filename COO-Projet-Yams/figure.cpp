#include "figure.h"

//Constructeurs
figure::figure()
{
	scoreMax = 0;
	condition = {};
}

figure::figure(const std::string& n, int s)
{
	nom = n;
	scoreMax = s;
	condition = {};
}

figure::figure(const figure& f)
{
	nom = f.nom;
	scoreMax = f.scoreMax;
	condition = f.condition;
}

//Destructeur
figure::~figure()
{

}

//Fonctions
bool figure::verifCondition(std::vector<int> L)
{
	return true;
}

std::string figure::getNom() const
{
	return nom;
}

int figure::getScore() const
{
	return scoreMax;
}
