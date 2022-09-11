#ifndef BOUTIQUE_H_INCLUDED
#define BOUTIQUE_H_INCLUDED

#include "carte.h"
#include "energie.h"
#include "speciales.h"
#include "creature.h"
//#include "joueur.h"
#include <fstream>
#include <iostream>
#include <vector>

class Boutique
{
private:
    std::vector <Creature*> m_creature;
    std::vector <Energie*> m_cEnergie;
    std::vector <Speciale*> m_speciale;

    std::vector <Creature*> m_creatureU;
    std::vector <Energie*> m_cEnergieU;
    std::vector <Speciale*> m_specialeU;

public :

    Boutique();
    ~Boutique();

    std::vector <Creature*> getCreature() const;
    std::vector <Energie*> getcEnergie() const;
    std::vector <Speciale*> getSpeciale() const;

    std::vector <Creature*> getCreatureU() const;
    std::vector <Energie*> getcEnergieU() const;
    std::vector <Speciale*> getSpecialeU()const;

    void setCreature(std::vector<Creature*> creature);
    void setcEnergie(std::vector<Energie*> cEnergie);
    void setSpeciale(std::vector<Speciale*> speciale);

    void setCreatureU(std::vector<Creature*> creature);
    void setcEnergieU(std::vector<Energie*> cEnergie);
    void setSpecialeU(std::vector<Speciale*> speciale);



    void remplir(); //on cree la boutique
    void supprimerCarteCrea(Creature* achat); //Quand on vend carte
    void supprimerCarteEner(Energie* achat);
    void supprimerCarteSpe(Speciale* achat);

    void Identifiant();

    void afficherCrea();
    void afficherEner();
    void afficherSpe();

    Carte * createCarte(int identifiant);
    bool present(Carte* cartes);
    bool chargerBoutique();
    void sauvegarde();

    Creature* choisirCrea();//acheter une carte
    Energie* choisirEner();//acheter une carte
    Speciale* choisirSpe();//acheter une carte
    ///Peut etre mettre un pointeur pour etre sur de bien retourner la bonne carte

};


#endif // BOUTIQUE_H_INCLUDED
