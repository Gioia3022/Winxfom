#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "carte.h"
#include "collection.h"
#include "deck.h"


class Joueur
{
public:
    Joueur();
    Joueur(std::string nom);
    Joueur(std::string nom, int cagnotte=100);
    ~Joueur();

    std::string getNom()const;
    void setNom(std::string nom);

    int getCagnotte()const;
    void setCagnotte(int cagnotte);

    Deck getDeck();
    void setDeck(std::vector <Carte*> deck);
    void setDeckC(Deck deck);

    bool getTurn()const;
    void setTurn(bool turn);

    int getWin()const;
    void setWin(int win);

    std::vector <Carte*> getMain()const;
    void setMain(std::vector <Carte*> main);

    int getLP()const;
    void setLP(int LP);

    Collection getCollection()const;
    void setCollection(Collection collection);

    Carte* getEnjeu()const;
    void setEnjeu(Carte* enjeu);

    bool getOut()const;
    void setOut(bool out);

    void recupCollection();
    bool chargerJoueur();
    void sauvegarde();
    Carte * createCarte(int identifiant);

    //a la fin du match on supprime la main et le deck du joueur
    void supprimerM_D();

private:
    std::string m_nom;
    Deck m_deck;
    int m_win; //0 si le joueur est inactif, 1 si le joueur est gagnant, -1 si le joueur est perdant
    int m_cagnotte;
    int m_LP;
    Collection m_collection;
    bool m_turn;
    std::vector <Carte*> m_main;
    Carte* m_enjeu;
    bool m_out; //Si le joueur ne peut plus jouer, il est out

};

#endif // JOUEUR_H_INCLUDED
