#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
#include <iostream>
#include "fonctions.h"

class Carte
{
protected:
    std::string m_nom;
    std::string m_description;
    int m_prix;
    int m_genre; //1 : Creature, 2 : Energie, 3 : Speciale
    int m_quantite;
    int m_identifiant;

public:
    Carte(std::string nom, std::string description, int prix, int genre, int , int identifiant);
    Carte(int indentifiant); //les informations seront recuperer dans la première partie du file "Joueur"
    Carte();
    virtual~Carte();

    std::string getNom()const;
    std::string getDescription()const;
    int getPrix()const;
    int getGenre()const;
    int getQuantite() const;
    int getIdentifiant() const;

    void setQuantite(int quantite);
    void setIdentifiant(int identifiant);

    virtual void afficher(int lig, int col);

};

bool operator==(Carte const& a, Carte const& b);

#endif // CARTE_H_INCLUDED
