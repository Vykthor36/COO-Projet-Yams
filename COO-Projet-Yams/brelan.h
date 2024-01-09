#pragma once

#include <iostream>
#include "figure.h"

template <int n>
class brelan : public figure
{
public:
	//Signature des constructeurs
	brelan() : figure() {}

	brelan(const std::string& n, int s) : figure(n, s) {}

	brelan(const brelan<n>& b) : figure(b) {}

	//Signatures des fonctions
	bool verifCondition(std::vector<int> L) override
	{
		for (int i = 1; i <= 6; i++) {
			int nb = 0;
			for (int j : L) if (j == i) nb++;

			if (nb == n) {
				condition = std::vector<int>(n, i);
				return true;
			}
		}

		return false;
	}

	int getScore() const override
	{
		if (n == 5) return 30;
		else {
			int N = 0;
			for (int i = 1; i <= 6; i++) {
				int nb = 0;
				for (int j : condition) if (j == i) nb++;
				if (nb == n) if (i > N) N = i;
			}

			return n * N;
		}
	}
};