
#include "attaque.h"
#include "carte.h"
#include <iostream>

///Constructeurs

Attaque::Attaque()
{}

Attaque::Attaque(std::string nom, int coupPE, std::string typePE, int HP)
:m_nom(nom), m_coupPE(coupPE), m_typePE(typePE), m_HP(HP)
{}

///Destructeur
Attaque::~Attaque()
{

}


///Accesseurs

int Attaque::getHp()const
{
    return m_HP;
}
int Attaque::getCoupPE()const
{
    return m_coupPE;
}
std::string Attaque::getType()const
{
    return m_typePE;
}
std::string Attaque::getNom()const
{
    return m_nom;
}
void Attaque::setHp(int HP)
{
    m_HP=HP;
}
void Attaque::setCoupPE(int coupPE)
{
    m_coupPE=coupPE;
}
void Attaque::setType(int type)
{
    m_typePE=type;
}

/*
affiche les caracteristiques de l'attaque
parametres : ligne et colonne pour l'affichage
pas de retour
*/
void Attaque::afficherAttaque(int lig, int col)
{
    gotoligcol(lig,col);
    std::cout<<"*"<<getNom()<<" "<< getHp() << "HP";
    gotoligcol(lig+1,col+1);
    std::cout<<"necessite "<< getCoupPE()<< " point de type " << getType();
}
