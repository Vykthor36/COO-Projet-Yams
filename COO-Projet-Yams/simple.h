#pragma once
#include "figure.h"
#include <iostream>

template <int n>
class simple : public figure
{
public:
	//Constructeurs
	simple() : figure() {}

	simple(const std::string& n, int s) : figure(n, s) {}

	simple(const simple<n>& s) : figure(s) {}

	//Fonctions
	bool verifCondition(std::vector<int> L) override
	{
		condition = {};
		bool test = false;
		for (int i = 0; i < L.size(); i++) if (L.at(i) == n) {
			test = true;
			condition.push_back(L.at(i));
		}

		return test;
	}

	int getScore() const override
	{
		return n * condition.size();
	}
};

