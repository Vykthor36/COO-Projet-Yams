#include "joueur.h"
#include "lancer.h"
#include "simple.h"
#include "brelan.h"
#include "suite.h"
#include "chance.h"
#include <iostream>

//Constructeurs
joueur::joueur()
{
	pointsMin = 0;
	pointsMaj = 0;
	nom = "";
	listeSimples = {};
	listeFigures = {};
}

joueur::joueur(const std::string& nom)
{
	pointsMin = 0;
	pointsMaj = 0;
	joueur::nom = nom;

	listeSimples = {new simple<1>("1", 5), new simple<2>("2", 10), new simple<3>("3", 15), new simple<4>("4", 20), 
					new simple<5>("5", 25), new simple<6>("6", 30)};
	listeFigures = {new brelan<3>("Brelan", 18), new brelan<4>("Carre", 24), new brelan<5>("Yam's", 30), 
					new suite<4>("Petite suite", 30), new suite<5>("Grande suite", 40), new chance()};
}

joueur::joueur(const joueur& j)
{
	pointsMin = j.pointsMin;
	pointsMaj = j.pointsMaj;
	nom = j.nom;
	listeSimples = j.listeSimples; //???
	listeFigures = j.listeFigures; //???
}

//Destructeur
joueur::~joueur()
{

}

//Fonctions
void joueur::jouer()
{
	std::cout << "C'est au tour de " << nom << " !" << std::endl;

	int nbLancers = 0;
	bool testLancer = true;
	while (testLancer && nbLancers < 3) {
		std::vector<figure*> resSimples = {};
		std::vector<figure*> resFigures = {};
		std::string coup;

		std::vector<int> resLancer = lancer::lancerDés();
		nbLancers++;
		std::cout << "R" << char(130) << "sultat du lancer " << nbLancers << " : ";
		for (int i = 0; i < 5; i++) {
			if (unsigned(i) < resLancer.size() - 1) std::cout << resLancer.at(i) << " - ";
			else std::cout << resLancer.at(i) << std::endl;
		}

		std::cout << "Coups disponibles : ";
		for (int i = 0; i < listeSimples.size(); i++) {
			figure* f = listeSimples.at(i);
			if (f->verifCondition(resLancer)) {
				std::cout << f->getNom();
				if (listeFigures.size() > 0) std::cout << " - ";
				resSimples.push_back(f);
			}
			else if (listeFigures.size() > 0) std::cout << f->getNom() << " - ";
			else std::cout << f->getNom();
		}

		for (int i = 0; i < listeFigures.size(); i++) {
			figure* f = listeFigures.at(i);
			if (f->verifCondition(resLancer)) {
				std::string nomFigure = f->getNom();
				for (int x = 0; x < nomFigure.size(); x++) putchar(toupper(nomFigure[x]));
				if (i < listeFigures.size() - 1) std::cout << " - ";
				resFigures.push_back(f);
			}
			else if (i < listeFigures.size() - 1) std::cout << f->getNom() << " - ";
			else std::cout << f->getNom();
		}

		if (nbLancers < 3) std::cout << " - RELANCER" << std::endl;
		else std::cout << std::endl;
		bool testCoup = false;
		while (!testCoup) {
			std::cout << "Chosissez votre coup pour cette manche : ";
			std::getline(std::cin, coup);
			std::transform(coup.begin(), coup.end(), coup.begin(), ::tolower);
			if (coup == "relancer") testCoup = true;

			for (int i = 0; unsigned(i) < listeSimples.size(); i++) {
				std::string nomSimple = listeSimples.at(i)->getNom();
				std::transform(nomSimple.begin(), nomSimple.end(), nomSimple.begin(), ::tolower);
				if (nomSimple == coup) {
					testLancer = false;
					testCoup = true;
					for (figure* f : resSimples) {
						std::string resNom = f->getNom();
						std::transform(resNom.begin(), resNom.end(), resNom.begin(), ::tolower);
						if (resNom == coup) pointsMin += f->getScore();
					}

					listeSimples.at(i) = nullptr;
					listeSimples.erase(listeSimples.begin() + i);

					if (listeSimples.empty() && pointsMin >= 63) {
						pointsMin += 35;
						//std::cout << "Obtention des points bonus !" << std::endl;
					}
				}
			}

			for (int i = 0; unsigned(i) < listeFigures.size(); i++) {
				std::string nomFigure = listeFigures.at(i)->getNom();
				std::transform(nomFigure.begin(), nomFigure.end(), nomFigure.begin(), ::tolower);
				//std::cout << nomFigure << "/" << coup << std::endl;
				if (nomFigure == coup) {
					testLancer = false;
					testCoup = true;
					for (figure* f : resFigures) {
						std::string resNom = f->getNom();
						std::transform(resNom.begin(), resNom.end(), resNom.begin(), ::tolower);
						if (resNom == coup) pointsMaj += f->getScore();
					}

					listeFigures.at(i) = nullptr;
					listeFigures.erase(listeFigures.begin() + i);
				}
			}

			if (!testCoup) std::cout << "Coup inconnu ! Veuillez recommencer." << std::endl;
		}
	}

	std::cout << "Nouveau score de " << nom << " : " << getPoints() << " !" << std::endl << std::endl;
}

std::string joueur::getNom()
{
	return nom;
}

int joueur::getPoints()
{
	return pointsMin + pointsMaj;
}
