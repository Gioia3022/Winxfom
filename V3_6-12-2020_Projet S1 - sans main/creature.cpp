#include "creature.h"

///Constructeur
Creature::Creature()
{}
Creature::Creature(std::string nom, std::string description,int prix, int LP, std::string energie,int quantite,int identifiant)
:Carte(nom,description, prix, 1, quantite, identifiant),m_LP(LP),m_energie(energie)
{}

///Destructeur
Creature::~Creature()
{

}

///Accesseurs

int Creature::getLP()const
{
    return m_LP;
}

void Creature::setLP(int LP)
{
    m_LP=LP;
}

std::string Creature::getEnergie()const
{
    return m_energie;
}


void Creature::setEnergie(std::string energie)
{
    m_energie=energie;
}


std::vector <Attaque*> Creature::getAttaque()
{
    return m_att;
}

/*
Assigne une nouvelle attaque a la creature
parametres : nom, coup, type et hp de l'attaque
pas de retour
*/
void Creature :: ajouter(std::string nom,int coup, std::string type, int HP)
{
        Attaque* att=new Attaque(nom,coup,type,HP);
        m_att.push_back(att);
}


/*
Affichage des caraterisques de l'attaque
parametres : ligne et colonne ou afficher
pas de retour
*/
void Creature::afficher(int lig, int col)
{
    gotoligcol(lig,col);
    std::cout<<"*********************************************";
    gotoligcol(lig+1,col);
    std::cout<<"\t\t"<<getNom();
    gotoligcol(lig+2,col);
    std::cout<<"*********************************************";
    gotoligcol(lig+3,col);
    std::cout<<"Id : " << getIdentifiant();///modif
    gotoligcol(lig+4,col);
    std::cout<<getDescription();
    gotoligcol(lig+5,col);
    std::cout<<"Life points : "<<getLP();
    gotoligcol(lig+6,col);
    std::cout<<"Attaques : ";
    lig+=7;
    for(auto elem : getAttaque())
    {
       elem->afficherAttaque(lig,col);
       lig+=2;
    }


}
/*
void Creature::choix()
{
    //choisir son attaque avec un cin
    //choix depend de i
    return m_att[i].getHp();
}


void Creature::GestionLP(int HP)
{
    setLP(m_LP-HP);
}
*/





