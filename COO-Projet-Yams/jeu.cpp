// COO-Projet-Yams.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <list>
#include "joueur.h"

int main()
{
    std::cout << "--- LANCEMENT DU JEU DE YAM'S ---" << std::endl;
    
    //ENREGISTREMENT DES JOUEURS
    std::string nbJoueurs = "0"; //BUG WITH A 1 CHAR INPUT
    while (nbJoueurs.length() != std::to_string(atoi(nbJoueurs.c_str())).length() || stoi(nbJoueurs) <= 1) {
        std::cout << "Veuillez choisir le nombre de joueurs : ";
        std::getline(std::cin, nbJoueurs);

        if (nbJoueurs.length() != std::to_string(atoi(nbJoueurs.c_str())).length()) std::cout << "Valeur incorrecte. Seuls les nombres entiers >= " << (char)133 << " 2 sont admis .Veuillez recommencer." << std::endl;
        else if (stoi(nbJoueurs) < 2) std::cout << "Valeur incorrecte. La valeur est un nombre >= " << (char)133 << " 2. Veuillez recommencer." << std::endl;
    }

    std::list<joueur> listeJoueurs = {};
    for (int i = 1; i <= stoi(nbJoueurs); i++) {
        std::string nom;
        std::cout << "Nom du joueur " << i << " : ";
        std::getline(std::cin, nom);
        listeJoueurs.push_back(joueur(nom));
    }

    //LANCEMENT DU JEU
    for (int i = 1; i <= 10; i++) {
        std::cout << "\n--- MANCHE " << i << " ---" << std::endl;
        for (joueur& j : listeJoueurs) j.jouer();
    }

    //FIN DU JEU
    joueur* gagnant = nullptr;
    for (joueur j : listeJoueurs) {
        if (gagnant == nullptr) gagnant = &j;
        else if (gagnant->getPoints() < j.getPoints()) gagnant = &j;
    }

    std::cout << "\n--- FIN DE PARTIE ---" << std::endl << "Le grand gagnant est " << gagnant->getNom();
}
