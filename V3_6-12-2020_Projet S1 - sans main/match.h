#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED
#include <vector>
#include "joueur.h"
#include "deck.h"
#include "Cimetiere.h"

class Match
{
    /**
    nomi giocatori
    deck
    inizia partita
    - una serie di chiamate-> cout opzioni x utente
    memorizo HP-> dipenono dalla scelta dell'attacco
    chiamo f° modifica LP 2a creatura-> if(LP<=0)->cimitero

    */
public:
    Match();
    //Jeu();
    ~Match();
    int round();
    void start();
    void round_single_player(int j);
    void attaque(int j, Creature* crea);
    int creatureP(int j);

    void ajouterJoueurs(Joueur joueur1, Joueur joueur2);
    void supprimerJoueurs();
    std::vector <Creature*> getCreature(int j);


    std::vector<Joueur> getJoueurs();
    void setJoueurs(std::vector<Joueur> joueurs);


    Cimetiere getCimetiere()const;
    void afficherVide(int lig, int col);
    void afficherVideEner(int lig, int col);
    void afficherVideLP(int lig, int col);
    void afficherVideTable(int lig, int col);
    void afficherConsole();

private:
    std::vector <Joueur> m_jo; //contient les joueurs qui vont s'affronter
    std::vector <std::vector <Energie*>> m_energie;
    std::vector <std::vector <Creature*>> m_creature;
    std::vector <std::vector <Speciale*>> m_speciale;
    Cimetiere m_cimitiere;
};

#endif // MATCH_H_INCLUDED
