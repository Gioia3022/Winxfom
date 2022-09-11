#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED
#include <vector>
#include "carte.h"
#include "creature.h"
#include "energie.h"
#include "speciales.h"


class Deck
{
private:
    int m_taille = 2;
    std::vector <Carte*> m_cartesD; //Vecteur qui contient les cartes qui composent le deck
    //std::vector <Carte*> m_cartesDU; //Vecteur qui contient liste des cartes sans doublons, pratique pour affichage
public:

    Deck();
    ~Deck();

    int getTaille() const;
    std::vector <Carte*> getCartesD() const;

    void setCartesD(std::vector<Carte*> cartesD);

    void remplirDeckCrea(std::vector <Creature*> creaturecoll);
    void remplirDeckEner(std::vector <Energie*> energiecoll);
    void remplirDeckSpec(std::vector <Speciale*> specialecoll);

    void supprimer();
    void ajouter(Carte* nouvCarte);

    void afficherDeck();
};

#endif // DECK_H_INCLUDED
