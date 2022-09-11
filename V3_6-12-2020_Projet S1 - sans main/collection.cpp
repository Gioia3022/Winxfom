#include "collection.h"

//Constructeur
Collection ::Collection(){}

//Destructeur
Collection::~Collection()
{

}

///Accesseurs

std::vector<Carte*> Collection::getCollection()const
{
    return m_collection;
}

void Collection::setCollection(std::vector<Carte*> collection)
{
    m_collection=collection;
}

std::vector<Creature*> Collection::getCreatureColl()const{
    return m_creatureCo;
}
std::vector<Energie*> Collection::getcEnergieColl()const{
    return m_cEnergieCo;
}

std::vector<Speciale*> Collection::getSpecialeColl()const{
    return m_specialeCo;
}

void Collection::setCreatureColl(std::vector<Creature*> creature){
    m_creatureCo=creature;
}

void Collection::setcEnergieColl(std::vector<Energie*> cEnergie){
    m_cEnergieCo=cEnergie;
}

void Collection::setSpecialeColl(std::vector<Speciale*> speciale){
    m_specialeCo=speciale;
}


/*
Pour afficher la collection notamment lors de la selection du deck
pas de parametres, pas de retour
*/

void Collection::afficherCrea(){
    int lig=10, col =1,i=0;
    for(const auto& elem :getCreatureColl()){
       elem->afficher(lig,col);
        i++;
        if(i<3)
        {
           col+=60;
        }
        else if(i == 3)
        {
            col=1;
            lig = 22;
        }
        else if(i>3 && i<=5)
        {
            col+=60;
        }
        else if(i==6)
        {
            col = 1;
            lig = 34;
        }
        else if(i>6 && i<=8)
        {
            col+=60;
        }
        else if(i==9)
        {
            col = 1;
            lig = 46;
        }
        else if(i>9 && i<=11)
        {
            col+=60;
        }
       //col+=25;
        //afficher toutes les cartes
    }
}

void Collection::afficherEner(){
    int lig=10, col =1, i=0;
    for(const auto& elem :getcEnergieColl()){
       elem->afficher(lig,col);
       //col+=25;
        elem->afficher(lig,col);
        i++;
        if(i<3)
        {
           col+=60;
        }
        else if(i == 3)
        {
            col=1;
            lig = 22;
        }
        else if(i>3 && i<=5)
        {
            col+=60;
        }
        else if(i==6)
        {
            col = 1;
            lig = 34;
        }
        else if(i>6 && i<=8)
        {
            col+=60;
        }
        else if(i==9)
        {
            col = 1;
            lig = 46;
        }
        else if(i>9 && i<=11)
        {
            col+=60;
        }
        //afficher toutes les cartes
    }
}

void Collection::afficherSpe(){
    int lig=10, col =1,i=0;
    for(const auto& elem :getSpecialeColl()){
       elem->afficher(lig,col);
       //col+=25;
        elem->afficher(lig,col);
        i++;
        if(i<3)
        {
           col+=60;
        }
        else if(i == 3)
        {
            col=1;
            lig = 22;
        }
        else if(i>3 && i<=5)
        {
            col+=60;
        }
        else if(i==6)
        {
            col = 1;
            lig = 34;
        }
        else if(i>6 && i<=8)
        {
            col+=60;
        }
        else if(i==9)
        {
            col = 1;
            lig = 46;
        }
        else if(i>9 && i<=11)
        {
            col+=60;
        }
        //afficher toutes les cartes
    }
}

/*
Pour ajouter une carte a la collection, quand on gagne l'enjeu par exemple
Parametre: carte a ajouter
Pas de retour
*/

void Collection::ajouterCreature(Creature* nouvCarte)
{
    std::vector<Creature*> creatureColl=getCreatureColl();

    creatureColl.push_back(nouvCarte);
    setCreatureColl(creatureColl);
    std::vector<Carte*> collection = getCollection();
    collection.push_back(nouvCarte);
    setCollection(collection);


}

void Collection::ajouterEnergie(Energie* nouvCarte)
{
    std::vector<Energie*> energieColl=getcEnergieColl();
    energieColl.push_back(nouvCarte);
    setcEnergieColl(energieColl);
    std::vector<Carte*> collection = getCollection();
    collection.push_back(nouvCarte);
    setCollection(collection);

}

void Collection::ajouterSpeciale(Speciale* nouvCarte)
{
    std::vector<Speciale*> specialeColl=getSpecialeColl();
    specialeColl.push_back(nouvCarte);
    setSpecialeColl(specialeColl);
    std::vector<Carte*> collection = getCollection();
    collection.push_back(nouvCarte);
    setCollection(collection);

}


/*
Pour supprimer carte, lorsque perte de l'enjeu par exemple
Parametre: Carte que l'on veut supprimer
Pas de retour
*/

void Collection::supprimerCreature(Creature* carteAsupp)
{
    std::vector<Creature*> creatureCo = getCreatureColl();
    int i=0;

    for(const auto& elem : creatureCo){
        //Si on retrouve la carte dans la collection
        if(elem->getIdentifiant() == carteAsupp->getIdentifiant()){
            creatureCo.erase(creatureCo.begin()+i); //on la supprime de la collection
        }
        i++;
    }

    setCreatureColl(creatureCo);
    std::vector<Carte*> collec = getCollection();
    int j=0;

    for(const auto& element : collec){
        //Si on retrouve la carte dans la collection
        if(element->getIdentifiant() == carteAsupp->getIdentifiant()){
            collec.erase(collec.begin()+j); //on la supprime de la collection
        }
        j++;
    }

    setCollection(collec);

}


void Collection::supprimerEnergie(Energie* carteAsupp)
{
    std::vector<Energie*> energieCo = getcEnergieColl();
    int i=0;

    for(const auto& elem : energieCo){
        //Si on retrouve la carte dans la collection
        if(elem->getIdentifiant() == carteAsupp->getIdentifiant()){
            energieCo.erase(energieCo.begin()+i); //on la supprime de la collection
        }
        i++;
    }

    setcEnergieColl(energieCo);
    std::vector<Carte*> collec = getCollection();
    int j=0;

    for(const auto& element : collec){
        //Si on retrouve la carte dans la collection
        if(element->getIdentifiant() == carteAsupp->getIdentifiant()){
            collec.erase(collec.begin()+j); //on la supprime de la collection
        }
        j++;
    }

    setCollection(collec);
}

void Collection::supprimerSpeciale(Speciale* carteAsupp)
{
    std::vector<Speciale*> specialeCo = getSpecialeColl();
    int i=0;

    for(const auto& elem : specialeCo){
        //Si on retrouve la carte dans la collection
        if(elem->getIdentifiant() == carteAsupp->getIdentifiant()){
            specialeCo.erase(specialeCo.begin()+i); //on la supprime de la collection
        }
        i++;
    }

    setSpecialeColl(specialeCo);
    std::vector<Carte*> collec = getCollection();
    int j=0;

    for(const auto& element : collec){
        //Si on retrouve la carte dans la collection
        if(element->getIdentifiant() == carteAsupp->getIdentifiant()){
            collec.erase(collec.begin()+j); //on la supprime de la collection
        }
        j++;
    }

    setCollection(collec);
}


Creature* Collection::choisirCreaCo()
{
    int choix;
    bool existante = false;
    Creature* achat = new Creature();
    std::vector<Creature*> creature = getCreatureColl();
    ///Pour ajouter la carte dans la collection du joueur
    do
    {
        //afficherCrea();
        gotoligcol(5,1);
        std::cout << "Veuillez saisir l'identifiant de la carte que vous voulez selectionner pour le match : " << std::endl;
        gotoligcol(7,1);
        std::cin >> choix;
        if(std::cin.fail())
        {
            //system("cls");
            gotoligcol(6,1);
            std::cout<<"                                                                                                      ";
            gotoligcol(6,1);
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
            gotoligcol(7,1);
            std::cout<<"           ";

            vider_buffer(); // On remet cin dans un état valide et vide le buffer

        }
        ///METTRE BLINDAGE SI LA CARTE N'EXISTE PAS
        else
        {
            for(const auto& elem : creature)
            {
                //i++;
                if(choix==elem->getIdentifiant())
                {
                    achat=elem; //Si on est arrives au niveau de l'indice de la carte choisie on recupere la carte choisie
                    existante = true;
                }
            }
            if(existante == false)
            {
                //system("cls");
                gotoligcol(6,1);
                //std::cout << "                                         ";
                std::cout<<"L'identifiant que vous avez saisi ne correspond a aucune carte, veuillez saisir un identifiant valide.";
                gotoligcol(7,1);
                std::cout<<"           ";
            }
        }
    }
    while(existante == false);

  /*
   for(const auto& elem : creature){
        delete elem;
    }
    */

    return achat;
}

Energie* Collection::choisirEnerCo()
{
    int choix;
    bool existante = false;
    Energie* achat = new Energie();
    std::vector<Energie*> energie = getcEnergieColl();

    ///Pour ajouter la carte dans la collection du joueur
    do
    {
        gotoligcol(5,1);
        std::cout << "Veuillez saisir l'identifiant de la carte que vous voulez selectionner pour le match : " << std::endl;
        gotoligcol(7,1);
        std::cin >> choix;
        if(std::cin.fail())
        {

            gotoligcol(6,1);
            std::cout<<"                                                                                                      ";
            gotoligcol(6,1);
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;

            vider_buffer(); // On remet cin dans un état valide et vide le buffer
            gotoligcol(7,1);
            std::cout<<"           ";

        }

        else
        {
            for(const auto& elem : energie)
            {
                //i++;
                if(choix==elem->getIdentifiant())
                {
                    achat=elem; //Si on est arrives au niveau de l'indice de la carte choisie on recupere la carte choisie
                    existante = true;
                }
            }
            if(existante == false)
            {
                gotoligcol(6,1);
                std::cout<<"L'identifiant que vous avez saisi ne correspond a aucune carte, veuillez saisir un identifiant valide.";
                gotoligcol(7,1);
                std::cout<<"           ";
            }
        }
    }
    while(existante == false);
/*
    for(const auto& elem : energie){
        delete elem;
    }
*/
    return achat;
}

Speciale* Collection::choisirSpeCo()
{
    int choix;
    bool existante = false;
    Speciale* achat = new Speciale();
    std::vector<Speciale*> speciale = getSpecialeColl();
    ///Pour ajouter la carte dans la collection du joueur
    do
    {
        gotoligcol(5,1);
        std::cout << "Veuillez saisir l'identifiant de la carte que vous voulez selectionner pour le match: " << std::endl;
        gotoligcol(7,1);
        std::cin >> choix;
        if(std::cin.fail())
        {

            gotoligcol(6,1);
            std::cout<<"                                                                                                      ";
            gotoligcol(6,1);
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
            gotoligcol(7,1);
            std::cout<<"           ";

            vider_buffer(); // On remet cin dans un état valide et vide le buffer

        }
        ///METTRE BLINDAGE SI LA CARTE N'EXISTE PAS
        else
        {
            for(const auto& elem : speciale)
            {
                //i++;
                if(choix==elem->getIdentifiant())
                {
                    achat=elem; //Si on est arrives au niveau de l'indice de la carte choisie on recupere la carte choisie
                    existante = true;
                }
            }
            if(existante == false)
            {
                gotoligcol(6,1);
                std::cout<<"L'identifiant que vous avez saisi ne correspond a aucune carte, veuillez saisir un identifiant valide.";
                gotoligcol(7,1);
                std::cout<<"           ";
            }
        }
    }
    while(existante == false);
/*
    for(const auto& elem : speciale){
        delete elem;
    }
*/
    return achat;
}
