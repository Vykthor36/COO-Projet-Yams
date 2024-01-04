#pragma once
#include "figure.h"

template <int n>
class brelan : public figure
{
public:
	//Signatures des fonctions
	bool verifCondition(std::list<int> L) override;
	int getScore() override;
};

