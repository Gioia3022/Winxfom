#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED
#include <vector>
#include "carte.h"
#include "attaque.h"
#include <iostream>
#include <vector>
#include <string>


class Creature: public Carte
{
private:
    int m_LP;
    std::string m_energie;
    std::vector <Attaque*> m_att;

public:
    Creature();
    Creature(std::string nom, std::string description,int prix, int LP, std::string energie,int quantite,int identifiant);
    virtual~Creature();

    int getLP()const;
    void setLP(int LP);

    std::string getEnergie()const;
    void setEnergie(std::string energie);

    std::vector <Attaque*> getAttaque();

    virtual void afficher(int lig, int col);
    void choix();

    //void setAttaque(std::vector <Attaque*> attaque);
    //attaque.push_back(new Attaque(nom,description,coupPE,typePE,HP,possible));
    void GestionLP(int HP);

    // std::vector<Attaque> //finDeVie(std::vector<Carte> deck, std::vector<Carte> cimetiere, int alerte);
    void ajouter(std::string nom, int coup, std::string type, int HP);
    //std::vector<Carte> finDeVie(std::vector<Carte> deck, std::vector<Carte> cimetiere, int alerte);
};

#endif // CREATURE_H_INCLUDED
