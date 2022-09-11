#include "jeu.h"

#define TOURS_MAX 30


///Constructeur
Jeu::Jeu()
{
    //Initialisation des joueurs (chargement)
    /*std::ifstream joueurs("game.txt");
    int nb_line=0;
    std::string ligne;
    Joueur tmp;
    std::vector<Creature*> tmpCreatures;
    std::vector<Energie*> tmpEnergies;
    std::vector<Speciale*> tmpSpeciales;

    while(std::getline(joueurs,ligne))
        nb_line++;

    for(int i=0; i<nb_line; i++)
    {
        tmp.recupCollection();//Recupere les donnees du joueur dans le fichier
        m_joueurs.push_back(tmp); //psuh le nouveau joueur dans le vecteur de joueurs
    }

    //Initialisation boutique
   // m_boutique.remplir();


    //Initialisation cartes prises
    for(const auto elem : m_joueurs)
    {
        //On recupere la liste de chaque type de carte dans la collection du joueur
          tmpCreatures=elem.getCollection().getCreatureColl();
          tmpEnergies=elem.getCollection().getcEnergieColl();
          tmpSpeciales=elem.getCollection().getSpecialeColl();

        for(const auto elem : tmpCreatures)
        {
            m_cartesCreaPrises.push_back(elem);
        }
        for(const auto elem : tmpEnergies)
        {
            m_cartesEnerPrises.push_back(elem);
        }
        for(const auto elem : tmpSpeciales)
        {
            m_cartesSpePrises.push_back(elem);
        }

    }*/
}


///Destructeur
Jeu :: ~Jeu(){


    for(const auto& elem : m_cartesCreaPrises)
    {
        delete elem;
    }
    for(const auto& elem : m_cartesEnerPrises)
    {
        delete elem;
    }
    for(const auto& elem : m_cartesSpePrises)
    {
        delete elem;
    }
    for(const auto& elem : m_boutique.getCreature())
    {
        delete elem;
    }
    for(const auto& elem : m_boutique.getcEnergie()){
        delete elem;
    }

    for(const auto& elem : m_boutique.getSpeciale()){
        delete elem;
    }

    for(const auto& elem : m_boutique.getCreatureU())
    {
        delete elem;
    }
    for(const auto& elem : m_boutique.getcEnergieU())
    {
        delete elem;
    }

    for(const auto& elem : m_boutique.getSpecialeU())
    {
        delete elem;
    }


}


/*
Tout le jeu se fait dans cette methode : utilise toutes les methodes implementees
pas de parametre, pas de retour
*/
void Jeu::deroulement()
{
    //Initialisation de la boutique
    Boutique boutique;
    //boutique=getBoutique();

    if(!boutique.chargerBoutique())
    {
        boutique.remplir();
    }
    //boutique.remplir();

    setBoutique(boutique);

    std::vector<Joueur> joueurs = getJoueurs();

    char quit;

    do{
        system("cls");
        int choix=menu();

        switch(choix){
            case 1 :
                afficherRegles();
                std::cout<<"Entrez m pour retourner sur le menu principal" << std::endl;
                std::cin >> quit;
                break;


            case 2 :
                system("cls");
                match();
                std::cout<<"Entrez m pour retourner sur le menu principal" << std::endl;
                std::cin >> quit;
                break;

            case 3 :
                system("cls");
                lancerBoutique();
                std::cout<<"Entrez m pour retourner sur le menu principal" << std::endl;
                std::cin >> quit;
                break;

            case 4 :
                for(auto elem : joueurs){
                    elem.sauvegarde(); //On sauvegarde chaque joueur dans le fichier
                }
                m_boutique.sauvegarde();
                exit(0); //On quitte la console
        }

    }while(quit == 'm');
}


/*
Affiche le menu principal
pas de parametre
retourne le choix du joueur
*/
int Jeu::menu(){

   int choix;
    do
    {
        gotoligcol(12,60);
        std::cout<<"________________________________________________";//affichage du menu centré sur l'écran
        gotoligcol(15,70);
        std::cout<<"* Bienvenue dans WINXMON *";
        gotoligcol(18,70);
        std::cout <<"Que voulez vous faire : ";
        gotoligcol(20,70);
        std::cout << "1. Afficher les regles";
        gotoligcol(22,70);
        std::cout<< "2. Commencer un nouveau match";
        gotoligcol(24,70);
        std::cout<< "3. Ouvrir la boutique";
        gotoligcol(26,70);
        std::cout<< "4. Quitter le jeu";
        gotoligcol(29,60);
        std::cout<<"________________________________________________";
        gotoligcol(31,66);
        std::cin >> choix;
        if(std::cin.fail())
        {
            system("cls");
            gotoligcol(30,66);
            std::cerr << "Erreur, saisie incorrecte." << std::endl;

            vider_buffer(); // On remet cin dans un état valide et vide le buffer
        }
        else if(choix > 4 || choix < 1)
        {
            system("cls");
            gotoligcol(30,66);
            std::cout << "Veuillez rentrer une valeur entre 1 et 4 svp";
        }

    }while(choix>4 || choix<1);


    return choix;
}

/*
affiche les regles du jeu
pas de retour, pas de parametre
*/
void Jeu::afficherRegles(){
    std::ifstream fRegles("regles.txt");
    std::string regles;
    std::string ligne;

    std::system("cls"); //On efface ce qu'il y a dans la console

    //Tant qu'il y a une ligne a lire
    while(getline(fRegles, ligne))
    {
        regles+=ligne; //On ajoute la ligne au texte
    }

    std::cout << "REGLES" <<std::endl<<std::endl;
    std::cout<<regles<<std::endl; //On affiche les regles
}



/*
Methode a utiliser lorsque les joueurs veulent lancer un match
Demande s'il y a des nouveaux joueurs, permets aux joueurs de choisir leurs decks
Pas de parametres, pas de retour
*/
void Jeu::lancerMatch()
{

    Match nouveauMatch;
    std::string nom1,nom2;
    std::vector<Joueur> listeJoueurs=getJoueurs();
    bool exist=false; //Permet de savoir si l'utilisateur rentre un pseudo qui existe deja
    Joueur joueur1;
    Joueur joueur2;

    Collection collec1;
    Collection collec2;

    int choix(0);
    bool reussi = false;

    //Blindqge
    do
    {

        gotoligcol(2,70);
        std::cout<<"*";
        gotoligcol(2,94);
        std::cout<<"*";
        gotoligcol(2,75);
        std::cout<<"INITIALISATION";
        gotoligcol(4,1);
        std::cout<< "Combien il y a-t-il de nouveaux joueurs pour ce match ? ";
        gotoligcol (5,1);
        std::cout<<"Rentrez un nombre entre 0 et 2";

        gotoligcol(7,1);
        std::cin >> choix;
        if(std::cin.fail())
        {
            system("cls");
            gotoligcol(6,1);
            std::cerr << "Erreur, saisie incorrecte." << std::endl;
            vider_buffer(); // On remet cin dans un état valide et vide le buffer
        }
        else if(choix>2 || choix<0)
        {
            system("cls");
            gotoligcol(6,1);
            std::cout << "Erreur vous ne pouvez pas ajouter plus de 2 joueurs. Resaisissez : ";
        }
        else
        {
            reussi = true;//blindage à l'aide d'un booleen car lorque l'on remet le cin dans un etat valide il prend la valeur de 0 et sors du while
        }
    }
    while(reussi == false);
    //S'il y a 2 nouveaux joueurs
    if(choix == 2)
    {
        system("cls");
        joueur1 = nouveauJoueur(1);
        system("cls");
        joueur2 = nouveauJoueur(2);
    }

    //S'il n'y a qu'un seul nouveau joueur
    else if(choix == 1)
    {
        system("cls");
        joueur1 = nouveauJoueur(1);

        //Saisie du second joueur
        system("cls");
        gotoligcol(2,65);
        std::cout<<"*  JOUEUR 2  *";
        gotoligcol(6,1);
        std::cout<<"Veuillez rentrer votre pseudo : ";

        exist=false;
        while(!exist)
        {
            std::cin >> nom2;
            joueur2 = Joueur();
            joueur2.setNom(nom2);///FAIRE AFFICHAGE
            exist=joueur2.chargerJoueur();
            if(exist == false)
                std::cout << "Le pseudo que vous avez rentre n'existe pas. Resaisissez : ";
        }
        system("cls");

    }

    //S'il n'y a aucun nouveau joueur
    else if(choix == 0)
    {
        //Demander quels joueurs jouent
        system("cls");
        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,88);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"JOUEUR 1";
        gotoligcol(5,1);
        std::cout<<"Veuillez rentrer votre pseudo : ";

        exist=false;
        while(!exist)
        {
            std::cin >> nom1;
            joueur1 = Joueur();
            joueur1.setNom(nom1);
            exist=joueur1.chargerJoueur();
            if(exist == false)
                std::cout << "Le pseudo que vous avez rentre n'existe pas. Resaisissez : ";
        }

        system("cls");
        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,88);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"JOUEUR 2";
        gotoligcol(11,1);
        std::cout<<"Veuillez rentrer votre pseudo : ";

        exist=false;
        while(!exist)
        {
            std::cin >> nom2;
            joueur2 = Joueur();
            joueur2.setNom(nom2);
            exist=joueur2.chargerJoueur();
            if(exist == false)
            std::cout << "Le pseudo que vous avez rentre n'existe pas. Resaisissez : ";
        }
        system("cls");
    }

    ///Selection des decks pour chaque joueur///

    //On remplit le deck du joueur 1 de creatures
    //Parametre = collection de creature de la collection du joueur
    Creature* creaChoisie = new Creature();
    Deck deck = joueur1.getDeck();
    Collection collection = joueur1.getCollection();

    for(int i=4; i>0; i--){

        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,88);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"CHOIX DU DECK";

        gotoligcol(3,1);
        std::cout<<"Joueur : "<<joueur1.getNom();
        gotoligcol(4,1);
        std::cout << "Il vous reste " << i << " cartes creature a selectionner" << std::endl; //affiche le nb de cartes restant a selectionner
        collection.afficherCrea(); //On affiche les cartes
        creaChoisie = collection.choisirCreaCo(); // Le joueur choisit la carte qu'il veut acheter
        deck.ajouter(creaChoisie);//On supprime la carte achetee de la boutique (afin de ne pas avoir 2 cartes avec le meme id)
        collection.supprimerCreature(creaChoisie);
        system("cls");
    }

    system("cls");
    Energie* enerChoisie = new Energie();
    for(int i=4; i>0; i--){

       gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,88);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"CHOIX DU DECK";

        gotoligcol(3,1);
        std::cout<<"Joueur : "<<joueur1.getNom();
        gotoligcol(4,1);
        std::cout << "Il vous reste " << i << " cartes energie a selectionner" << std::endl; //affiche le nb de cartes restant a selectionner
        collection.afficherEner(); //On affiche les cartes
        enerChoisie = collection.choisirEnerCo(); // Le joueur choisit la carte qu'il veut acheter
        deck.ajouter(enerChoisie); //On supprime la carte achetee de la boutique (afin de ne pas avoir 2 cartes avec le meme id)
        collection.supprimerEnergie(enerChoisie);//on supprime la carte de la collection temporaire afin d'afficher seulement les cartes dispo
        system("cls");
    }

    system("cls");


    Speciale* speChoisie = new Speciale();
    for(int i=4; i>0; i--){

        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,88);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"CHOIX DU DECK";

        gotoligcol(3,1);
        std::cout<<"Joueur : "<<joueur1.getNom();
        gotoligcol(4,1);
        std::cout << "Il vous reste " << i << " cartes speciale a selectionner" << std::endl; //affiche le nb de cartes restant a selectionner
        collection.afficherSpe(); //On affiche les cartes
        speChoisie = joueur1.getCollection().choisirSpeCo(); // Le joueur choisit la carte qu'il veut acheter
        deck.ajouter(speChoisie); //On supprime la carte achetee de la boutique (afin de ne pas avoir 2 cartes avec le meme id)
        collection.supprimerSpeciale(speChoisie);
        system("cls");
    }

    joueur1.setDeckC(deck);
    system("cls");

    //Idem pour joueur 2
    Deck deck2 = joueur2.getDeck();
    Collection collection2 = joueur2.getCollection();

    for(int i = 4; i>0; i--){

        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,88);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"CHOIX DU DECK";

        gotoligcol(3,1);
        std::cout<<"Joueur : "<<joueur2.getNom();
        gotoligcol(4,1);;
        std::cout << "Il vous reste " << i << " cartes creature a selectionner" << std::endl; //affiche le nb de cartes restant a selectionner
        collection2.afficherCrea(); //On affiche les cartes
        creaChoisie = collection2.choisirCreaCo(); // Le joueur choisit la carte qu'il veut acheter
        deck2.ajouter(creaChoisie); //On supprime la carte achetee de la boutique (afin de ne pas avoir 2 cartes avec le meme id)
        collection2.supprimerCreature(creaChoisie);
        system("cls");
    }

    system("cls");

    for(int i = 4; i>0; i--){

        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,88);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"CHOIX DU DECK";

        gotoligcol(3,1);
        std::cout<<"Joueur : "<<joueur2.getNom();
        gotoligcol(4,1);
        std::cout << "Il vous reste " << i << " cartes energie a selectionner" << std::endl; //affiche le nb de cartes restant a selectionner
        collection2.afficherEner(); //On affiche les cartes
        enerChoisie = collection2.choisirEnerCo(); // Le joueur choisit la carte qu'il veut acheter
        deck2.ajouter(enerChoisie); //On supprime la carte achetee de la boutique (afin de ne pas avoir 2 cartes avec le meme id)
        collection2.supprimerEnergie(enerChoisie);
        system("cls");
    }
    system("cls");

    for(int i=4; i>0; i--){

        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,88);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"CHOIX DU DECK";

        gotoligcol(3,1);
        std::cout<<"Joueur : "<<joueur2.getNom();
        gotoligcol(4,1);
        std::cout << "Il vous reste " << i << " cartes speciales a selectionner" << std::endl; //affiche le nb de cartes restant a selectionner
        collection2.afficherSpe(); //On affiche les cartes
        speChoisie = collection2.choisirSpeCo(); // Le joueur choisit la carte qu'il veut acheter
        deck2.ajouter(speChoisie); //On supprime la carte achetee de la boutique (afin de ne pas avoir 2 cartes avec le meme id)
        collection2.supprimerSpeciale(speChoisie);
        system("cls");
    }

    joueur2.setDeckC(deck2);
    system("cls");


    //On assigne les joueurs au match
    nouveauMatch.ajouterJoueurs(joueur1, joueur2);

    //Lance le debut du match : joueur qui commence decide aleatoirement, extraction enjeu, initialisation main
    nouveauMatch.start();
    setMatch(nouveauMatch);
    joueur1.sauvegarde();
    joueur2.sauvegarde();
}

/*
Boucle pour les round du match, pose les conditions pour que le jeu continue
pas de parametres ni de retour
*/
void Jeu::matchEnCours(){

    Match onGoingMatch = getMatch(); //On recup le match
    Joueur joueur1;
    Joueur joueur2;
    std::vector<Joueur> joueurs;
    int creaP = 2; //nb de creatures que chaque joueur a dans son deck
    int nul = 0;
    int tours = 0; //nb de tours de jeu au total

    while(joueur1.getLP()!=0 && joueur2.getLP()!=0 && creaP == 2 && tours <= TOURS_MAX && nul == 0)
    {
        joueurs = onGoingMatch.getJoueurs(); //On recup les joueurs
        joueur1 = joueurs[0];
        joueur2 = joueurs[1];
        creaP = onGoingMatch.round();


        //On recupere les decks des joueurs
        /*std::vector<Carte*> deckJ1 = joueur1.getDeck().getCartesD();
        std::vector<Carte*> deckJ2 = joueur2.getDeck().getCartesD();

        ///A corriger, il faut chercher dans le vecteur de vecteur s'il y a une creature
        for(const auto& elem : deckJ1){
            //on compte le nombre de cartes creatures dans le deck du joueur
            if(elem->getGenre() == 2)
                nbCrea1++;
        }

        for(const auto& elem : deckJ2){
            if(elem->getGenre() == 2)
                nbCrea2++;
        }
        */
        tours++; //On incremente a chaque tour de match

        //Si les deux joueurs ne peuvent plus jouer
        if(joueur1.getOut() == true && joueur2.getOut() == true)
        {
            nul = 3;
            std::cout<<"les deux sont biens out"<<std::endl;
        }
        else if(joueur1.getOut() == true)
        {
            nul = 1;
            std::cout << joueur1.getNom() <<" est bien out"<<std::endl;
        }
        else if(joueur2.getOut() == true)
        {
            nul = 2;
            std::cout << joueur2.getNom() <<" est bien out"<<std::endl;
        }
        system("PAUSE");

    //On continue le match tant que les joueurs ont toujours des points de vie, ont toujours des cartes creatures, le nombre de tour n'a pas depasse le nb max de tours

    }




    ///GESTION DU WIN///
    //Si j1 n'a plus de pt de vie ou plus de crea
    if(joueur1.getLP() == 0 || creaP == 0 || nul == 1 ){
        joueur1.setWin(-1); //Le joueur a perdu
        joueur2.setWin(1); //Le joueur a gagne

        system("cls");
        std::cout << joueur2.getNom() <<" a gagne !";
    }

    //j2 n'a plus de pt de vie ou plus de crea
    else if(joueur2.getLP()== 0 || creaP == 1 || nul == 2){
        joueur2.setWin(-1); //loser
        joueur1.setWin(1); //winner !! yay

        system("cls");
        std::cout << joueur1.getNom()<<" a gagne !";
    }

    //jeu trop long => egalite
    else if(tours >= TOURS_MAX || nul == 3) {
        //Aucun joueur ne gagne, aucun joueur ne perd
        joueur1.setWin(0);
        joueur2.setWin(0);

        system("cls");
        std::cout<< "Vous etes a egalite";
    }

    //On actualise les joueurs
    actualiserJoueur(joueur1);
    actualiserJoueur(joueur2);

    setMatch(onGoingMatch);
}

/*
Gestion de l'enjeu apres la fin du match
pas de parametre
pas de retour
*/
void Jeu::finDeMatch(){

Match matchFini=getMatch();
    std::cout<< "Est ce que je plante ici ? " <<std::endl;
    std::vector<Joueur> joueurs = matchFini.getJoueurs();
    Joueur joueur1=joueurs[0];
    Joueur joueur2=joueurs[1];

    std::cout << "WIN DES JOUEURS : "<< std::endl;
    std::cout << joueur1.getNom() << " : " << joueur1.getWin() << std::endl;
    std::cout << joueur2.getNom() << " : " << joueur2.getWin() << std::endl;

    Carte* enjeu1 = new Carte;
    enjeu1 = joueur1.getEnjeu();
    Carte* enjeu2 = new Carte;
    enjeu2 = joueur2.getEnjeu();


    ///GESTION DE L'ENJEU///



    //Si le premier joueur a gagne
    if(joueur1.getWin() == 1) //L'enjeu 1 est deja dans la collection du joueur
    {
        std::cout << joueur1.getNom() << " a gagne " << std::endl;
        //Ajouter l'enjeu dans sa collection
        //Si l'enjeu est une carte energie
       if(enjeu2->getGenre() == 2){



            std::cout << "ENJEU EST ENERGIE" << std::endl;
            //On recupere la collection energie du joueur 2 pour la parcourir
            std::vector<Energie*> collecEner2 = joueur2.getCollection().getcEnergieColl();

            //On recup la collection energie du j1 pour ajouter la carte enjeu
            std::vector<Energie*> collecEner1=joueur1.getCollection().getcEnergieColl();

            Energie* enjeuEner2 = (Energie*) enjeu2;

            collecEner1.push_back(enjeuEner2); //On ajoute la carte enjeu du joueur 2 a la collection du j1
            joueur1.getCollection().setcEnergieColl(collecEner1);


            int it = 0;
            for(const auto& elem : collecEner2){
                //lorsqu'on retrouve la carte enjeu dans la collection du joueur
                if(enjeu2->getIdentifiant() == elem->getIdentifiant()){


                    collecEner2.erase(collecEner2.begin()+it); //Oon supprime la carte de la collection du joueur perdant
                    std::cout << "On supprime enjeu de collection" << std::endl;
                    joueur2.getCollection().setcEnergieColl(collecEner2);

                }

                it++;
            }

       }

       //Si l'enjeu est une carte creature
       else if(enjeu2->getGenre() == 1){



            std::cout << "ENJEU EST CREA" << std::endl;

            std::vector<Creature*> collecCrea1=joueur1.getCollection().getCreatureColl();
            std::vector<Creature*> collecCrea2=joueur2.getCollection().getCreatureColl();

            Creature* enjeuCrea2 = (Creature *) enjeu2;

            collecCrea1.push_back(enjeuCrea2); //On ajoute la carte enjeu du joueur 2 a la collection du j1
            joueur1.getCollection().setCreatureColl(collecCrea1);

            int it = 0;
            for(const auto&elem : collecCrea2){
                if(enjeu2->getIdentifiant() == elem->getIdentifiant())
                {

                    collecCrea2.erase(collecCrea2.begin()+it); //Oon supprime la carte de la collection du joueur perdant
                    joueur2.getCollection().setCreatureColl(collecCrea2);
                    std::cout << "On supprime enjeu de collection" << std::endl;


                }
                it++;
            }
       }

       //Si l'enjeu est une carte speciale
       else if(enjeu2->getGenre()==3){




            std::cout << "ENJEU EST Spe" << std::endl;


            std::vector<Speciale*> collecSpe1=joueur1.getCollection().getSpecialeColl();
            std::vector<Speciale*> collecSpe2=joueur2.getCollection().getSpecialeColl();

            Speciale* enjeuSpe2 = (Speciale*) enjeu2;

            collecSpe1.push_back(enjeuSpe2); //On ajoute la carte enjeu du joueur 2 a la collection du j1
            joueur1.getCollection().setSpecialeColl(collecSpe1);

            int it = 0;
            for(const auto&elem : collecSpe2){
                if(enjeu2->getIdentifiant() == elem->getIdentifiant()){

                    collecSpe2.erase(collecSpe2.begin()+it); //Oon supprime la carte de la collection du joueur perdant
                    joueur2.getCollection().setSpecialeColl(collecSpe2);
                    std::cout << "On supprime enjeu de collection" << std::endl;


                }

                it++;
            }

       }

        joueur1.setCagnotte(joueur1.getCagnotte()+50); //Pour l'instant on ajoute 50 pieces

    }

    //Si le deuxieme joueur est gagnant
    else if(joueur2.getWin() == 1)
    {
        std::cout << joueur2.getNom() << " a gagne " << std::endl;


        //Ajouter l'enjeu dans sa collection
        //Si l'enjeu est une carte energie
       if(enjeu1->getGenre() == 2){

            std::cout << "ENJEU EST ENERGIE" << std::endl;


            //On recupere la collection energie du joueur 1 pour la parcourir
            std::vector<Energie*> collecEner1=joueur1.getCollection().getcEnergieColl();

            //On recup la collection energie du j1 pour ajouter la carte enjeu
            std::vector<Energie*> collecEner2=joueur2.getCollection().getcEnergieColl();

            Energie* enjeuEner1 = (Energie*) enjeu1;


            collecEner2.push_back(enjeuEner1); //On ajoute la carte enjeu du joueur 2 a la collection du j1
            joueur2.getCollection().setcEnergieColl(collecEner2);

            int it = 0;
            for(const auto& elem : collecEner1){
                //lorsqu'on retrouve la carte enjeu dans la collection du joueur
                if(enjeu1->getIdentifiant() == elem->getIdentifiant()){
                    collecEner1.erase(collecEner1.begin()+it); //Oon supprime la carte de la collection du joueur perdant
                    joueur1.getCollection().setcEnergieColl(collecEner1);
                    std::cout << "On supprime enjeu de collection" << std::endl;

                }

                it++;
            }
       }

       //Si l'enjeu est une carte creature
       else if(enjeu1->getGenre() == 1){

            std::cout << "ENJEU EST crea" << std::endl;


            std::vector<Creature*> collecCrea2=joueur2.getCollection().getCreatureColl();
            std::vector<Creature*> collecCrea1=joueur1.getCollection().getCreatureColl();

            Creature* enjeuCrea1 = (Creature *) enjeu1;

            collecCrea2.push_back(enjeuCrea1); //On ajoute la carte enjeu du joueur 2 a la collection du j1
            joueur2.getCollection().setCreatureColl(collecCrea2);

            int it = 0;

            for(const auto&elem : collecCrea1){
                if(enjeu1->getIdentifiant() == elem->getIdentifiant()){
                    collecCrea1.erase(collecCrea1.begin()+it); //Oon supprime la carte de la collection du joueur perdant
                    joueur1.getCollection().setCreatureColl(collecCrea1);


                }

                it++;
            }
       }

       //Si l'enjeu est une carte speciale
       else if(enjeu1->getGenre() == 3){



            std::cout << "ENJEU EST spe" << std::endl;

            std::vector<Speciale*> collecSpe2=joueur2.getCollection().getSpecialeColl();
            std::vector<Speciale*> collecSpe1=joueur1.getCollection().getSpecialeColl();

            Speciale* enjeuSpe1 = (Speciale*) enjeu1;

            collecSpe2.push_back(enjeuSpe1); //On ajoute la carte enjeu du joueur 2 a la collection du j1
            joueur2.getCollection().setSpecialeColl(collecSpe2);

            int it = 0;
            for(const auto&elem : collecSpe1){
                if(enjeu1->getIdentifiant() == elem->getIdentifiant()){
                    collecSpe1.erase(collecSpe1.begin()+it); //Oon supprime la carte de la collection du joueur perdant
                    joueur1.getCollection().setSpecialeColl(collecSpe1);



                }

                it++;
            }
       }

        joueur2.setCagnotte(joueur1.getCagnotte()+50);

    }


    ///MAJ JOUEURS///

    Deck deck1 = joueur1.getDeck();
    Deck deck2 = joueur2.getDeck();

    //Les decks et la main des joueurs sont supprimes
    deck1.supprimer();
    deck2.supprimer();

    joueur1.setDeckC(deck1);
    joueur2.setDeckC(deck2);



    actualiserJoueur(joueur1);
    actualiserJoueur(joueur2);




    ///MAJ MATCH///

    //On enleve les joueurs du match
    matchFini.supprimerJoueurs();


    matchFini.getCimetiere().supprimer(); //On vide le cimetiere du match

    setMatch(matchFini);


}

/*
Lance toutes les methodes concernant le match
pas de parametre, pas de retour
*/
void Jeu::match(){
    lancerMatch();
    matchEnCours();
    finDeMatch();
}

/*
ouvre la boutique lorsqu'un joueur le demande
Pas de parametre, pas de retour
*/
void Jeu::lancerBoutique(){
    Creature* creaAchetee=new Creature;
    Energie* enerAchetee=new Energie;
    Speciale* speAchetee=new Speciale;

    Joueur joueur; //Joueur qui souhaite acheter des cartes
    std::string pseudo;
    Collection collection;

    Boutique shop=getBoutique();
    std::vector<Joueur> listeJoueurs=getJoueurs();


    bool exist;//permet de savoir si le pseudo rentre existe
    int choix;

    std::cout<< "Veuillez rentrer votre pseudo : ";
    std::cin.ignore();
    exist=false;
        while(!exist)
        {
            std::cin>>pseudo;

            joueur=Joueur();
            joueur.setNom(pseudo);
            exist=joueur.chargerJoueur();

            if(exist == false) std::cout << "Le pseudo que vous avez rentre n'existe pas. Resaisissez : ";
        }
        system("cls");

    collection=joueur.getCollection();


    ///MENU
     do
    {
        gotoligcol(12,60);
        std::cout<<"________________________________________________";//affichage du menu centré sur l'écran
        gotoligcol(15,70);
        std::cout<<"* Bienvenue dans la Boutique *";
        gotoligcol(18,70);
        std::cout << "Que voulez vous acheter ? ";
        gotoligcol(20,70);
        std::cout << "1. Cartes creatures";
        gotoligcol(22,70);
        std::cout<< "2. Cartes Energies";
        gotoligcol(24,70);
        std::cout<< "3. Cartes Speciales" ;
        gotoligcol(27,60);
        std::cout<<"________________________________________________";
        gotoligcol(30,63);
        std::cout<< "Entrez votre choix : ";
        std::cin >> choix;
        if(std::cin.fail())
        {
            system("cls");
            gotoligcol(29,63);
            std::cerr << "Erreur, saisie incorrecte." << std::endl;

            vider_buffer(); // On remet cin dans un état valide et vide le buffer
        }
        else if(choix > 3 || choix < 1)
        {
            system("cls");
            gotoligcol(29,63);
            std::cout << "Veuillez rentrer une valeur entre 1 et 3 svp";
        }

    }while(choix>3 || choix<1);

    //Boutique de cartes creatures
    if(choix == 1){
        shop.afficherCrea(); //On affiche les cartes
        creaAchetee = shop.choisirCrea(); // Le joueur choisit la carte qu'il veut acheter
        shop.supprimerCarteCrea(creaAchetee); //On supprime la carte achetee de la boutique

        joueur.setCagnotte(joueur.getCagnotte()-creaAchetee->getPrix()); // On met a jour la cagnotte du joueur
        collection.ajouterCreature(creaAchetee); //On ajoute la carte dans la collection du joueur
        joueur.setCollection(collection);
    }

    //Boutique de cartes energies
    if(choix == 2){
        shop.afficherEner();
        enerAchetee = shop.choisirEner();
        shop.supprimerCarteEner(enerAchetee);

        joueur.setCagnotte(joueur.getCagnotte()-enerAchetee->getPrix());
        collection.ajouterEnergie(enerAchetee);
        joueur.setCollection(collection);
    }

    //Boutique de cartes speciales
    if(choix == 3)
    {
        shop.afficherSpe();
        speAchetee = shop.choisirSpe();
        shop.supprimerCarteSpe(speAchetee);

        joueur.setCagnotte(joueur.getCagnotte()-speAchetee->getPrix());
        collection.ajouterSpeciale(speAchetee);
        joueur.setCollection(collection);
    }

    setBoutique(shop);
    joueur.sauvegarde();
    //actualiserJoueur(joueur); //On actualise car collection modifiee
}


/*
Si il y a un nouveau joueur
Pas de parametre
Retourne le nouveau joueur cree
*/
Joueur Jeu::nouveauJoueur(int i)
{
    Joueur newJ; //Win, LP et cagnotte initialises par defaut a 0, 2000 et 100 respectivement
    std::string pseudo;
    bool dispo;
    std::vector<Joueur> joueurs=getJoueurs();

    Collection collection;

    Boutique shop=getBoutique();
    std::vector<Joueur> listeJoueurs=getJoueurs();

    Creature* creaAchetee=new Creature;
    Energie* enerAchetee=new Energie;
    Speciale* speAchetee=new Speciale;

    ///Choix du pseudo///

    gotoligcol(5,1);
    std::cout<< "Quel est votre pseudo ? ";

    do
    {
        gotoligcol(2,65);
        std::cout<<"*  JOUEUR "<<i<<"  *";
        gotoligcol(5,30);
        dispo=true; //Par defaut le pseudo n'est pas utilise
        std::cin >> pseudo;
        for(const auto elem : joueurs)
        {
            if(pseudo == elem.getNom())
                dispo=false; //Si ce pseudo est deja pris on fais en sorte que l'utilisateur resaisisse
        }
        if(dispo == false)
        {
           system("cls");
           gotoligcol(5,1);
           std::cout<< "Ce pseudo est deja utilise... Choisissez en un autre : ";
        }

    }
    while(dispo!=true);

    system("cls");

    newJ.setNom(pseudo);

    ///choix de la collection///
    ///On utilise la boutique///

    //CREATURES
    //La boucle force le joueur a choisir un nombre definit de cartes pour chaque type

    for(int i=4; i>0; i--){

        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,91);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"CHOIX DE LA COLLECTION";

        gotoligcol(45,1);
        std::cout<<"Joueur : "<<newJ.getNom();
        gotoligcol(46,1);
        std::cout << "Il vous reste " << i << " cartes creature a selectionner" << std::endl; //affiche le nb de cartes restant a selectionner
        shop.afficherCrea(); //On affiche les cartes
        creaAchetee = shop.choisirCrea(); // Le joueur choisit la carte qu'il veut acheter
        shop.supprimerCarteCrea(creaAchetee); //On supprime la carte achetee de la boutique (afin de ne pas avoir 2 cartes avec le meme id)

        newJ.setCagnotte(newJ.getCagnotte()-creaAchetee->getPrix()); // On met a jour la cagnotte du joueur
        collection.ajouterCreature(creaAchetee); //On ajoute la carte dans la collection du joueur
        newJ.setCollection(collection);

        system("cls");

    }


    //ENERGIES
    for(int i=4; i>0; i--){

        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,91);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"CHOIX DE LA COLLECTION";

        gotoligcol(30,1);
        std::cout<<"Joueur : "<<newJ.getNom();
        gotoligcol(31,1);
        std::cout << "Il vous reste " << i << " cartes energie a selectionner" << std::endl;

        shop.afficherEner(); //On affiche les cartes
        enerAchetee = shop.choisirEner(); // Le joueur choisit la carte qu'il veut acheter
        shop.supprimerCarteEner(enerAchetee); //On supprime la carte achetee de la boutique (afin de ne pas avoir 2 cartes avec le meme id

        newJ.setCagnotte(newJ.getCagnotte()-enerAchetee->getPrix()); // On met a jour la cagnotte du joueur
        collection.ajouterEnergie(enerAchetee); //On ajoute la carte dans la collection du joueur
        newJ.setCollection(collection);
        system("cls"); //Pour effacer la console apres affichage

    }

    //SPECIALES

    for(int i=4; i>0; i--){

        gotoligcol(2,63);
        std::cout<<"*";
        gotoligcol(2,91);
        std::cout<<"*";
        gotoligcol(2,66);
        std::cout<<"CHOIX DE LA COLLECTION";

        gotoligcol(30,1);
        std::cout<<"Joueur : " << newJ.getNom();
        gotoligcol(31,1);
        std::cout << "Il vous reste " << i << " cartes speciales a selectionner" << std::endl;
        shop.afficherSpe(); //On affiche les cartes
        speAchetee = shop.choisirSpe(); // Le joueur choisit la carte qu'il veut acheter
        shop.supprimerCarteSpe(speAchetee); //On supprime la carte achetee de la boutique (afin de ne pas avoir 2 cartes avec le meme id)

        newJ.setCagnotte(newJ.getCagnotte()- speAchetee->getPrix()); // On met a jour la cagnotte du joueur
        collection.ajouterSpeciale(speAchetee); //On ajoute la carte dans la collection du joueur
        newJ.setCollection(collection);
        system("cls");

    }

    //On actualise la boutique car on a supprime les cartes achetee
    setBoutique(shop);

    ajouterNouvJoueur(newJ); //On ajoute le nouveau joueur a la liste de tous les joueurs qui on deja ete crees

    return newJ;
}



///ACCESSEURS

void Jeu::setMatch(Match match)
{
    m_match=match;
}

Match Jeu::getMatch()const{
    return m_match;
}

void Jeu::setBoutique(Boutique boutique){
    m_boutique=boutique;
}

std::vector<Joueur> Jeu::getJoueurs()
{
    return m_joueurs;
}

void Jeu::setJoueurs(std::vector<Joueur> joueurs){
    m_joueurs=joueurs;
}

Boutique Jeu::getBoutique()const
{
    return m_boutique;
}

/*
Actualise le joueur
parametre : joueur actualise
pas de retour
*/
void Jeu::actualiserJoueur(Joueur joueur){
    std::vector<Joueur> joueurs = getJoueurs();
    int position=0;

    for(const auto& elem : joueurs){
        if(elem.getNom() == joueur.getNom())
        {
            joueurs.erase(joueurs.begin()+position); //on supprime l'ancienne version du joueur
            joueurs.push_back(joueur); //on ajoute la version du joueur actualisee
        }

        position++;
    }

    setJoueurs(joueurs);
}

/*
ajoute un nouveau joueur
parametre : nouveau joueur
pas de retour
*/
void Jeu::ajouterNouvJoueur(Joueur nouveauJoueur){

    std::vector<Joueur> joueurs=getJoueurs();

    joueurs.push_back(nouveauJoueur); //on ajoute le joueur

    setJoueurs(joueurs);

}
