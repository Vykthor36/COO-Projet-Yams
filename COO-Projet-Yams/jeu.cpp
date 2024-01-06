// COO-Projet-Yams.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <list>
#include "joueur.h"

int main()
{
    std::cout << "--- LANCEMENT DU JEU DE YAM'S ---" << std::endl;
    
    std::string nbJoueurs = "0";
    while (nbJoueurs.length() != std::to_string(atoi(nbJoueurs.c_str())).length() || stoi(nbJoueurs) <= 1) {
        std::cout << "Veuillez choisir le nombre de joueurs : ";
        std::cin >> nbJoueurs;

        if (nbJoueurs.length() != std::to_string(atoi(nbJoueurs.c_str())).length()) std::cout << "Valeur incorrecte. Seuls les nombres entiers >= " << (char)133 << " 2 sont admis .Veuillez recommencer." << std::endl;
        else if (stoi(nbJoueurs) < 2) std::cout << "Valeur incorrecte. La valeur est un nombre >= " << (char)133 << " 2. Veuillez recommencer." << std::endl;
    }

    std::list<joueur> listeJoueurs = {};
    for (int i = 1; i <= stoi(nbJoueurs); i++) {
        std::string nom;
        std::cout << "Nom du joueur " << i << " : ";
        std::cin >> nom;
        listeJoueurs.push_back(joueur(nom));
    }
}
