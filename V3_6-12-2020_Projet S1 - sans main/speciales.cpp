#include "speciales.h"
#include "creature.h"

///Genres des cartes speciales :
//3 : spe1... 8 : spe6


/////////////////////////////
///METHODES CARTE SPECIALE///
/////////////////////////////


//Constructeurs

Speciale::Speciale(int cycle,std::string nom, std::string description, bool pioche, int prix, int quantite, int identifiant, int type_spe)
    :Carte(nom,description, prix,3, quantite,identifiant),m_cycleVie(cycle),m_pioche(pioche), m_type_spe(type_spe)
{}

Speciale::Speciale() {}


Speciale::~Speciale()
{

}
///Accesseurs

int Speciale::getCycle()const
{
    return m_cycleVie;
}

bool Speciale::getBool()const
{
    return m_pioche;
}
int Speciale::getTypeSpe()const
{
    return m_type_spe;
}
void Speciale::setCycle(int cycle)
{
    if(cycle>=0) m_cycleVie=cycle;
}

void Speciale::setBool(bool pioche)
{
    m_pioche=pioche;
}


///////////////////////////////
///METHODES CARTES SPECIALES///
///////////////////////////////


/*
Fonction a utiliser dans la boucle de jeu, 1 fois par tour
Pas de parametres
Valeur de retour permet de prevenir la fonction finDeVie qu'il faut ranger la carte
*/
int Speciale::cycleVie()
{
    //Tant que la carte speciale n'est pas expiree, on utilise son pouvoir
    int alerteFin=0;
    if(getCycle()!=0)
    {
        //pouvoir();
        setCycle(getCycle()-1);
    }

    else if(getCycle()==0)
    {
        std::cout << "carte expiree" << std::endl;
        alerteFin=1;
        ///On peut peut-etre utiliser une variable a retourner dans la boucle de jeu pour savoir quand
        ///remettre carte dans la pioche ou dans cimetiere ???
    }

    return alerteFin;
}

void Speciale::afficher(int lig, int col)
{
    gotoligcol(lig,col);
    std::cout<<"*******************************";
    gotoligcol(lig+1,col);
    std::cout<<"\t"<<getNom();
    gotoligcol(lig+2,col);
    std::cout<<"*******************************";
    gotoligcol(lig+3,col);
    std::cout<<"Id : " << getIdentifiant();///modif
    gotoligcol(lig+4,col);
    std::cout<<getDescription();
    gotoligcol(lig+5,col);
    std::cout<<"Cycle de vie : "<<getCycle();
}

/*
Fonction a utiliser une fois que cycle de vie termine, permet de ranger ou jeter la carte
Parametres : le deck, le cimetiere et la variable qui previent la fonction que la carte est morte et donc a ranger
Retourne le conteneur, soit le deck soit le cimetiere, qui a ete modifie
*/
std::vector<Carte*> Speciale::finDeVie(std::vector<Carte*> deck, std::vector<Carte*> cimetiere, int alerte)
{
    std::vector <Carte*> tmp;
    Speciale* carteObj = new Speciale(getCycle(), getNom(),getDescription(),getBool(), getPrix(),getQuantite(), getIdentifiant(), getTypeSpe()); //Contient l'objet

    //condition permettant de verifier que la carte est bien morte
    if(alerte==1)
    {
        //Si la carte  doit retourner dans la pioche lorsqu'elle a fini son cycle de vie
        if(getBool()==true)
        {
            deck.push_back(carteObj); //On ajoute l'objet au deck
            tmp=deck; //permet de retourner le deck
        }

        //Si la carte doit aller dans le cimetiere a la fin de son cycle de vie
        else if(getBool()==false)
        {
            cimetiere.push_back(carteObj); //on ajoute l'objet au cimetiere
            tmp=cimetiere; //permet de retourner le cimetiere
        }
    }
    return tmp;
}



/*
Permet de retourner l'attaque de l'adversaire contre lui meme
Parametres :
crea_A = creature qui attaque et qui va subir le pouvoir de la carte
attaque = attaque de la crea_A
Retourne la carte modifiee
*/
Creature* Speciale::pouvoir1(Creature* crea_A, Attaque attaque)
{
    crea_A->setLP(crea_A->getLP()-attaque.getHp()); //L'attaque de crea A se retourne contre elle
    return crea_A;
}



/*
Le joueur recupere 10 LP
*/

/*Joueur* Speciale::pouvoir2(Joueur* joueur)
{
    joueur->setLP(joueur->getLP()+10); //adapter les pts de vie a rajouter en fct de pt de vie de base de la creature
    //ou ajouter pt de vie en fct de pt de vie actuels maybe ?

    return creature;
}*/


/*
On choisit la carte que l'on veut joueur, on deroule les 3 premieres cartes du deck, et lire la selection du joueur
Parametre : vecteur de carte : deck du joueur qui a joue la carte speciale
Retour : carte selectionnee par le joueur
*/
Carte* Speciale::pouvoir2(std::vector <Carte*> deck)
{
    //Afficher toutes les cartes
    //choisir carte de notre choix a jouer, dans la pioche
    //condition : passer un tour ?

    srand(time(NULL));
    int alea=rand()%deck.size(); //Random qui va permettre de recuperer une carte dans le cimetiere
    int j=0;
    Carte* selec = new Carte;

    for(const auto elem : deck)
    {

        if(j == alea)
        {
            selec = elem; //on recupere une carte aleatoire dans le cimetiere
        }
        j++;
    }

    //affichage des 3 premieres cartes

    return selec;
}


/*
Fonction qui permet de recuperer une carte aleatoire du cimetiere
parametre : vecteur de carte = le cimetiere
retour : carte recuperee aleatoirement dans le cimetiere
*/
Carte* Speciale :: pouvoir3(std::vector<Carte*> cimetiere)
{
    ///ATTENTION : Supprimer la carte retournee du cimetiere en dehors du ss prog si on veut eviter les pointeurs...

    srand(time(NULL));
    int alea=rand()%cimetiere.size(); //Random qui va permettre de recuperer une carte dans le cimetiere
    int j=0;
    Carte* selec = new Carte;

    for(const auto elem : cimetiere)
    {

        if(j == alea)
        {
            selec = elem; //on recupere une carte aleatoire dans le cimetiere
        }
        j++;
    }


    return selec; // et on la retourne
}


/*
permet de rajouter des pts de vie a la creature en jeu du joueur
parametre : creature en question
Retour : creature en question avec plus de pv
*/
Creature* Speciale::pouvoir4(Creature* creature)
{
    creature->setLP(creature->getLP()+10); //adapter les pts de vie a rajouter en fct de pt de vie de base de la creature
    //ou ajouter pt de vie en fct de pt de vie actuels maybe ?

    return creature;
}


/*
La carte retournee est a ajouter au cimetiere et a retirer du deck de l'adversaire
Parametre : deck = deck de l'adversaire
retour : Carte selectionne aleatoirement a envoyer au cimetiere
*/
Carte* Speciale::pouvoir6(std::vector<Carte*> deck)
{
    srand(time(NULL));

    int alea=rand()%deck.size(); //Random qui va permettre de recuperer une carte dans le deck
    int j=0;
    Carte* selec = new Carte; //Carte selectionnee par la variable alea

    for(const auto elem : deck)
    {
        if(j==alea)
        {
            selec = elem; //On recupere une carte au hasard
        }

        j++;
    }

    return selec; // et on la retourne
}


