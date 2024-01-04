#pragma once
#include <list>

class figure
{
	//Attributs
	int score;
	std::list<int> condition;

public:
	//Signatures des constructeurs
	figure();

	//Signature du destructeur
	~figure();

	//Signatures des fonctions
	virtual bool verifCondition(std::list<int> L);
	virtual int getScore();
};