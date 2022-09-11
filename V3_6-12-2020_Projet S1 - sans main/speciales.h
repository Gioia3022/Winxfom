#ifndef SPECIALES_H_INCLUDED
#define SPECIALES_H_INCLUDED
#include "carte.h"
#include "creature.h"
#include "attaque.h"
#include <iostream>
#include <vector>
#include <time.h>

class Speciale : public Carte
{
private :
    int m_cycleVie; // si = 0 => usage unique
    bool m_pioche; //si true, carte retourne dans la pioche/si false, carte va dans cimetiere
    int m_type_spe;

public :
    Speciale(int cycle, std::string nom, std::string description, bool pioche, int prix, int quantite,int identifiant, int type_spe);
    Speciale();
    virtual~Speciale();

    int getCycle()const;
    bool getBool()const;

    int getTypeSpe()const;

    void setCycle(int cycle);
    void setBool(bool pioche);

    virtual void afficher(int lig, int col);

    Creature* pouvoir1(Creature* crea_A, Attaque attaque);
    Carte* pouvoir2(std::vector <Carte*> deck);
    Carte* pouvoir3(std::vector<Carte*> cimetiere);
    Creature* pouvoir4(Creature* creature);

    Carte* pouvoir6(std::vector<Carte*> deck);


    int cycleVie();
    std::vector<Carte*> finDeVie(std::vector<Carte*> deck, std::vector<Carte*> cimetiere, int alerte);


};
#endif // SPECIALES_H_INCLUDED
