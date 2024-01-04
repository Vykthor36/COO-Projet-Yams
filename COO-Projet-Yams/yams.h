#pragma once
#include "figure.h"

class yams : public figure
{
public:
	//Signatures des fonctions
	bool verifCondition(std::list<int> L) override;
	int getScore() override;
};

