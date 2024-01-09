#pragma once

#include "figure.h"
#include <set>
#include <algorithm>
#include <iterator>

template <int n>
class suite : public figure
{
public:
	//Constructeurs
	suite() : figure() {}

	suite(const std::string& n, int s) : figure(n, s) {}

	suite(const suite<n>& s) : figure(s) {}

	//Fonctions
	bool verifCondition(std::vector<int> L) override
	{
		std::sort(L.begin(), L.end());
		L.erase(std::unique(L.begin(), L.end()), L.end());

		if (L.size() != n) return false;
		else {
			for (int i = 0; i < L.size() - 2; i++) if (L.at(i + 1) != L.at(i) + 1) return false;

			condition = L;
			return true;
		}
	}

	int getScore() const override
	{
		if (n == 4) return 30;
		else return 40;
	}
};

