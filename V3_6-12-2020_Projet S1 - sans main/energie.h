#ifndef ENERGIE_H_INCLUDED
#define ENERGIE_H_INCLUDED

#include <string>
#include "carte.h"


class Energie : public Carte
{
    private:
        int m_gain;//si on veut que les cartes energies rapporte plus que un point énergie sinon pas utile
        int m_couleur;//vert TERRE, jaune LUMIERE, rouge FEU, blanc TECHNO?
        std::string m_domaine;
        //pourquoi pas rajouter un booleen tant qu'elle est utilisable et quand elle ne l'est plus
        //=> on doit piocher une nouvelle carte ou on decremente le nombre de cartes posées du domaine
    public:
        Energie();
        Energie(std::string nom,std::string description,int prix,int gain, int couleur,std::string domaine,int quantite, int identifiant);
        virtual~Energie();

        std::string getDomaine()const {return m_domaine;}
        int getGain()const {return m_gain;}
        int getCouleur()const {return m_couleur;}

        void setDomaine(std::string domaine){m_domaine=domaine;}
        void setGain(int gain){m_gain=gain;}
        void setCouleur(int couleur){m_couleur=couleur;}

        bool utiliser();
        virtual void afficher(int lig, int col);
};

#endif // ENERGIE_H_INCLUDED
