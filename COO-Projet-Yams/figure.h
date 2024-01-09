#pragma once
#include <string>
#include <vector>

class figure
{
	//Attributs
	std::string nom;
	int scoreMax;

protected:
	std::vector<int> condition;

public:
	//Signatures des constructeurs
	figure();
	figure(const std::string& n, int s);
	figure(const figure& f);

	//Signature du destructeur
	~figure();

	//Signatures des fonctions
	virtual bool verifCondition(std::vector<int> L);
	std::string getNom() const;
	virtual int getScore() const;
};