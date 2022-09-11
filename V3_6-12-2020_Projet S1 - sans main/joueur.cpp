#include "joueur.h"

///Constructeurs

Joueur::Joueur(): m_win(0), m_cagnotte(100), m_LP(2000), m_out(false)
{

}

Joueur::Joueur(std::string nom):m_nom(nom)
{
    m_LP=200;
    recupCollection();
}

Joueur::Joueur(std::string nom,int cagnotte)
    :m_nom(nom), m_cagnotte(cagnotte)
{
    m_LP=2000;
    m_collection=Collection();
}


///Destructeur
Joueur::~Joueur()
{

}


///Accesseurs

int Joueur::getWin()const
{
    return m_win;
}

void Joueur::setWin(int win)
{
    m_win=win;
}

std::string Joueur::getNom()const
{
    return m_nom;
}
void Joueur::setNom(std::string nom)
{
    m_nom=nom;
}

Deck Joueur::getDeck()
{
    return m_deck;
}
void Joueur::setDeck(std::vector <Carte*> deck)
{
    m_deck.setCartesD(deck);
}

void Joueur::setDeckC(Deck deck)
{
    m_deck = deck;
}

bool Joueur::getTurn()const
{
    return m_turn;
}
void Joueur::setTurn(bool turn)
{
    m_turn=turn;
}

int Joueur::getCagnotte()const
{
    return m_cagnotte;
}

void Joueur::setCagnotte(int cagnotte)
{
    m_cagnotte=cagnotte;
}

std::vector <Carte*> Joueur::getMain()const
{
    return m_main;
}

void Joueur::setMain(std::vector <Carte*> main)
{
    m_main=main;
}

int Joueur::getLP()const
{
    return m_LP;
}

void Joueur::setLP(int LP)
{
    m_LP=LP;
}

Collection Joueur::getCollection()const
{
    return m_collection;
}

void Joueur::setCollection(Collection collection)
{
    m_collection=collection;
}

Carte* Joueur::getEnjeu()const
{
    return m_enjeu;
}

void Joueur::setEnjeu(Carte* enjeu)
{
    m_enjeu=enjeu;
}

bool Joueur::getOut()const{
    return m_out;
}

void Joueur :: setOut(bool out){
    m_out = out;
}


Carte * Joueur::createCarte(int identifiant)
{
    int QUANTITE = 1;
    if(identifiant>=0 && identifiant <50)
    {
        Creature* ptr = new Creature("Bloom", "Gardiene de la flamme du dragon", 15, 110, "Feu",QUANTITE,identifiant);
        ptr->ajouter("Feu du Dragon", 2, "Feu", 25);
        ptr->ajouter("Dragon Kick", 1, "Feu", 15);
        return ptr;
    }
    else if(identifiant>=50 && identifiant <100)
    {
        Creature* ptr = new Creature("Stella", "Princesse du royaume du soleil", 15, 80, "Lumiere",QUANTITE,identifiant);
        ptr->ajouter("Lumiere de Solaria", 2, "Lumiere", 35);
        ptr->ajouter("Explosion solaire", 1, "Lumiere", 20);
        return ptr;
    }
    else if(identifiant>=100 && identifiant <150)
    {
        Creature* ptr = new Creature("Tecna", "Genie de la technologie", 15, 120, "Technologie",QUANTITE,identifiant);
        ptr->ajouter("Explosion Technologique", 2, "Technologie", 30);
        ptr->ajouter("Rayon Laser", 1, "Technologie", 15);
        return ptr;
    }
    else if(identifiant>=150 && identifiant <200)
    {
        Creature* ptr = new Creature("Flora", "Meilleure amie de la nature", 15, 150,"Terre",QUANTITE,identifiant);
        ptr->ajouter("Tremblement", 2, "Terre", 15);
        ptr->ajouter("Lianes Sauvages", 1, "Terre", 10);
        return ptr;
    }
    else if(identifiant>=200 && identifiant <250)
    {
        Creature* ptr = new Creature("Musa","Fee de la musique", 25, 140, "Technologie",QUANTITE,identifiant);
        ptr->ajouter("Mega sound", 2, "Technologie", 30);
        ptr->ajouter("Attaque d'ultrason", 1, "Technologie", 10);
        return ptr;
    }
    else if(identifiant>=250 && identifiant <300)
    {
        Creature* ptr = new Creature("Leila", "Reine du plasma", 35, 90, "Terre",QUANTITE,identifiant);
        ptr->ajouter("Attaque plasmique", 2, "Terre", 40);
        ptr->ajouter("Flux d'eau courante", 1, "Terre", 10);
        return ptr;
    }
    else if(identifiant>=300 && identifiant <350)
    {
        Creature* ptr = new Creature("Roxy", "Fee des animaux", 45, 100, "Feu",QUANTITE,identifiant);
        ptr->ajouter("Attaque de l'ours", 3, "Feu", 60);
        ptr->ajouter("Chant de l'aigle", 1, "Feu", 20);
        return ptr;
    }
    else if(identifiant>=350 && identifiant <400)
    {
        Energie* ptr = new Energie("Source d'energie", "Energie fournie par la technologie", 5, 1, 15, "Technologie",QUANTITE,identifiant);
        return ptr;
    }
    else if(identifiant>=400 && identifiant <450)
    {
        Energie* ptr = new Energie("Source d'energie", "Energie fournie par la nature", 5,1,2,"Terre",QUANTITE,identifiant);
        return ptr;
    }
    else if(identifiant>=450 && identifiant <500)
    {
        Energie* ptr = new Energie("Source d'energie", "Energie fournie par la lumiere", 5,1,14,"Lumiere",QUANTITE,identifiant);
        return ptr;
    }
    else if(identifiant>=500 && identifiant <550)
    {
        Energie* ptr = new Energie("Source d'energie", "Energie fournie par le feu", 5,1,4,"Feu",QUANTITE,identifiant);
        return ptr;
    }
    else if(identifiant>=550 && identifiant <600)
    {
        Speciale* ptr = new Speciale(0,"Spe1","Auto-Hit", true, 5,QUANTITE,identifiant,1);
        return ptr;
    }
    else if(identifiant>=600 && identifiant <650)
    {
        Speciale* ptr = new Speciale(1,"Spe2","Vol à l'adversaire", true, 3,QUANTITE,identifiant,2);
        return ptr;
    }
    else if(identifiant>=650 && identifiant <700)
    {
        Speciale* ptr = new Speciale(0,"Spe3","Recupere une carte du cimetiere", true, 3,QUANTITE,identifiant,3);
        return ptr;
    }
    else if(identifiant>=700 && identifiant <750)
    {
        Speciale* ptr = new Speciale(2,"Spe4","Soigne une creature", true, 5,QUANTITE, identifiant,4);
        return ptr;
    }
    else if(identifiant>=750 && identifiant <800)
    {
        Speciale* ptr = new Speciale(1,"spe5","Immunise", true, 5,QUANTITE, identifiant,5);
        return ptr;
    }
    else if(identifiant>=800 && identifiant <850)
    {
        Speciale* ptr = new Speciale(0,"Spe6","Fait perdre une carte a l'adversaire", true,3,QUANTITE, identifiant,6);
        return ptr;
    }
    else
    {
        Carte * ptr = NULL;
        return ptr;
    }

}


/*
Charge les informations du joueur dans le fichier game
pas de parametre
Retour : la collection chargee du joueur
*/
bool Joueur::chargerJoueur()
{
    bool existe=false;
    std::ifstream game("game.txt");
    std::string s;
    std::vector <Carte*> Lista;
    m_collection=Collection();
    std::vector <Creature*> LC;
    std::vector <Energie*> LE;
    std::vector <Speciale*> LS;
    while(std::getline(game, s))
    {
        std::string n=s.substr(0,s.find("="));
        if(n==m_nom)
        {
            existe=true;
            std::string m=s.substr(s.find("=")+1,100000000);
            std::string o=m.substr(0, m.find(";"));
            std::string coin=m.substr(m.find(";")+1, 100000000);
            std::cout<< o<<std::endl<<coin<<std::endl;

            std::string delimiter = ",";

            size_t pos = 0;
            std::string token;
            while ((pos = o.find(delimiter)) != std::string::npos)
            {
                token = o.substr(0, pos);
                Carte* c_token = createCarte(std::stoi(token));
                /*      CONTROLLARE TIPO DELLA CARTE E AGGIUNGERLA NEL VETTORE CORRISPONDENTE */
                //std::cout << "genere: " << c_token->getNom() << "\t" << c_token->getGenre()<< std::endl;
                switch(c_token->getGenre())
                {

                case 1:
                {
                    Creature * crea = (Creature * ) c_token;
                    Collection tmp = getCollection();
                    tmp.ajouterCreature(crea);
                    setCollection(tmp);
                    break;
                }

                case 2:
                {
                    Energie* ene=(Energie*) c_token;
                    m_collection.ajouterEnergie(ene);
                    break;
                }

                case 3:
                {
                    Speciale* spe=(Speciale*) c_token;
                    m_collection.ajouterSpeciale(spe);
                    break;
                }

                }

                o.erase(0, pos + 1);
            }
            break;
            //std::cout << o << std::endl;
        }
    }
    game.close();
    return existe;
}

/*
assigne au joueur la collection chargee dans chargerJoueur
pas de parametre, pas de retour
*/
void Joueur::recupCollection()
{
    m_collection=Collection();
    //m_collection.setCollection(chargerJoueur());
}
/*
Sauvegarde les informations du joueur
pas de parametre, pas de retour
*/
void Joueur::sauvegarde()
{

    std::string sFinale;
    std::string StringCollection="";
    std::vector <Carte*> c=m_collection.getCollection();
    for(unsigned int i=0; i<c.size(); i++)
    {
        StringCollection+=std::to_string(c[i]->getIdentifiant())+","; //additionne tous les identifiants avec virgules
    }
    sFinale=m_nom+"="+StringCollection+ ";"+std::to_string(m_cagnotte); //additionne nom du joueur, =, identifiants des cartes ; cagnotte
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
        if(n==m_nom)
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

/*
On supprime la main et le deck du joueur une fois le match termine
Pas de parametre ni de retour
*/
void Joueur::supprimerM_D()
{

    ///Main
    int i=0;
    std::vector<Carte*> main = getMain();
    while(!main.empty())
    {
        main.erase(main.begin()+i);
        i++;
    }

    //On redonne au joueur une main vide
    setMain(main);


    ///Deck
    getDeck().supprimer(); //Bug dans ma tete est ce que besoin de faire un set

}

/*
Surcharge operateur comparaison pour comparer des joueurs
Parametres : references sur les deux objets compares
Retour : booleen permettant de savoir si les deux objets sont egaux
*/
bool operator==(Joueur const& a, Joueur const& b)
{
    //La comparaison des noms suffit car la saisie des pseudos est blindes pour ne pas avoir de doublon
    if(a.getNom()== b.getNom())
    {
        return true;
    }

    else
    {
        return false;
    }
}
