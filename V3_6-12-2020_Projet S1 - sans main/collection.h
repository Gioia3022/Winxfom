#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED
#include <iostream>
#include <vector>
#include "carte.h"
#include "boutique.h"

class Collection
{
private:

    std::vector <Creature*> m_creatureCo;
    std::vector <Energie*> m_cEnergieCo;
    std::vector <Speciale*> m_specialeCo;

    std::vector <Carte*> m_collection;

public :
    Collection();
    ~Collection();

    std::vector <Creature*> getCreatureColl() const;
    std::vector <Energie*> getcEnergieColl() const;
    std::vector <Speciale*> getSpecialeColl() const;

    std::vector <Carte*> getCollection() const;

    void setCollection(std::vector<Carte*> collection);
    void setCreatureColl(std::vector<Creature*> creature);
    void setcEnergieColl(std::vector<Energie*> cEnergie);
    void setSpecialeColl(std::vector<Speciale*> speciale);

    Creature* choisirCreaCo();
    Energie* choisirEnerCo();
    Speciale* choisirSpeCo();

    void afficherCrea();
    void afficherEner();
    void afficherSpe(); //lors du choix du deck

    //void selectionner(Boutique boutique); //Lorsque nouveau joueur

    //Lorsque achat d'une carte
    //Lorsque gain de l'enjeu
    void ajouterCreature(Creature *nouvCarte);
    void ajouterEnergie(Energie* nouvCarte);
    void ajouterSpeciale(Speciale* nouvCarte); //peut etre utiliser cette methode dans la classe achat de la boutique

    //Lorsque perte de l'enjeu
    void supprimerCreature(Creature* carteAsupp);
    void supprimerEnergie(Energie* carteAsupp);
    void supprimerSpeciale(Speciale* carteAsupp);

};


#endif // COLLECTION_H_INCLUDED
