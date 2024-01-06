#include "figure.h"

//Constructeurs
figure::figure()
{
	score = 0;
	condition = {};
}

//Destructeur
figure::~figure()
{

}

//Fonctions
bool figure::verifCondition(std::list<int> L)
{
	return false;
}

int figure::getScore()
{
	return score;
}
