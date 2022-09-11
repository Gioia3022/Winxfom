#include "energie.h"

///Constructeurs

Energie::Energie()
{

}


Energie::Energie(std::string nom,std::string description,int prix,int gain, int couleur ,std::string domaine,int quantite, int identifiant)
        :Carte(nom,description,prix,2,quantite,identifiant),m_gain(gain), m_couleur(couleur),m_domaine(domaine)
{

}

///Destructeur
Energie::~Energie()
{

}

/*
affiche les cartes energies
parametres : ligne et colonne ou afficher
pas de retour
*/
void Energie::afficher(int lig, int col)
{
    gotoligcol(lig,col);
    Color(m_couleur,0);
    std::cout<<"*********************************";
    gotoligcol(lig+1,col+7);
    std::cout<<getNom();
    gotoligcol(lig+2,col);
    std::cout<<"*********************************";
    Color(7,0);
    gotoligcol(lig+3,col);
    std::cout<<"Id : " << getIdentifiant();///modif
    gotoligcol(lig+4,col);
    std::cout<<"Domaine : "<<getDomaine();
    gotoligcol(lig+5,col);
    std::cout<<getDescription();
    gotoligcol(lig+6,col);
    std::cout<<"Gain : "<<getGain();


    gotoligcol(50,40);
    std::cout << "On appelle affichage energie ms pq";

}

/*

*/
bool Energie::utiliser()
{
    if(getGain()>0)//test si il reste des points energies
    {
        m_gain=0;
        return true;
    }

    else
    {
        return false;
    }
}
/*
void Energie::utiliser()
{
    if(getGain()>0)//test si il reste des points energies
    {
        setGain(getGain()-1);//decrementation des points energies
        if(getGain()>0)
        {
            std::cout<<"Votre carte "<<getNom()<<" n a plus que "<<getGain()<<" point(s) energie! "<<std::endl;
        }
        else
        {
            std::cout<<"Carte morte"<<std::endl;
            //utilisation du booleen
        }
    }

}
*/
