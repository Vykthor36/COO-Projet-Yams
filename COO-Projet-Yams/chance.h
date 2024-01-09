#pragma once
#include "figure.h"

class chance : public figure
{
public:
	//Constructeurs
	chance() : figure("Chance", 30) {}

	chance(const chance& c) : figure(c) {}

	//Fonctions
	bool verifCondition(std::vector<int> L) override
	{
		condition = L;
		return true;
	}

	int getScore() const override
	{
		int N = 0;
		for (int nb : condition) N += nb;
		return N;
	}
};

