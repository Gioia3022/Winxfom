#include "deck.h"


//Constructeur
Deck::Deck() {}

//Destructeur
Deck::~Deck()
{

}

///accesseurs

int Deck::getTaille() const
{
    return m_taille;
}

std::vector <Carte*> Deck::getCartesD() const
{
    return m_cartesD;
}

void Deck::setCartesD(std::vector<Carte*> cartesD)
{
    m_cartesD = cartesD;
}


/*
Permet au joueur de selectionner les cartes avec lesquelles il va jouer parmis sa collection
Prend la collection du joueur en parametre
*/
/*
void Deck::remplirDeckCrea(std::vector <Creature*> creaturecoll)
{
    int i = 0;
    int compteur = getTaille();//compteur pour afficher le nombre restant de carte a selectionner
    int selection [getTaille()];//tableau pour recuperer tous les choix du joueur
    std::vector <Carte*> cartesD = getCartesD();
    bool existante = false; // permet d'afficher un message d'erreur si le joueur rentre un numero de carte inexistant

    std::cout << "Veuillez entrer les numeros des cartes que vous souhaitez selectionner :" << std::endl;
    std::cout<<"Appuyer sur entrer pour valider vos choix"<<std::endl;

    gotoligcol(2,5);// pour ecrire a un endroit bien precis sur la console et reecrire le compteur toujours au meme endroit il faudra modifier les coordonnees
    std::cout<<"Il vous reste "<<compteur<<" cartes  a selectionner"<<std::endl;

    for(int j=0; j<getTaille(); j++)//Permet de recuperer toutes les valeurs entrees par l'utilisateur dans le tableau
    {
        std::cin >> selection[j];
        if(std::cin.fail())
        {
            std::cerr << "Saisie incorrecte, veuillez recommencer" << std::endl;

            vider_buffer(); // On remet cin dans un état valide et vide le buffer

        }
        else
        {
            for(const auto& elem : creaturecoll)
            {

                if(selection[j] == elem->getIdentifiant()) //Si on est arrive au niveau de l'indice de la carte choisie on recupere la carte choisie
                {
                    cartesD.push_back(elem);//on ajoute la carte au deck
                    compteur--;
                    existante = true;
                    if(compteur == 0)//previent l'utilisateur quand toutes les cartes ont ete selectionnees
                    {
                        gotoligcol(2,5);// pour ecrire a un endroit bien precis sur la console et reecrire le compteur toujours au meme endroit
                        std::cout<<"Vous avez selectionne toutes vos cartes!"<<std::endl;
                    }
                    else
                    {
                        gotoligcol(2,5);// pour ecrire a un endroit bien precis sur la console et reecrire le compteur toujours au meme endroit
                        std::cout << "Il vous reste "<<compteur<<" cartes a selectionner" << std::endl;
                    }
                }
                i++;
            }
            if(existante == false)
            {
                std::cout << "Numero de carte invalide! Veuillez saisir un nouveau numero de carte :" << std::endl;
            }
        }

    }
    setCartesD(cartesD);

}*/


/*void Deck::remplirDeckEner(std::vector <Energie*> energiecoll)
{
    int i = 0;
    int compteur = getTaille();//compteur pour afficher le nombre restant de carte a selectionner
    int selection [getTaille()];//tableau pour recuperer tous les choix du joueur
    std::vector <Carte*> cartesD = getCartesD();
    bool existante = false; // permet d'afficher un message d'erreur si le joueur rentre un numero de carte inexistant

    std::cout << "Veuillez entrer les numeros des cartes que vous souhaitez selectionner :" << std::endl;
    std::cout<<"Appuyer sur entrer pour valider vos choix"<<std::endl;

    gotoligcol(2,5);// pour ecrire a un endroit bien precis sur la console et reecrire le compteur toujours au meme endroit il faudra modifier les coordonnees
    std::cout<<"Il vous reste "<<compteur<<" cartes  a selectionner"<<std::endl;

    for(int j=0; j<getTaille(); j++)//Permet de recuperer toutes les valeurs entrees par l'utilisateur dans le tableau
    {
        std::cin >> selection[j];
        if(std::cin.fail())
        {
            std::cerr << "Saisie incorrecte, veuillez recommencer" << std::endl;

            vider_buffer(); // On remet cin dans un état valide et vide le buffer

        }
        else
        {
            for(const auto& elem : energiecoll)
            {

                if(selection[j] == elem->getIdentifiant()) //Si on est arrive au niveau de l'indice de la carte choisie on recupere la carte choisie
                {
                    cartesD.push_back(elem);//on ajoute la carte au deck
                    compteur--;
                    existante = true;
                    if(compteur == 0)//previent l'utilisateur quand toutes les cartes ont ete selectionnees
                    {
                        gotoligcol(2,5);// pour ecrire a un endroit bien precis sur la console et reecrire le compteur toujours au meme endroit
                        std::cout<<"Vous avez selectionne toutes vos cartes!"<<std::endl;
                    }
                    else
                    {
                        gotoligcol(2,5);// pour ecrire a un endroit bien precis sur la console et reecrire le compteur toujours au meme endroit
                        std::cout << "Il vous reste "<<compteur<<" cartes a selectionner" << std::endl;
                    }
                }
                i++;
            }
            if(existante == false)
            {
                std::cout << "Numero de carte invalide! Veuillez saisir un nouveau numero de carte :" << std::endl;
            }
        }

    }
    setCartesD(cartesD);

}

void Deck::remplirDeckSpec(std::vector <Speciale*> specialecoll)
{
    int i = 0;
    int compteur = getTaille();//compteur pour afficher le nombre restant de carte a selectionner
    int selection [getTaille()];//tableau pour recuperer tous les choix du joueur
    std::vector <Carte*> cartesD = getCartesD();
    bool existante = false; // permet d'afficher un message d'erreur si le joueur rentre un numero de carte inexistant

    std::cout << "Veuillez entrer les numeros des cartes que vous souhaitez selectionner :" << std::endl;
    std::cout<<"Appuyer sur entrer pour valider vos choix"<<std::endl;

    gotoligcol(2,5);// pour ecrire a un endroit bien precis sur la console et reecrire le compteur toujours au meme endroit il faudra modifier les coordonnees
    std::cout<<"Il vous reste "<<compteur<<" cartes  a selectionner"<<std::endl;

    for(int j=0; j<getTaille(); j++)//Permet de recuperer toutes les valeurs entrees par l'utilisateur dans le tableau
    {
        std::cin >> selection[j];
        if(std::cin.fail())
        {
            std::cerr << "Saisie incorrecte, veuillez recommencer" << std::endl;

            vider_buffer(); // On remet cin dans un état valide et vide le buffer

        }
        else
        {
            for(const auto& elem : specialecoll)
            {

                if(selection[j] == elem->getIdentifiant()) //Si on est arrive au niveau de l'indice de la carte choisie on recupere la carte choisie
                {
                    cartesD.push_back(elem);//on ajoute la carte au deck
                    compteur--;
                    existante = true;
                    if(compteur == 0)//previent l'utilisateur quand toutes les cartes ont ete selectionnees
                    {
                        gotoligcol(2,5);// pour ecrire a un endroit bien precis sur la console et reecrire le compteur toujours au meme endroit
                        std::cout<<"Vous avez selectionne toutes vos cartes!"<<std::endl;
                    }
                    else
                    {
                        gotoligcol(2,5);// pour ecrire a un endroit bien precis sur la console et reecrire le compteur toujours au meme endroit
                        std::cout << "Il vous reste "<<compteur<<" cartes a selectionner" << std::endl;
                    }
                }
                i++;
            }
            if(existante == false)
            {
                std::cout << "Numero de carte invalide! Veuillez saisir un nouveau numero de carte :" << std::endl;
            }
        }

    }
    setCartesD(cartesD);

}*/
/*
affiche le deck
pas de parametre, pas de retour
*/
void Deck::afficherDeck()
{
    int lig=4, col =1,i=0;
    for(const auto& elem : getCartesD())
    {
        elem->afficher(lig,col);
         elem->afficher(lig,col);
        i++;
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
        else if(i==6)
        {
            col = 1;
            lig = 32;
        }
        else if(i>6 && i<=8)
        {
            col+=60;
        }
        else if(i==9)
        {
            col = 1;
            lig = 44;
        }
        else if(i>9 && i<=11)
        {
            col+=60;
        }
    }
}

/*
vide le deck, utilise apres un ;atch
pas de parametre, pas de retour
*/
void Deck::supprimer()
{
    std::vector<Carte*> deck = getCartesD();

    std::cout << "Avant supprimer deck" << std::endl;

    for(unsigned int i=0; i<deck.size(); i++){
        deck.erase(deck.begin()+i); //on la supprime de la collection
    }

    std::cout << "Apres supp deck" << std::endl;

    setCartesD(deck);


}

/*
ajoute une nouvelle carte au deck
parametre : carte a ajouter
pas de retour
*/
void Deck::ajouter(Carte *nouvCarte)
{

    std::vector<Carte*> deck = getCartesD();
    deck.push_back(nouvCarte);
    setCartesD(deck);

}

