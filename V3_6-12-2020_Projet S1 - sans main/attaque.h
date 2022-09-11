#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED
#include <iostream>
//#include "creature.h"
#include "carte.h"

class Attaque
{
private:
    std::string m_nom;
    int m_coupPE;
    std::string m_typePE;
    int m_HP;

public:
    Attaque();
    Attaque(std::string nom, int coupPE, std::string typePE, int HP);
    ~Attaque();

    int getHp()const;
    int getCoupPE()const;
    std::string getType()const;
    std::string getNom()const;

    void setHp(int HP);
    void setCoupPE(int coupPE);
    void setType(int type);

    void afficherAttaque(int lig, int col);
};

#endif // ATTAQUE_H_INCLUDED








