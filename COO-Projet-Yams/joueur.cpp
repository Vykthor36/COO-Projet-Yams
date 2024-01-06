#include "joueur.h"

//Constructeurs
joueur::joueur()
{
	points = 0;
	nom = "";
	listeFigures = {};
}

joueur::joueur(const std::string& nom)
{
	points = 0;
	joueur::nom = nom;
	listeFigures = {};
}

//Destructeur
joueur::~joueur()
{

}

//Fonctions
bool joueur::jouer()
{
	//TODO
	return false;
}
