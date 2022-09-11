#include "boutique.h"

#define QUANTITE 50

//Constructeur
Boutique::Boutique()
{}

//Destructeur
Boutique::~Boutique()
{}


///Accesseurs


std::vector<Creature*> Boutique::getCreature()const
{
    return m_creature;
}
std::vector<Energie*> Boutique::getcEnergie()const
{
    return m_cEnergie;
}

std::vector<Speciale*> Boutique::getSpeciale()const
{
    return m_speciale;
}

void Boutique::setCreature(std::vector<Creature*> creature)
{
    m_creature=creature;
}

void Boutique::setcEnergie(std::vector<Energie*> cEnergie)
{
    m_cEnergie=cEnergie;
}

void Boutique::setSpeciale(std::vector<Speciale*> speciale)
{
    m_speciale=speciale;
}

std::vector<Creature*> Boutique::getCreatureU()const
{
    return m_creatureU;
}
std::vector<Energie*> Boutique::getcEnergieU()const
{
    return m_cEnergieU;
}

std::vector<Speciale*> Boutique::getSpecialeU()const
{
    return m_specialeU;
}

void Boutique::setCreatureU(std::vector<Creature*> creatureU)
{
    m_creatureU=creatureU;
}

void Boutique::setcEnergieU(std::vector<Energie*> cEnergieU)
{
    m_cEnergieU=cEnergieU;
}

void Boutique::setSpecialeU(std::vector<Speciale*> specialeU)
{
    m_specialeU=specialeU;
}



/*
On ajoute toutes les cartes dans la boutique. La boutique sert a contenir toutes les cartes du jeu
Pas de parametres, pas de retour
*/
void Boutique::remplir()
{

    int identifiant=0;//s'incremente de 1 a chaque fois qu'on associe a une carte


    ///Vecteurs///
    std::vector <Creature*> creature = getCreature();
    std::vector <Energie*> energie = getcEnergie();
    std::vector <Speciale*> speciale = getSpeciale();

    std::vector <Creature*> creatureU = getCreatureU();
    std::vector <Energie*> energieU = getcEnergieU();
    std::vector <Speciale*> specialeU = getSpecialeU();

    ///Attaques///





    ////////////////////
    ///AJOUT CREATURES//
    ////////////////////
 for(int i=0; i<QUANTITE; i++)
    {
        Creature* crea1 = new Creature("Bloom", "Gardiene de la flamme du dragon", 15, 110, "Feu",QUANTITE,5);

        //Attaques

        crea1->ajouter("Feu du Dragon", 2, "Feu", 25);
        crea1->ajouter("Dragon Kick", 1, "Feu", 20);
        crea1->setIdentifiant(identifiant); //on assigne un identifiant a une carte
        creature.push_back(crea1);
        if(i == crea1->getQuantite()-1) creatureU.push_back(crea1); //Si c'est la derniere carte a ajouter, on la copie dans le vecteur de cartes uniques
        identifiant++; //On incremente dans la boucle afin que l'identifiant soit unique pour chaque carte
        //delete crea1;
    }
    for(int i=0; i<QUANTITE; i++)
    {
        Creature* crea2 = new Creature("Stella", "Princesse du royaume du soleil", 15, 80, "Lumiere",QUANTITE,6);

        //Attaques

        crea2->ajouter("Lumiere de Solaria", 2, "Lumiere", 35);
        crea2->ajouter("Explosion solaire", 1, "Lumiere", 20);

        crea2->setIdentifiant(identifiant);
        creature.push_back(crea2);
        if(i == crea2->getQuantite()-1) creatureU.push_back(crea2);
        identifiant++;

        //delete crea2;
    }

    for(int i=0; i<QUANTITE; i++)
    {

        Creature* crea3 = new Creature("Flora", "Meilleure amie de la nature", 15, 150,"Terre",QUANTITE,8);

        //Attaques

        crea3->ajouter("Tremblement", 2, "Terre", 15);
        crea3->ajouter("Lianes Sauvages", 1, "Terre", 10);

        crea3->setIdentifiant(identifiant);
        creature.push_back(crea3);
        if(i== crea3->getQuantite()-1) creatureU.push_back(crea3);
        identifiant++;

        //delete crea3;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Creature* crea4 = new Creature("Tecna", "Genie de la technologie", 15, 120, "Technologie", QUANTITE,7);

        //Attaques

        crea4->ajouter("Explosion Technologique", 2, "Technologie", 30);
        crea4->ajouter("Rayon Laser", 1, "Technologie", 15);

        crea4->setIdentifiant(identifiant);
        creature.push_back(crea4);
        if(i== crea4->getQuantite()-1) creatureU.push_back(crea4);
        identifiant++;

        //delete crea4;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Creature* crea5 = new Creature("Musa", "Fee de la musique", 12, 140, "Technologie", QUANTITE,9);

        //Attaques

        crea5->ajouter("Mega sound", 2, "Technologie", 30);
        crea5->ajouter("Attaque d'ultrason", 1, "Technologie", 10);

        crea5->setIdentifiant(identifiant);
        creature.push_back(crea5);
        if(i== crea5->getQuantite()-1) creatureU.push_back(crea5);
        identifiant++;

        //delete crea5;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Creature* crea6 = new Creature("Leila", "Reine du plasma", 34, 90, "Terre", QUANTITE,10);

        //Attaques

        crea6->ajouter("Attaque plasmique", 2, "Terre", 40);
        crea6->ajouter("Flux d'eau courante", 1, "Terre", 10);

        crea6->setIdentifiant(identifiant);
        creature.push_back(crea6);
        if(i== crea6->getQuantite()-1) creatureU.push_back(crea6);
        identifiant++;

        //delete crea6;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Creature* crea7 = new Creature("Roxy", "Fee des animaux", 45, 100, "Feu", QUANTITE,11);

        //Attaques

        crea7->ajouter("Attaque de l'ours", 3, "Feu", 60);
        crea7->ajouter("Chant de l'aigle", 1, "Feu", 20);

        crea7->setIdentifiant(identifiant);
        creature.push_back(crea7);
        if(i== crea7->getQuantite()-1) creatureU.push_back(crea7);
        identifiant++;

        //delete crea7;
    }


    ////////////////////
    ///AJOUT ENERGIES///
    ////////////////////

    for(int i=0; i<QUANTITE; i++)
    {
        Energie* e1 = new Energie("Source d'energie", "Energie fournie par la technologie", 5, 1, 15, "Technologie",QUANTITE,1);

        e1->setIdentifiant(identifiant);
        energie.push_back(e1);
        if(i==e1->getQuantite()-1) energieU.push_back(e1);
        identifiant++;

        //delete e1;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Energie* e2 = new Energie("Source d'energie", "Energie fournie par la nature", 5,1,2,"Terre", QUANTITE,2);

        e2->setIdentifiant(identifiant);
        energie.push_back(e2);
        if(i== e2->getQuantite()-1) energieU.push_back(e2);
        identifiant++;

        //delete e2;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Energie* e3 = new Energie("Source d'energie", "Energie fournie par la lumiere", 5,1,14,"Lumiere", QUANTITE,3);

        e3->setIdentifiant(identifiant);
        energie.push_back(e3);
        if(i== e3->getQuantite()-1) energieU.push_back(e3);
        identifiant++;

        //delete e3;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Energie* e4 = new Energie("Source d'energie", "Energie fournie par le feu", 5,1,4,"Feu", QUANTITE,4);

        e4->setIdentifiant(identifiant);
        energie.push_back(e4);
        if(i== e4->getQuantite()-1) energieU.push_back(e4);
        identifiant++;

        //delete e4;
    }

    /////////////////////
    ///AJOUT SPECIALES///
    /////////////////////

    for(int i=0; i<QUANTITE; i++)
    {
        Speciale* speciale1 = new Speciale(0,"Spe1","Auto-Hit", true, 5,QUANTITE,12,1);

        speciale1->setIdentifiant(identifiant);
        speciale.push_back(speciale1);
        if(i== speciale1->getQuantite()-1) specialeU.push_back(speciale1);
        identifiant++;

        //delete speciale1;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Speciale* speciale2 = new Speciale(1,"Spe2","Vol à l'adversaire", true, 3, QUANTITE,13,2);

        speciale2->setIdentifiant(identifiant);
        speciale.push_back(speciale2);
        if(i== speciale2->getQuantite()-1) specialeU.push_back(speciale2);
        identifiant++;

        //delete speciale2;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Speciale* speciale3 = new Speciale(0,"Spe3","Recupere une carte du cimetiere", true, 3,QUANTITE,14,3);

        speciale3->setIdentifiant(identifiant);
        speciale.push_back(speciale3);
        if(i== speciale3->getQuantite()-1) specialeU.push_back(speciale3);
        identifiant++;

        //delete speciale3;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Speciale* speciale4 = new Speciale(2,"Spe4","Soigne une creature", true, 5, QUANTITE, 15,4);

        speciale4->setIdentifiant(identifiant);
        speciale.push_back(speciale4);
        if(i== speciale4->getQuantite()-1) specialeU.push_back(speciale4);
        identifiant++;

        //delete speciale4;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Speciale* speciale5 = new Speciale(1,"Spe5","Immunise", true, 5, QUANTITE, 16,5);

        speciale5->setIdentifiant(identifiant);
        speciale.push_back(speciale5);
        if(i== speciale5->getQuantite()-1) specialeU.push_back(speciale5);
        identifiant++;

        //delete speciale5;
    }

    for(int i=0; i<QUANTITE; i++)
    {
        Speciale* speciale6 = new Speciale(0,"Spe6","Fait perdre une carte a l'adversaire", true,3,QUANTITE, 17,6);

        speciale6->setIdentifiant(identifiant);
        speciale.push_back(speciale6);
        if(i== speciale6->getQuantite()-1) specialeU.push_back(speciale6);
        identifiant++;

        //delete speciale6;
    }

    //On met les vecteurs modifies dans les attibuts
    setCreature(creature);
    setcEnergie(energie);
    setSpeciale(speciale);

    setCreatureU(creatureU);
    setcEnergieU(energieU);
    setSpecialeU(specialeU);

}

/*
Affichage de la liste des cartes disponibles dans la boutique
Pas de parametres, pas de retour
*/

void Boutique::afficherCrea()
{
    int lig=8, col =1, i=0;
    for(const auto& elem :getCreatureU())
    {
        i++;
        elem->afficher(lig,col);
        if(i<3)
        {
           col+=60;
        }
        else if(i == 3)
        {
            col=1;
            lig = 20;
        }
        else if(i>3 && i<=5)
        {
            col+=60;
        }
        else
        {
            col = 1;
            lig = 32;
        }

        //afficher toutes les cartes
    }
}

void Boutique::afficherEner()
{
    int lig=8, col =1, i = 0;
    for(const auto& elem :getcEnergieU())
    {
        i++;
        elem->afficher(lig,col);
        if(i<3)
        {
           col+=60;
        }
        else if(i == 3)
        {
            col=1;
            lig = 20;
        }
        //afficher toutes les cartes
    }
}

void Boutique::afficherSpe()
{
    int lig=8, col =1, i=0;
    for(const auto& elem :getSpecialeU())
    {
        i++;
        elem->afficher(lig,col);
        if(i<3)
        {
           col+=60;
        }
        else if(i == 3)
        {
            col=1;
            lig = 20;
        }
        else if(i>3 && i<=5)
        {
            col+=60;
        }
        //afficher toutes les cartes
    }
}


/*
Permet de selectionner la carte que l'on souhaite acheter
pas de parametre
retour : carte achetee
*/

Creature* Boutique::choisirCrea()
{
    int choix;
    bool existante = false;
    Creature* achat = new Creature();
    std::vector<Creature*> creature = getCreature();
    ///Pour ajouter la carte dans la collection du joueur
    do
    {
        //afficherCrea();
        gotoligcol(47,1);
        std::cout << "Veuillez saisir l'identifiant de la carte que vous voulez acheter : " << std::endl;
        gotoligcol(49,1);
        std::cin >> choix;
        if(std::cin.fail())
        {
            //system("cls");
            gotoligcol(48,1);
            std::cout<<"                                                                                                      ";
            gotoligcol(48,1);
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
            gotoligcol(49,1);
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
                gotoligcol(48,1);
                //std::cout << "                                         ";
                std::cout<<"L'identifiant que vous avez saisi ne correspond a aucune carte, veuillez saisir un identifiant valide.";
                gotoligcol(49,1);
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

Energie* Boutique::choisirEner()
{
    int choix;
    bool existante = false;
    Energie* achat = new Energie();
    std::vector<Energie*> energie = getcEnergie();

    ///Pour ajouter la carte dans la collection du joueur
    do
    {
        gotoligcol(32,1);
        std::cout << "Veuillez saisir l'identifiant de la carte que vous voulez acheter : " << std::endl;
        gotoligcol(34,1);
        std::cin >> choix;
        if(std::cin.fail())
        {

            gotoligcol(33,1);
            std::cout<<"                                                                                                      ";
            gotoligcol(33,1);
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;

            vider_buffer(); // On remet cin dans un état valide et vide le buffer
            gotoligcol(34,1);
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
                gotoligcol(33,1);
                std::cout<<"L'identifiant que vous avez saisi ne correspond a aucune carte, veuillez saisir un identifiant valide.";
                gotoligcol(34,1);
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

Speciale* Boutique::choisirSpe()
{
    int choix;
    bool existante = false;
    Speciale* achat = new Speciale();
    std::vector<Speciale*> speciale = getSpeciale();
    ///Pour ajouter la carte dans la collection du joueur
    do
    {
        gotoligcol(32,1);
        std::cout << "Veuillez saisir l'identifiant de la carte que vous voulez acheter : " << std::endl;
        gotoligcol(34,1);
        std::cin >> choix;
        if(std::cin.fail())
        {

            gotoligcol(33,1);
            std::cout<<"                                                                                                      ";
            gotoligcol(33,1);
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
            gotoligcol(34,1);
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
                gotoligcol(33,1);
                std::cout<<"L'identifiant que vous avez saisi ne correspond a aucune carte, veuillez saisir un identifiant valide.";
                gotoligcol(34,1);
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

/*
Permet de supprimer la carte achetee des conteneurs de la boutique
Parametre : carte achetee
pas de retour
*/
void Boutique::supprimerCarteCrea(Creature* achat)
{
    std::vector <Creature*> creatureU = getCreatureU();
    std::vector <Creature*> creature = getCreature();

    bool added = false;
    int i=0;
    int delete_element;

    for(const auto& elem : creature)
    {
        if(elem->getIdentifiant() == achat->getIdentifiant())
        {
            delete_element = i;
        }
        else if((elem->getNom() == achat->getNom())&&(elem->getIdentifiant()!=achat->getIdentifiant())&& !added)
        {
            creatureU.push_back(elem);
            added = true;
        }
            i++;
    }
    creature.erase(creature.begin()+delete_element);

    int j=0;

    for(const auto& elem : creatureU)
    {
        if(elem->getIdentifiant() == achat->getIdentifiant())
        {
            creatureU.erase(creatureU.begin()+j);//Si on retrouve la carte achetee dans le vecteur on la supprime du vect
        }
        j++;
    }

    //Si c'est la derniere carte de ce modele
    /*if(achat.getQuantite()==1) {
        for(const auto elem : cartesU){
            if(*elem==achat) cartesU.erase(cartes.begin()+i); //Si on retrouve la carte achetee dans le vecteur on la supprime du vect
             i++;
        }*/


    setCreature(creature);
    setCreatureU(creatureU);
/*
    for(const auto& elem : creature){
        delete elem;
    }

    for(const auto& elem : creatureU){
        delete elem;
    }
*/
}


void Boutique::supprimerCarteEner(Energie* achat)
{
    std::vector <Energie*> energieU = getcEnergieU();
    std::vector <Energie*> energie = getcEnergie();

    bool added = false;
    int i=0;
    int delete_element;
    for(const auto& elem : energie)
    {
        if(elem->getIdentifiant() == achat->getIdentifiant())
        {
            delete_element = i;
        }
        else if(elem->getDescription() == achat->getDescription()&&(elem->getIdentifiant()!=achat->getIdentifiant())&& !added)
        {
            energieU.push_back(elem);
            added = true;
        }
            i++;
    }
    energie.erase(energie.begin()+delete_element);

    int j=0;

    for(const auto& elem : energieU)
    {
        if(elem->getIdentifiant() == achat->getIdentifiant())
        {
            energieU.erase(energieU.begin()+j);//Si on retrouve la carte achetee dans le vecteur on la supprime du vect
        }
        j++;
    }
    //Si c'est la derniere carte de ce modele
    /*if(achat.getQuantite()==1) {
        for(const auto elem : cartesU){
            if(*elem==achat) cartesU.erase(cartes.begin()+i); //Si on retrouve la carte achetee dans le vecteur on la supprime du vect
             i++;
        }*/

    setcEnergie(energie);
    setcEnergieU(energieU);
/*
    for(const auto& elem : energie){
        delete elem;
    }

    for(const auto& elem : energieU){
        delete elem;
    }
*/
}

void Boutique::supprimerCarteSpe(Speciale* achat)
{
    std::vector <Speciale*> specialeU = getSpecialeU();
    std::vector <Speciale*> speciale = getSpeciale();

    bool added = false;
    int i=0;
    int delete_element;

    for(const auto& elem : speciale)
    {
        if(elem->getIdentifiant() == achat->getIdentifiant())
        {
            delete_element = i;
        }
        else if(elem->getNom() == achat->getNom()&&(elem->getIdentifiant()!=achat->getIdentifiant()) && !added)
        {
            specialeU.push_back(elem);
            added = true;
        }
            i++;
    }
    speciale.erase(speciale.begin()+delete_element);

    int j=0;

    for(const auto& elem : specialeU)
    {
        if(elem->getIdentifiant() == achat->getIdentifiant())
        {
            specialeU.erase(specialeU.begin()+j);//Si on retrouve la carte achetee dans le vecteur on la supprime du vect

        }
            j++;
    }
    //Si c'est la derniere carte de ce modele
    /*if(achat.getQuantite()==1) {
        for(const auto elem : cartesU){
            if(*elem==achat) cartesU.erase(cartes.begin()+i); //Si on retrouve la carte achetee dans le vecteur on la supprime du vect
             i++;
        }*/

    setSpeciale(speciale);
    setSpecialeU(specialeU);
/*
    for(const auto& elem : speciale){
        delete elem;
    }

    for(const auto& elem : specialeU){
        delete elem;
    }
*/
}

void Boutique::Identifiant(){

    std::vector<Creature*> crea= getCreature();
    std::vector<Energie*> ener = getcEnergie();
    std::vector<Speciale*> spe=getSpeciale();

    for(const auto& elem : crea){
        std::cout<< "crea : " << elem->getIdentifiant()<<std::endl;
    }

    std::cout << std::endl;

    for(const auto& elem : ener){
        std::cout<< "ener : " << elem->getIdentifiant() << std::endl;
    }

    std::cout<<std::endl;

    for(const auto& elem : spe){
        std::cout<< "spe : " << elem->getIdentifiant() << std::endl;
    }


   /* for(const auto& elem : crea){
        delete elem;
    }

    for(const auto& elem : ener){
        delete elem;
    }

    for(const auto& elem : spe){
        delete elem;
    }*/
}


Carte * Boutique::createCarte(int identifiant)
{
    int q = 1;
    if(identifiant>=0 && identifiant <50)
    {
        Creature* ptr = new Creature("Bloom", "Gardiene de la flamme du dragon", 15, 110, "Feu",q,identifiant);
        ptr->ajouter("Feu du Dragon", 2, "Feu", 25);
        ptr->ajouter("Dragon Kick", 1, "Feu", 20);
        return ptr;
    }
    else if(identifiant>=50 && identifiant <100)
    {
        Creature* ptr = new Creature("Stella", "Princesse du royaume du soleil", 15, 80, "Lumiere",q,identifiant);
        ptr->ajouter("Lumiere de Solaria", 2, "Lumiere", 35);
        ptr->ajouter("Explosion solaire", 1, "Lumiere", 20);
        return ptr;
    }
    else if(identifiant>=100 && identifiant <150)
    {
        Creature* ptr = new Creature("Tecna", "Genie de la technologie", 15, 120, "Technologie", q,identifiant);
        ptr->ajouter("Explosion Technologique", 2, "Technologie", 30);
        ptr->ajouter("Rayon Laser", 1, "Technologie", 15);
        return ptr;
    }
    else if(identifiant>=150 && identifiant <200)
    {
        Creature* ptr = new Creature("Flora", "Meilleure amie de la nature", 15, 150,"Terre",q,identifiant);
        ptr->ajouter("Tremblement", 2, "Terre", 15);
        ptr->ajouter("Lianes Sauvages", 1, "Terre", 10);
        return ptr;
    }
    else if(identifiant>=200 && identifiant <250)
    {
        Creature* ptr = new Creature("Musa","Fee de la musique", 12, 140, "Technologie", q,identifiant);
        ptr->ajouter("Mega sound", 2, "Technologie", 30);
        ptr->ajouter("Attaque d'ultrason", 1, "Technologie", 10);
        return ptr;
    }
    else if(identifiant>=250 && identifiant <300)
    {
        Creature* ptr = new Creature("Leila", "Reine du plasma", 34, 90, "Terre", q,identifiant);
        ptr->ajouter("Attaque plasmique", 2, "Terre", 40);
        ptr->ajouter("Flux d'eau courante", 1, "Terre", 10);
        return ptr;
    }
    else if(identifiant>=300 && identifiant <350)
    {
        Creature* ptr = new Creature("Roxy", "Fee des animaux", 45, 100, "Feu", q,identifiant);
        ptr->ajouter("Attaque de l'ours", 3, "Feu", 60);
        ptr->ajouter("Chant de l'aigle", 1, "Feu", 20);
        return ptr;
    }
    else if(identifiant>=350 && identifiant <400)
    {
        Energie* ptr = new Energie("Source d'energie", "Energie fournie par la technologie", 5, 1, 15, "Technologie",q,identifiant);
        return ptr;
    }
    else if(identifiant>=400 && identifiant <450)
    {
        Energie* ptr = new Energie("Source d'energie", "Energie fournie par la nature", 5,1,2,"Terre", q,identifiant);
        return ptr;
    }
    else if(identifiant>=450 && identifiant <500)
    {
        Energie* ptr = new Energie("Source d'energie", "Energie fournie par la lumiere", 5,1,14,"Lumiere", q,identifiant);
        return ptr;
    }
    else if(identifiant>=500 && identifiant <550)
    {
        Energie* ptr = new Energie("Source d'energie", "Energie fournie par le feu", 5,1,4,"Feu", q,identifiant);
        return ptr;
    }
    else if(identifiant>=550 && identifiant <600)
    {
        Speciale* ptr = new Speciale(0,"Spe1","Auto-Hit", true, 5,q,identifiant,1);
        return ptr;
    }
    else if(identifiant>=600 && identifiant <650)
    {
        Speciale* ptr = new Speciale(1,"Spe2","Vol à l'adversaire", true, 3, q,identifiant,2);
        return ptr;
    }
    else if(identifiant>=650 && identifiant <700)
    {
        Speciale* ptr = new Speciale(0,"Spe3","Recupere une carte du cimetiere", true, 3,q,identifiant,3);
        return ptr;
    }
    else if(identifiant>=700 && identifiant <750)
    {
        Speciale* ptr = new Speciale(2,"Spe4","Soigne une creature", true, 5, q, identifiant,4);
        return ptr;
    }
    else if(identifiant>=750 && identifiant <800)
    {
        Speciale* ptr = new Speciale(1,"spe5","Immunise", true, 5, q, identifiant,5);
        return ptr;
    }
    else if(identifiant>=800 && identifiant <850)
    {
        Speciale* ptr = new Speciale(0,"Spe6","Fait perdre une carte a l'adversaire", true,3,q, identifiant,6);
        return ptr;
    }
    else
    {
        Carte * ptr = NULL;
        return ptr;
    }

}

bool Boutique::present(Carte* cartes)
{
    std::vector <Creature*> creaU=getCreatureU();
    std::vector <Energie*> eneU=getcEnergieU();
    std::vector <Speciale*> speU=getSpecialeU();
    switch(cartes->getGenre())
    {
    case 1:
        {
            for(const auto& elem : creaU)
            {
                if(elem->getNom()==cartes->getNom())
                {
                    return true;
                }
            }
            break;
        }
    case 2:
        {
            for(const auto& elem : eneU)
            {
                if(elem->getDescription()==cartes->getDescription())
                {
                    return true;
                }
            }
            break;
        }
    case 3:
        {
            for(const auto& elem : speU)
            {
                if(elem->getNom()==cartes->getNom())
                {
                    return true;
                }
            }
            break;
        }
    }
    return false;
}

bool Boutique::chargerBoutique()
{
    bool existe=false;
    std::vector <Creature*> creaU=getCreatureU();
    std::vector <Energie*> eneU=getcEnergieU();
    std::vector <Speciale*> speU=getSpecialeU();
    std::ifstream game("game.txt");
    std::string s;
    //std::vector <Carte*> Lista;
    //m_collection=Collection();
    std::vector <Creature*> LC;
    std::vector <Energie*> LE;
    std::vector <Speciale*> LS;
    while(std::getline(game, s))
    {
        std::string n=s.substr(0,s.find("="));
        if(n=="boutique")
        {
            existe=true;
            std::string m=s.substr(s.find("=")+1,100000000);
            std::cout<< m<<std::endl;

            std::string delimiter = ",";

            size_t pos = 0;
            std::string token;
            while ((pos = m.find(delimiter)) != std::string::npos)
            {
                token = m.substr(0, pos);
                Carte* c_token = createCarte(std::stoi(token));
                /*      CONTROLLARE TIPO DELLA CARTE E AGGIUNGERLA NEL VETTORE CORRISPONDENTE */
                //std::cout << "genere: " << c_token->getNom() << "\t" << c_token->getGenre()<< std::endl;
                switch(c_token->getGenre())
                {

                case 1:
                {
                    Creature * crea = (Creature * ) c_token;
                    LC.push_back(crea);
                    if(!present(crea))
                    {
                        creaU.push_back(crea);
                        setCreatureU(creaU);
                    }
                    break;
                }

                case 2:
                {
                    Energie* ene=(Energie*) c_token;
                    LE.push_back(ene);
                    if(!present(ene))
                    {
                        eneU.push_back(ene);
                        setcEnergieU(eneU);
                    }
                    break;
                }

                case 3:
                {
                    Speciale* spe=(Speciale*) c_token;
                    LS.push_back(spe);
                    if(!present(spe))
                    {
                        speU.push_back(spe);
                        setSpecialeU(speU);
                    }
                    break;
                }

                }

                m.erase(0, pos + 1);
            }
            break;
            //std::cout << o << std::endl;
        }
    }
    game.close();
    setCreature(LC);
    setcEnergie(LE);
    std::cout << "Lunghezza carte energia: " << LE.size() << std::endl;
    setSpeciale(LS);
    return existe;
}



void Boutique::sauvegarde()
{

    std::string sFinale;
    std::string StringCollection="";

    std::vector <Creature*> crea=getCreature();
    std::vector <Energie*> ene=getcEnergie();
    std::vector <Speciale*> spe=getSpeciale();

    for(unsigned int i=0; i<crea.size(); i++)
    {
        StringCollection+=std::to_string(crea[i]->getIdentifiant())+","; //additionne tous les identifiants avec virgules
    }

    for(unsigned int i=0; i<ene.size(); i++)
    {
        StringCollection+=std::to_string(ene[i]->getIdentifiant())+","; //additionne tous les identifiants avec virgules
    }

    for(unsigned int i=0; i<spe.size(); i++)
    {
        StringCollection+=std::to_string(spe[i]->getIdentifiant())+","; //additionne tous les identifiants avec virgules
    }

    sFinale="boutique="+StringCollection; //additionne nom du joueur, =, identifiants des cartes ; cagnotte
    //std::cout << sFinale << std::endl;
    std::vector<std::string> NewText;
    std::ifstream oldGame("game.txt");
    std::string s;
    bool Found = false;
    //std::vector <Carte> Lista;
    while(std::getline(oldGame, s))
    {
        //std::cout << s << std::endl;
        std::string n=s.substr(0,s.find("="));
        if(n=="boutique")
        {
            NewText.push_back(sFinale);
            Found = true;
        }
        else
        {
            NewText.push_back(s);
        }
    }
    oldGame.close();

    std::ofstream game;
    game.open("game.txt", std::ios::out | std::ios::trunc);
    if(game.is_open())
    {
        for(unsigned int i=0; i<NewText.size(); i++)
        {
            //std::cout << "Stringa: " << NewText[i] << std::endl;
            game << NewText[i] << std::endl;
        }
        if(NewText.size() == 0 || !Found)
        {
            //the file was empty
            game << sFinale << std::endl;
        }
    }

    game.close();
}
