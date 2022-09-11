#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <iostream>
#include "joueur.h"
#include "deck.h"
#include <vector>
#include <fstream>
#include "match.h"

class Jeu{
private :
    std::vector<Joueur> m_joueurs;
    Match m_match;
    Boutique m_boutique;

    ///Recuperent toutes les cartes des joueurs afin de supprimer les cartes qui sont en doubles de la boutique
    std::vector<Creature*> m_cartesCreaPrises;
    std::vector<Energie*> m_cartesEnerPrises;
    std::vector<Speciale*> m_cartesSpePrises;

public :
    Jeu();
    ~Jeu();

    std::vector<Joueur> getJoueurs();
    void setJoueurs(std::vector<Joueur> joueurs);

    Boutique getBoutique()const;
    void setBoutique(Boutique boutique);

    void setMatch(Match match);
    Match getMatch()const;

    void deroulement();


    //Regles, demander si nouveau joueur, demander si lancement match, quitter
    //Si lancement de match demander si joueur veut aller dans boutique
    int menu();
    void afficherRegles();

    void lancerMatch();
    void matchEnCours();
    void finDeMatch();
    void match();

    Joueur nouveauJoueur(int i);
    void actualiserJoueur(Joueur joueur);
    void ajouterNouvJoueur(Joueur newJoueur);



    void lancerBoutique();
};



#endif // JEU_H_INCLUDED
