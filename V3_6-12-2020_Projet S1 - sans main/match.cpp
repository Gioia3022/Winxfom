#include "match.h"

Match::Match()
{
    std::vector<Creature*> c1;
    std::vector<Creature*> c2;
    m_creature.push_back(c1);
    m_creature.push_back(c2);

    std::vector<Energie*> e1;
    std::vector<Energie*> e2;
    m_energie.push_back(e1);
    m_energie.push_back(e2);

    std::vector<Speciale*> s1;
    std::vector<Speciale*> s2;
    m_speciale.push_back(s1);
    m_speciale.push_back(s2);

}
Match::~Match()
{

}

/*
Definit aleatoirement qui commence le match, prend l'enjeu pour chaque joueur, initialise la main de chaque joueur
pas de parametre ni de retour
*/

std::vector <Creature*> Match::getCreature(int j)
{
    return m_creature[j];
}

void Match :: afficherVide(int lig, int col)
{
    gotoligcol(lig,col);
    std::cout<<"                                               ";
    gotoligcol(lig+1,col);
    std::cout<<"                                               ";
    gotoligcol(lig+2,col);
    std::cout<<"                                               ";
    gotoligcol(lig+3,col);
    std::cout<<"                                               ";
    gotoligcol(lig+4,col);
    std::cout<<"                                               ";
    gotoligcol(lig+5,col);
    std::cout<<"                                               ";
    gotoligcol(lig+6,col);
    std::cout<<"                                               ";
    gotoligcol(lig+7,col);
    std::cout<<"                                               ";
    gotoligcol(lig+8,col);
    std::cout<<"                                               ";
    gotoligcol(lig+9,col);
    std::cout<<"                                               ";
    gotoligcol(lig+10,col);
    std::cout<<"                                               ";
    gotoligcol(lig+11,col);
}
void Match::afficherVideEner(int lig, int col)
{
    gotoligcol(lig,col);
    std::cout<<"                                              ";
}



void Match::afficherVideLP(int lig, int col)
{
    gotoligcol(lig,col);
    std::cout<<"            ";
}

void Match::afficherVideTable(int lig, int col)
{
    gotoligcol(lig,col);
    std::cout<<"                                                                  ";
    gotoligcol(lig+1,col);
    std::cout<<"                                                                  ";
    gotoligcol(lig+2,col);
    std::cout<<"                                                                  ";
    gotoligcol(lig+3,col);
    std::cout<<"                                                                  ";
    gotoligcol(lig+4,col);
    std::cout<<"                                                                   ";
    gotoligcol(lig+5,col);
    std::cout<<"                                                                   ";
    gotoligcol(lig+6,col);
    std::cout<<"                                                                   ";
    gotoligcol(lig+7,col);
    std::cout<<"                                                                   ";
    gotoligcol(lig+8,col);
    std::cout<<"                                                                    ";
    gotoligcol(lig+9,col);
    std::cout<<"                                                                    ";
    gotoligcol(lig+10,col);
    std::cout<<"                                                                    ";
    gotoligcol(lig+11,col);
    std::cout<<"                                                                    ";
    gotoligcol(lig+12,col);
}

void Match::afficherConsole()
{
    int lig=0;
    for(int i=0; i<35; i++)
    {
        gotoligcol(lig,83);
        std::cout<<"|";
        lig++;
    }
}

int Match::creatureP(int j)
{
    int i = 5;

    if(!m_creature[j].empty())//si il y encore des creatures posées il retourne 1
        i = 1;

    else if(m_creature[j].empty())
        i = 0;

    return i;
}

void Match::start()
{
    srand(time(nullptr));
    int i=rand()%2;

    //decide aleatoirement du joueur qui commence
    m_jo[i].setTurn(1);
    m_jo[(1-i)%2].setTurn(0);

    //Pour les 2 joueurs
    for(int i=0; i<2; i++)
    {
        std::vector <Carte*> new_deck; //prend le deck melange
        std::vector <Carte*> old_deck=m_jo[i].getDeck().getCartesD();


        //Melange du deck
        while(old_deck.size()>0)
        {
            srand(time(NULL));
            int j=rand()%old_deck.size();
            new_deck.push_back(old_deck[j]);
            old_deck.erase(old_deck.begin()+j);
        }

        //Recupere l'enjeu
        if(new_deck[0]->getGenre()== 1)
        {
            Creature* enjeuR = (Creature*) new_deck[0];
            m_jo[i].setEnjeu(enjeuR);
        }
        else if(new_deck[0]->getGenre()== 2)
        {
            Energie* enjeuE = (Energie*) new_deck[0];
            m_jo[i].setEnjeu(enjeuE);
        }
        else if(new_deck[0]->getGenre()== 3)
        {
            Speciale* enjeuS = (Speciale*) new_deck[0];
            m_jo[i].setEnjeu(enjeuS);
        }

        new_deck.erase(new_deck.begin());//supprime l'enjeu du deck
        //Actualisation
        m_jo[i].setDeck(new_deck);

    }
}

void Match::round_single_player(int j)
{

    std::vector <Carte*> deck=m_jo[j].getDeck().getCartesD(); ///Attention on est sense utiliser accesseurs pas directement attribut
    Joueur joueur = m_jo[j];

    int choice = 0; //SI joueur veut remplacer ou non sa carte crea

    int compteurCrea = 0;

    for(const auto& elem : deck){
        if(elem->getGenre() == 1){
            compteurCrea++;
        }
    }



    //si il y a au moins une carte dans le deck
    if(!deck.empty() && compteurCrea > 0)
    {


        bool creaAjt = false;



        //Si on n'a pas deja pose une creature
        if(m_creature[j].empty())
        {

            if(j==0)
            {
                afficherVideTable(5,0);
                gotoligcol(6,2);
                std::cout << "Vous n'avez plus de creature";
            }
            if(j==1)
            {
                afficherVideTable(5,85);
                gotoligcol(6,85);
                std::cout << "Vous n'avez plus de creature";
            }


            int i = 0;
            //On parcourt le deck jusqu'a trouver une creature
            for(const auto& elem : deck)
            {

                //Si on n'a toujours pas ajoute de carte crea on continue
                if(creaAjt == false)
                {

                    //Si la carte piochee est une carte creature
                    if(elem->getGenre() == 1)
                    {
                        //system("cls");


                        Creature* crea = (Creature*) elem;

                        m_creature[j].push_back(crea); //on pose la creature

                        deck.erase(deck.begin()+i); //on efface la carte que l'on vient de push

                        if(j==0)
                        {

                            afficherVideTable(5,2);
                            gotoligcol(6,2);
                            std::cout << "Une creature vient d etre piochee ";
                            m_creature[j][0]->afficher(21,2);
                            Sleep(1000);
                            afficherVideTable(5,2);
                        }
                        if(j==1)
                        {
                            afficherVideTable(5,85);
                            gotoligcol(6,85);
                            std::cout << "Une creature vient d etre piochee ";
                            m_creature[j][0]->afficher(21,85);
                            Sleep(1000);
                            afficherVideTable(5,2);
                        }

                        creaAjt = true; //on dit au programme qu'on a deja ajt une creature

                        //delete crea;

                    }

                    i++;

                }
            }

            system("PAUSE");
        }


        //Si on a deja pose une creature et qu'elle ne vient pas d'etre posee juste avant
        else if(!m_creature[j].empty() && creaAjt == false)
        {
            int choix = 0;

            //Sleep(2000);
            //system("cls");



            //On laisse le choix au joueur que si la carte est de type speciale
            if(deck[0]->getGenre() == 3)
            {
                if(j==0)
                {
                    afficherVideTable(5,2);
                    deck[0]->afficher(5,2);

                }
                if(j==1)
                {
                    afficherVideTable(5,85);
                    deck[0]->afficher(5,85);

                }

                do
                {
                    if(j==0)
                    {
                        gotoligcol(5, 50);
                        std::cout<<"Voulez vous placer cette carte ? ";
                        gotoligcol(6,50);
                        std::cout<<"Saisissez 1 si oui, 2 si non : ";
                        gotoligcol(8,50);
                        std::cin>> choix;
                        if(std::cin.fail())
                        {
                            //Sleep(2000);
                            //system("cls");
                            gotoligcol(7,50);
                            std::cout << "                           ";
                            gotoligcol(7,50);
                            std::cerr << "Erreur, saisie incorrecte.";

                            vider_buffer(); // On remet cin dans un état valide et vide le buffer
                        }
                        else if(choix > 2 || choix < 1)
                        {
                            //Sleep(2000);
                            //system("cls");
                            gotoligcol(7,50);
                            std::cout << "                           ";
                            gotoligcol(7,50);
                            std::cout << "Veuillez rentrer 1 ou 2 svp  ";
                        }
                    }
                    if(j==1)
                    {
                        gotoligcol(5,133);
                        std::cout<<"Voulez vous placer cette carte ? ";
                        gotoligcol(6,133);
                        std::cout<<"Saisissez 1 si oui, 2 si non : ";
                        gotoligcol(8,133);
                        std::cin>> choix;
                        if(std::cin.fail())
                        {
                            //Sleep(2000);
                            //system("cls");
                            gotoligcol(7,133);
                            std::cout << "                           ";
                            gotoligcol(7,133);
                            std::cerr << "Erreur, saisie incorrecte.";

                            vider_buffer(); // On remet cin dans un état valide et vide le buffer
                        }
                        else if(choix > 2 || choix < 1)
                        {
                            //Sleep(2000);
                            //system("cls");
                            gotoligcol(7,133);
                            std::cout << "                           ";
                            gotoligcol(7,133);
                            std::cout << "Veuillez rentrer 1 ou 2 svp  ";
                        }
                    }


                    //Blindage lettre
                }
                while(choix < 1 || choix > 2);
            }

            //Si la carte est energie, on pose la carte systematiquement
            else if(deck[0]->getGenre() == 2)
            {
                //deck[0]->afficher(20,20);

                Energie* enerTmp = (Energie *) deck[0];
                //peut etre afficher la carte énergie posée et afficher aussi la phrase suivante.
                choix = 1;
                if(j==0)
                {
                    afficherVideTable(5,2);
                    gotoligcol(5,2);
                    std::cout << "Vous avez gagne " << enerTmp->getGain() << " points " << enerTmp->getDomaine() << "." << std::endl;
                    Sleep(2000);
                    afficherVideTable(5,2);
                    afficherVideEner(35,2);
                    int t=0,tech=0, lum=0,f=0;
                    for(const auto& elem : m_energie[0])
                    {
                        if(elem->getDomaine() == "Terre")
                        {
                            t++;
                        }
                        if(elem->getDomaine() == "Technologie")
                        {
                            tech++;
                        }
                        if(elem->getDomaine() == "Feu")
                        {
                            f++;
                        }
                        if(elem->getDomaine() == "Lumiere")
                        {
                            lum++;
                        }
                    }
                    gotoligcol(35,2);
                    std::cout<<t<<" point(s) de type Terre";
                    gotoligcol(36,2);
                    std::cout<<tech<<" point(s) de type Technologie";
                    gotoligcol(37,2);
                    std::cout<<f<<" point(s) de type Feu";
                    gotoligcol(38,2);
                    std::cout<<lum<<" point(s) de type Lumiere";

                }
                if(j==1)
                {
                    afficherVideTable(5,85);
                    gotoligcol(5,85);
                    std::cout << "Vous avez gagne " << enerTmp->getGain() << " points " << enerTmp->getDomaine() << "." << std::endl;
                    Sleep(2000);
                    afficherVideTable(5,85);
                    afficherVideEner(35,133);
                    int t2=0,tech2=0, lum2=0,f2=0;
                    for(const auto& elem : m_energie[1])
                    {
                        if(elem->getDomaine() == "Terre")
                        {
                            t2++;
                        }
                        if(elem->getDomaine() == "Technologie")
                        {
                            tech2++;
                        }
                        if(elem->getDomaine() == "Feu")
                        {
                            f2++;
                        }
                        if(elem->getDomaine() == "Lumiere")
                        {
                            lum2++;
                        }
                    }
                    gotoligcol(35,133);
                    std::cout<<t2<<" point(s) de type Terre";
                    gotoligcol(36,133);
                    std::cout<<tech2<<" point(s) de type Technologie";
                    gotoligcol(37,133);
                    std::cout<<f2<<" point(s) de type Feu";
                    gotoligcol(38,133);
                    std::cout<<lum2<<" point(s) de type Lumiere";
                }


            }

            //Si la carte est creature on demande autrement
            else if(deck[0]->getGenre() == 1)
            {

                if(j==0)
                {
                    afficherVideTable(5,2);
                    gotoligcol(5,2);
                    std::cout << "Vous avez pioche cette carte : ";
                    deck[0]->afficher(6,2);
                }
                if(j==0)
                {
                    afficherVideTable(5,85);
                    gotoligcol(5,85);
                    std::cout << "Vous avez pioche cette carte : ";
                    deck[0]->afficher(6,85);
                }




                //Si le joueur a deja une creature en jeu
                if(m_creature[j].size() != 0)
                {



                    //On recupere la crea deja posee
                    //Creature * crea_dejaP = (Creature *) m_creature[j][0];///Pk on fait un cast ici m_creature cest forcement une carte creature non??

                    do
                    {
                        if(j==0)
                        {

                            gotoligcol(5, 50);
                            std::cout<<"Voulez vous remplacer votre carte creature ? ";
                            gotoligcol(6,50);
                            std::cout<<"Saisissez 1 si oui, 2 si non (si non, la nouvelle carte partira au cimetiere): ";
                            gotoligcol(8,50);
                            std::cin>> choice;
                            if(std::cin.fail())
                            {
                                //Sleep(2000);
                                //system("cls");
                                gotoligcol(7,50);
                                std::cout << "                           ";
                                gotoligcol(7,50);
                                std::cerr << "Erreur, saisie incorrecte.";

                                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                            }
                            else if(choice > 2 || choice < 1)
                            {
                                //Sleep(2000);
                                //system("cls");
                                gotoligcol(7,50);
                                std::cout << "                           ";
                                gotoligcol(7,50);
                                std::cout << "Veuillez rentrer 1 ou 2 svp  ";
                            }
                        }
                        if(j==1)
                        {
                            gotoligcol(5,133);
                            std::cout<<"Voulez vous remplacer votre carte creature ? ";
                            gotoligcol(6,133);
                            std::cout<<"Saisissez 1 si oui, 2 si non (si non, la nouvelle carte partira au cimetiere): ";
                            gotoligcol(8,133);
                            std::cin>> choice;
                            if(std::cin.fail())
                            {
                                //Sleep(2000);
                                //system("cls");
                                gotoligcol(7,133);
                                std::cout << "                           ";
                                gotoligcol(7,133);
                                std::cerr << "Erreur, saisie incorrecte.";

                                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                            }
                            else if(choice > 2 || choice < 1)
                            {
                                //Sleep(2000);
                                //system("cls");
                                gotoligcol(7,133);
                                std::cout << "                           ";
                                gotoligcol(7,133);
                                std::cout << "Veuillez rentrer 1 ou 2 svp  ";
                            }


                            /* if(std::cin.fail())
                             {
                                 Sleep(2000);
                                 system("cls");
                                 gotoligcol(43,0);
                                 std::cerr << "Erreur, saisie incorrecte." << std::endl;

                                 vider_buffer(); // On remet cin dans un état valide et vide le buffer
                             }

                             else if(choice > 2 || choice < 1)
                             {
                                 Sleep(2000);
                                 system("cls");
                                 gotoligcol(43,0);
                                 std::cout << "Veuillez rentrer 1 ou 2 svp  ";
                             }*/

                        }
                    }
                    while(choice > 2 || choice < 1);

                    choix = 1; //Pour rentrer dans le match

                }
            }





            ///Si le joueur choisit de poser la carte
            if(choix==1)
            {

                //on efface la console
                Sleep(2000);
                //system("cls");



                switch(deck[0]->getGenre())
                {

                ///Si la carte est une creature
                case 1:
                {
                    //Sleep(4000);
                    //system("cls");
                    //Recupere la carte selectionnee
                    Creature * crea = (Creature * ) deck[0];



                    //Si le joueur veut remplacer sa carte deja posee
                    if(choice == 1)
                    {
                        //On recupere la carte deja posee
                        Creature * crea_dejaP = (Creature *) m_creature[j][0];

                        //On supprime la carte deja posee
                        m_cimitiere.ajouter(crea_dejaP);
                        m_creature[j].erase(m_creature[j].begin());


                        //On ajoute la nouvelle carte
                        m_creature[j].push_back(crea);
                        if(j==0)
                        {
                            afficherVideTable(5,2);
                            m_creature[0][0]->afficher(21,2);

                        }
                        if(j==1)
                        {
                            afficherVideTable(5,85);
                            m_creature[1][0]->afficher(21,85);

                        }
                    }

                    //Si le joueur veut garder sa carte deja posee
                    if(choice == 2)
                    {
                        //On recupere la carte deja posee
                        Creature * crea_dejaP = (Creature *) m_creature[j][0];

                        ///peut etre faire un affichage pour dire que la carte est partie au cimetière
                        m_cimitiere.ajouter(crea); //on ajoute la nouvelle carte au cimetiere

                        crea = crea_dejaP; ///POUR EVITER DE CHANGER TOUTES LES VAR DANS LE CODE
                        if(j==0)
                        {
                            afficherVideTable(5,2);
                            gotoligcol(6,2);
                            std::cout<<"Votre carte est partie au cimetiere ! ";
                            Sleep(2000);
                            gotoligcol(37,78);
                            std::cout<<"                         ";
                            gotoligcol(37,78);
                            std::cout<<"Nombre de cartes : "<<m_cimitiere.getCimetiere().size();
                        }
                        if(j==1)
                        {
                            afficherVideTable(5,85);
                            gotoligcol(6,85);
                            std::cout<<"Votre carte est partie au cimetiere ! ";
                            Sleep(2000);
                            gotoligcol(37,78);
                            std::cout<<"                         ";
                            gotoligcol(37,78);
                            std::cout<<"Nombre de cartes : "<<m_cimitiere.getCimetiere().size();
                        }
                    }

                    //attaque(j,crea);

                    break;

                }


                ///Si la carte est une energie
                case 2:
                {
                    //On ajoute l'energie aux energies du joueur
                    Energie * ene = (Energie * ) deck[0];
                    m_energie[j].push_back(ene);
                    ///faire un affichage des energies dispo
                    if(j==0)
                    {
                        afficherVideEner(35,2);
                        int t=0,tech=0, lum=0,f=0;
                        for(const auto& elem : m_energie[0])
                        {
                            if(elem->getDomaine() == "Terre")
                            {
                                t++;
                            }
                            if(elem->getDomaine() == "Technologie")
                            {
                                tech++;
                            }
                            if(elem->getDomaine() == "Feu")
                            {
                                f++;
                            }
                            if(elem->getDomaine() == "Lumiere")
                            {
                                lum++;
                            }
                        }
                        gotoligcol(35,2);
                        std::cout<<t<<" point(s) de type Terre";
                        gotoligcol(36,2);
                        std::cout<<tech<<" point(s) de type Technologie";
                        gotoligcol(37,2);
                        std::cout<<f<<" point(s) de type Feu";
                        gotoligcol(38,2);
                        std::cout<<lum<<" point(s) de type Lumiere";
                    }
                    if(j==1)
                    {
                        afficherVideEner(35,133);
                        int t2=0,tech2=0, lum2=0,f2=0;
                        for(const auto& elem : m_energie[1])
                        {
                            if(elem->getDomaine() == "Terre")
                            {
                                t2++;
                            }
                            if(elem->getDomaine() == "Technologie")
                            {
                                tech2++;
                            }
                            if(elem->getDomaine() == "Feu")
                            {
                                f2++;
                            }
                            if(elem->getDomaine() == "Lumiere")
                            {
                                lum2++;
                            }
                        }
                        gotoligcol(35,133);
                        std::cout<<t2<<" point(s) de type Terre";
                        gotoligcol(36,133);
                        std::cout<<tech2<<" point(s) de type Technologie";
                        gotoligcol(37,133);
                        std::cout<<f2<<" point(s) de type Feu";
                        gotoligcol(38,133);
                        std::cout<<lum2<<" point(s) de type Lumiere";
                    }


                }

                    //delete ene;
                break;


                ///Si la carte est speciale
                case 3:
                {
                    //Sleep(2000);
                    //system("cls");
                    Speciale * spe =(Speciale *) deck[0];
                    if(j==0)
                    {
                        afficherVideTable(5,2);
                        spe->afficher(5,2);
                    }
                    if(j==1)
                    {
                        afficherVideTable(5,85);
                        spe->afficher(5,85);
                    }


                    ///Si le joueur a deja une carte speciale posee
                    if(!m_speciale[j].empty())
                    {

                        int choice = 0;

                        //On recupere la spe deja posee
                        Speciale * spe_dejaP = (Speciale *) m_speciale[j][0];

                        gotoligcol(20,0);
                        ///ces affichages seront pas forcement nécessaire

                        if(j==0)
                        {

                            gotoligcol(5, 50);
                            std::cout<<"Voulez vous remplacer votre carte speciale ? ";
                            gotoligcol(6,50);
                            std::cout<<"Saisissez 1 si oui, 2 si non (si non, la nouvelle carte partira au cimetiere): ";
                            gotoligcol(8,50);
                            std::cin>> choice;
                            if(std::cin.fail())
                            {
                                //Sleep(2000);
                                //system("cls");
                                gotoligcol(7,50);
                                std::cout << "                           ";
                                gotoligcol(7,50);
                                std::cerr << "Erreur, saisie incorrecte.";

                                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                            }
                            else if(choice > 2 || choice < 1)
                            {
                                //Sleep(2000);
                                //system("cls");
                                gotoligcol(7,50);
                                std::cout << "                           ";
                                gotoligcol(7,50);
                                std::cout << "Veuillez rentrer 1 ou 2 svp  ";
                            }
                        }
                        if(j==1)
                        {
                            gotoligcol(5,133);
                            std::cout<<"Voulez vous remplacer votre carte speciale ? ";
                            gotoligcol(6,133);
                            std::cout<<"Saisissez 1 si oui, 2 si non (si non, la nouvelle carte partira au cimetiere): ";
                            gotoligcol(8,133);
                            std::cin>> choice;
                            if(std::cin.fail())
                            {
                                //Sleep(2000);
                                //system("cls");
                                gotoligcol(7,133);
                                std::cout << "                           ";
                                gotoligcol(7,133);
                                std::cerr << "Erreur, saisie incorrecte.";

                                vider_buffer(); // On remet cin dans un état valide et vide le buffer
                            }
                            else if(choice > 2 || choice < 1)
                            {
                                //Sleep(2000);
                                //system("cls");
                                gotoligcol(7,133);
                                std::cout << "                           ";
                                gotoligcol(7,133);
                                std::cout << "Veuillez rentrer 1 ou 2 svp  ";
                            }



                            //Si le joueur veut remplacer sa carte deja posee
                            if(choice == 1)
                            {

                                //On supprime la carte deja posee
                                m_cimitiere.ajouter(spe_dejaP);
                                m_speciale[j].erase(m_speciale[j].begin());


                                //On ajoute la nouvelle carte
                                m_speciale[j].push_back(spe);
                                if(j==0)
                                {
                                    afficherVideTable(5,2);
                                    afficherVide(21,50);
                                    spe->afficher(21,50);
                                }
                                if(j==1)
                                {
                                    afficherVideTable(5,85);
                                    afficherVide(21,133);
                                    spe->afficher(21,133);
                                }

                                ///afficher la nouvelle carte au bon endroit

                            }

                            //Si le joueur veut garder sa carte deja posee
                            else if(choice == 2)
                            {
                                m_cimitiere.ajouter(spe); //on ajoute la nouvelle carte au cimetiere
                                spe = spe_dejaP; //Pour eviter de tt changer
                                if(j==0)
                                {
                                    afficherVideTable(5,2);
                                    gotoligcol(5,2);
                                    std::cout<<"Votre carte est partie au cimetiere ! ";
                                    Sleep(2000);
                                    afficherVideTable(5,2);
                                }
                                if(j==1)
                                {
                                    afficherVideTable(5,85);
                                    gotoligcol(5,85);
                                    std::cout<<"Votre carte est partie au cimetiere ! ";
                                    Sleep(2000);
                                    afficherVideTable(5,85);
                                }
                            }

                            //delete spe_dejaP;

                        }

                        //Si il n'y a pas de carte deja posee :
                        else
                        {


                            m_speciale[j].push_back(spe);
                            if(j==0)
                            {
                                afficherVideTable(5,2);
                                afficherVide(21,50);
                                spe->afficher(21,50);
                            }
                            if(j==1)
                            {
                                afficherVideTable(5,85);
                                afficherVide(21,133);
                                spe->afficher(21,133);
                            }


                        }

                        switch(spe->getTypeSpe())
                        {


                        case 2:
                        {
                            //Sleep(2000);
                            //system("cls");

                            std::vector<Carte*> deckAdv = m_jo[(j+1)%2].getDeck().getCartesD();

                            //S'il y a bien des cartes dans le cimetiere
                            if(!deckAdv.empty())
                            {

                                Carte* recup = new Carte;
                                recup = spe->pouvoir2(deckAdv);

                                if(recup->getGenre()== 1)
                                {
                                    Creature* creaR = (Creature*) recup;
                                    deck.push_back(creaR);
                                    if(j==0)
                                    {
                                        afficherVideTable(5,2);
                                        gotoligcol(5,2);
                                        std::cout << "Vous avez volé une carte dans le deck adverse !! ";

                                        creaR->afficher(6,2);
                                        Sleep(3000);
                                        afficherVideTable(5,2);

                                    }
                                    if(j==1)
                                    {
                                        afficherVideTable(5,85);
                                        gotoligcol(5,85);
                                        std::cout << "Vous avez volé une carte dans le deck adverse !! ";

                                        creaR->afficher(6,85);
                                        Sleep(3000);
                                        afficherVideTable(5,85);
                                    }

                                }

                                else if(recup->getGenre()== 2)
                                {
                                    Energie* enerR = (Energie*) recup;
                                    deck.push_back(enerR);
                                    if(j==0)
                                    {
                                        afficherVideTable(5,2);
                                        gotoligcol(5,2);
                                        std::cout << "Vous avez volé une carte dans le deck adverse !! ";

                                        enerR->afficher(6,2);
                                        Sleep(3000);
                                        afficherVideTable(5,2);
                                    }
                                    if(j==1)
                                    {
                                        afficherVideTable(5,85);
                                        gotoligcol(5,85);
                                        std::cout << "Vous avez volé une carte dans le deck adverse !! ";

                                        enerR->afficher(6,85);
                                        Sleep(3000);
                                        afficherVideTable(5,85);
                                    }
                                }

                                else if(recup->getGenre()== 3)
                                {
                                    Speciale* speR = (Speciale*) recup;
                                    deck.push_back(speR);
                                    if(j==0)
                                    {
                                        afficherVideTable(5,2);
                                        gotoligcol(5,2);
                                        std::cout << "Vous avez volé une carte dans le deck adverse !! ";

                                        speR->afficher(6,2);
                                        Sleep(3000);
                                        afficherVideTable(5,2);
                                    }
                                    if(j==1)
                                    {
                                        afficherVideTable(5,85);
                                        gotoligcol(5,85);
                                        std::cout << "Vous avez volé une carte dans le deck adverse !! ";

                                        speR->afficher(6,85);
                                        Sleep(3000);
                                        afficherVideTable(5,85);
                                    }
                                }

                                int interateur = 0;
                                for(const auto& elem : deckAdv)
                                {

                                    if(recup->getIdentifiant()== elem->getIdentifiant())
                                    {
                                        deckAdv.erase(deckAdv.begin()+interateur); //on recupere une carte aleatoire dans le cimetiere
                                    }
                                    interateur++;
                                }

                                m_jo[(j+1)%2].setDeck(deckAdv); //Maj du cimetiere



                                //Supprime la carte
                                m_speciale[j].erase(m_speciale[j].begin());
                                m_cimitiere.ajouter(spe);
                                gotoligcol(37,78);
                                std::cout<<"Nombre de carte : "<<m_cimitiere.getCimetiere().size();

                            }

                            else // la carte n'est pas utilisée
                            {
                                if(j==0)
                                {
                                    afficherVideTable(5,2);
                                    gotoligcol(5,2);
                                    std::cout<<"Le deck adverse est vide vous ne pouvez pas lui voler de carte !";
                                    Sleep(2000);
                                    afficherVideTable(5,2);
                                }
                                if(j==1)
                                {
                                    afficherVideTable(5,85);
                                    gotoligcol(5,85);
                                    std::cout<<"Le deck adverse est vide vous ne pouvez pas lui voler de carte !";
                                    Sleep(2000);
                                    afficherVideTable(5,85);
                                }
                            }
                        }

                        break;

                        case 3:
                        {
                            //Sleep(2000);
                            //system("cls");

                            ///AFFICHER CE QU'IL SE PASSE POUR INFORMER LE JOUEUR


                            std::vector <Carte*> old_cimitiere = m_cimitiere.getCimetiere();

                            //S'il y a bien des cartes dans le cimetiere
                            if(!old_cimitiere.empty())
                            {

                                Carte* recup = new Carte;
                                recup = spe->pouvoir3(old_cimitiere);///j'ajoute des cast pour bien afficher

                                if(recup->getGenre()== 1)
                                {
                                    Creature* creaR = (Creature*) recup;
                                    deck.push_back(creaR);
                                    if(j==0)
                                    {
                                        afficherVideTable(5,2);
                                        gotoligcol(5,2);
                                        std::cout << "Vous avez recuperer une carte du cimetiere !! ";

                                        creaR->afficher(6,2);
                                        Sleep(3000);
                                        afficherVideTable(5,2);
                                    }
                                    if(j==1)
                                    {
                                        afficherVideTable(5,85);
                                        gotoligcol(5,85);
                                        std::cout << "Vous avez recuperer une carte du cimetiere  !! ";

                                        creaR->afficher(6,85);
                                        Sleep(3000);
                                        afficherVideTable(5,85);
                                    }
                                    //on affiche la nouvelle carte
                                }
                                else if(recup->getGenre()== 2)
                                {
                                    Energie* enerR = (Energie*) recup;
                                    deck.push_back(enerR);
                                    if(j==0)
                                    {
                                        afficherVideTable(5,2);
                                        gotoligcol(5,2);
                                        std::cout << "Vous avez recuperer une carte du cimetiere !! ";

                                        enerR->afficher(6,2);
                                        Sleep(3000);
                                        afficherVideTable(5,2);
                                    }
                                    if(j==1)
                                    {
                                        afficherVideTable(5,85);
                                        gotoligcol(5,85);
                                        std::cout << "Vous avez recuperer une carte du cimetiere  !! ";

                                        enerR->afficher(6,85);
                                        Sleep(3000);
                                        afficherVideTable(5,85);
                                    }

                                }
                                else if(recup->getGenre()== 3)
                                {
                                    Speciale* speR = (Speciale*) recup;
                                    deck.push_back(speR);
                                    if(j==0)
                                    {
                                        afficherVideTable(5,2);
                                        gotoligcol(5,2);
                                        std::cout << "Vous avez recuperer une carte du cimetiere !! ";

                                        speR->afficher(6,2);
                                        Sleep(3000);
                                        afficherVideTable(5,2);
                                    }
                                    if(j==1)
                                    {
                                        afficherVideTable(5,85);
                                        gotoligcol(5,85);
                                        std::cout << "Vous avez recuperer une carte du cimetiere  !! ";

                                        speR->afficher(6,85);
                                        Sleep(3000);
                                        afficherVideTable(5,85);
                                    }
                                }
                                int interateur = 0;
                                for(const auto& elem : old_cimitiere)
                                {

                                    if(recup->getIdentifiant()== elem->getIdentifiant())
                                    {
                                        old_cimitiere.erase(old_cimitiere.begin()+interateur); //on recupere une carte aleatoire dans le cimetiere
                                    }
                                    interateur++;
                                }

                                m_cimitiere.setCimetiere(old_cimitiere); //Maj du cimetiere
                                ///AU LIEU DE FAIRE UN SET PEUT ETRE SUPPRIME LA CARTE DU CIMETIERE ICI PLUTOT QUE DANS LE POUVOIR 3 CE SERA PLUS PROPRE PCQ PAS SUR QUE LE CIMETIERE SOIT MODIFIE                            PLUS

                                ///Afficher la carte recuperee


                                //Supprime la carte
                                m_speciale[j].erase(m_speciale[j].begin());
                                m_cimitiere.ajouter(spe);

                            }

                            else
                            {
                                // la carte n'est pas utilisée
                                if(j==0)
                                {
                                    afficherVideTable(5,2);
                                    gotoligcol(5,2);
                                    std::cout<<"Le cimetiere est vide vous ne pouvez pas recuperer de carte !";
                                    Sleep(2000);
                                    afficherVideTable(5,2);
                                }
                                if(j==1)
                                {
                                    afficherVideTable(5,85);
                                    gotoligcol(5,85);
                                    std::cout<<"Le cimetiere est vide vous ne pouvez pas recuperer de carte !";
                                    Sleep(2000);
                                    afficherVideTable(5,85);
                                }
                            }
                            break;
                        }

                        case 4:
                        {

                            Sleep(2000);
                            system("cls");


                            //Si le joueur a bien une creature
                            if(!m_creature[j].empty())
                            {

                                if(j==0)
                                {
                                    afficherVideTable(5,2);
                                    gotoligcol(5,2);
                                    std::cout<<"Votre creature a gagne des points de vie";
                                    Sleep(2000);
                                    afficherVideTable(5,2);
                                    m_creature[j][0]=spe->pouvoir4(m_creature[j][0]);
                                    afficherVide(21,2);
                                    m_creature[0][0]->afficher(21,2);
                                }
                                if(j==1)
                                {
                                    afficherVideTable(5,85);
                                    gotoligcol(5,85);
                                    std::cout<<"Votre creature a gagne des points de vie";
                                    Sleep(2000);
                                    afficherVideTable(5,85);
                                    m_creature[j][0]=spe->pouvoir4(m_creature[j][0]);
                                    afficherVide(21,85);
                                    m_creature[0][0]->afficher(21,85);
                                }
                            }

                            else
                            {
                                if(j==0)
                                {
                                    afficherVideTable(5,2);
                                    gotoligcol(5,2);
                                    std::cout<<"Vous n'avez pas de creature active, la carte n'a pas pu être utilisee";
                                    Sleep(2000);
                                    afficherVideTable(5,2);

                                }
                                if(j==1)
                                {
                                    afficherVideTable(5,85);
                                    gotoligcol(5,85);
                                    std::cout<<"Vous n'avez pas de creature active, la carte n'a pas pu être utilisee";
                                    Sleep(2000);
                                    afficherVideTable(5,95);

                                }
                            }
                            break;
                        }

                        case 6:
                        {
                            ///AFFICHAGE POUR INDIQUE AU JOUEUR CE QU'IL SE PASSE

                            //Sleep(2000);
                            //system("cls");

                            std::vector <Carte*> old_deck = m_jo[(j+1)%2].getDeck().getCartesD();
                            std::vector <Carte*> cimetiere = m_cimitiere.getCimetiere();

                            if(!old_deck.empty())
                            {
                                Carte* tmp = new Carte;
                                tmp = spe->pouvoir6(old_deck);

                                if(tmp->getGenre()==1)
                                {
                                    //Creature* crea2 = new Creature;
                                    //crea2 = (Creature*) tmp;
                                    if(j==0)
                                    {
                                        afficherVideTable(5,2);
                                        gotoligcol(5,2);
                                        std::cout << m_jo[(j+1)%2].getNom() << " a perdu une carte de son deck";
                                        Sleep(2000);
                                        afficherVideTable(5,2);
                                    }
                                    if(j==1)
                                    {
                                        afficherVideTable(5,85);
                                        gotoligcol(5,85);
                                        std::cout << m_jo[(j+1)%2].getNom() << " a perdu une carte de son deck";
                                        Sleep(2000);
                                        afficherVideTable(5,85);
                                    }

                                }
                                else if(tmp->getGenre()==2)
                                {
                                    //Energie* ener2 = new Energie;
                                    //ener2 = (Energie*) tmp;
                                    if(j==0)
                                    {
                                        afficherVideTable(5,2);
                                        gotoligcol(5,2);
                                        std::cout << m_jo[(j+1)%2].getNom() << " a perdu une carte de son deck";
                                        Sleep(2000);
                                        afficherVideTable(5,2);
                                    }
                                    if(j==1)
                                    {
                                        afficherVideTable(5,85);
                                        gotoligcol(5,85);
                                        std::cout << m_jo[(j+1)%2].getNom() << " a perdu une carte de son deck";
                                        Sleep(2000);
                                        afficherVideTable(5,85);
                                    }
                                }
                                else if(tmp->getGenre()==3)
                                {
                                    //Speciale* speciale2 = new Speciale;
                                    //speciale2 = (Speciale*) tmp;
                                    if(j==0)
                                    {
                                        afficherVideTable(5,2);
                                        gotoligcol(5,2);
                                        std::cout << m_jo[(j+1)%2].getNom() << " a perdu une carte de son deck";
                                        Sleep(2000);
                                        afficherVideTable(5,2);
                                    }
                                    if(j==1)
                                    {
                                        afficherVideTable(5,85);
                                        gotoligcol(5,85);
                                        std::cout << m_jo[(j+1)%2].getNom() << " a perdu une carte de son deck";
                                        Sleep(2000);
                                        afficherVideTable(5,85);
                                    }
                                }

                                int iter = 0;

                                //On supprime la carte du deck du joueur adverse
                                for(const auto& elem : old_deck)
                                {
                                    if(elem->getIdentifiant() == tmp->getIdentifiant())///DANS POUVOIR 6 ON LA SUPPRIME DEJA PEUT ETRE ENLEVER LA SUPRESSION DANS LE POUVOIR6
                                    {
                                        old_deck.erase(old_deck.begin()+iter);
                                    }
                                    iter++;
                                }


                                m_jo[(j-1)%2].setDeck(old_deck);

                                cimetiere.push_back(tmp);// on envoie la carte perdue de l'adversaire au cimetiere


                                //supprime la carte
                                m_speciale[j].erase(m_speciale[j].begin());
                                m_cimitiere.ajouter(deck[0]); //deck[saisie] = spe6

                                m_cimitiere.setCimetiere(cimetiere);

                            }

                            else
                            {
                                if(j==0)
                                {
                                    afficherVideTable(5,2);
                                    gotoligcol(5,2);
                                    std::cout << m_jo[(j+1)%2].getNom() << " n'a pas de carte dans son deck";
                                    Sleep(2000);
                                    afficherVideTable(5,2);
                                }
                                if(j==1)
                                {
                                    afficherVideTable(5,85);
                                    gotoligcol(5,85);
                                    std::cout << m_jo[(j+1)%2].getNom() << " n'a pas de carte dans son deck";
                                    Sleep(2000);
                                    afficherVideTable(5,85);

                                }
                            }
                        }
                        break;
                        }

                    }
                    //delete spe;
                    break;
                }
                }

                deck.erase(deck.begin()); //Supprime la carte qui vinet d'etre jouee du deck

            }

            else if(choix == 2)
            {
                // system("cls");
                if(j==0)
                {
                    afficherVideTable(5,2);
                    gotoligcol(5,2);
                    std::cout <<  "Vous avez decide de passer votre tour, votre carte part donc dans le cimetiere...";
                    Sleep(2000);
                    afficherVideTable(5,2);
                    gotoligcol(37,78);
                    std::cout<<"Nombre de cartes : "<<m_cimitiere.getCimetiere().size();


                }
                if(j==1)
                {
                    afficherVideTable(5,85);
                    gotoligcol(5,85);
                    std::cout <<  "Vous avez decide de passer votre tour, votre carte part donc dans le cimetiere...";
                    Sleep(2000);
                    afficherVideTable(5,85);
                    gotoligcol(37,78);
                    std::cout<<"Nombre de cartes : "<<m_cimitiere.getCimetiere().size();


                }

                deck.erase(deck.begin());

            }

        }


        m_jo[j].setDeck(deck);
    }

    //Hors de la verif si deck vide car on peut toujours attaquer avec deck vide
    //Si les deux joueurs ont encore des creatures
    if(m_creature[j].size() > 0 && m_creature[(j+1)%2].size() > 0 && m_jo[j].getOut()== false && m_jo[(j+1)%2].getOut()== false)
    {
        Creature* creaP = m_creature[j][0]; //On recupere la creature posee
        attaque(j,creaP); //On attaque
    }

    /*if(m_jo[j].getDeck().getCartesD().empty())
    {
        if(!m_creature[j].empty() && !m_creature[(j+1)%2].empty() )
        {
            Creature* creaP = m_creature[j][0]; //On recupere la creature posee
            attaque(j,creaP); //On attaque
        }

    }*/

    ///ICI ATTENTION

}



int Match::round()
{
    int i(6);
    afficherConsole();
    gotoligcol(0,36);
    std::cout<<"* Joueur 1 *";
    gotoligcol(0,119);
    std::cout<<"* Joueur 2 *";
    gotoligcol(2,3);
    std::cout<<"Pseudo : "<<m_jo[0].getNom();
    gotoligcol(2,25);
    std::cout<<"LP : "<<m_jo[0].getLP();
    gotoligcol(2,86);
    std::cout<<"Pseudo : "<<m_jo[1].getNom();
    gotoligcol(2,108);
    std::cout<<"LP : "<<m_jo[1].getLP();


    //AFFICHAGE TABLE
    gotoligcol(4,2);
    std::cout<<"Table de jeu : ";
    gotoligcol(4,85);
    std::cout<<"Table de jeu : ";

    //affichage cimetiere
    gotoligcol(35,78);
    std::cout<<" CIMETIERE ";

    //AFFICHAGE CARTE ACTIVE
    gotoligcol(20,2);
    std::cout<<"Creature active : "<<std::endl;

    gotoligcol(20,85);
    std::cout<<"Creature active : "<<std::endl;

    //AFFICHAGE CARTE SPECIALE

    gotoligcol(20,50);
    std::cout<<"Speciale active : "<<std::endl;

    gotoligcol(20,133);
    std::cout<<"Speciale active : "<<std::endl;

    //AFFICHAGE LISTE ENERGIE

    gotoligcol(34,2);
    std::cout<<"Energie disponible : "<<std::endl;

    gotoligcol(34,133);
    std::cout<<"Energie disponible : "<<std::endl;


    system("PAUSE");

    if(m_jo[0].getTurn()==1)
    {
        for(int j=0; j<2; j++)
        {
            round_single_player(j);
        }
    }
    else
    {
        for(int j=1; j>=0; j--)
        {
            round_single_player(j);
        }

    }
    bool trouve = false;
    for(const auto& elem : m_jo[0].getDeck().getCartesD())
    {
        if(elem->getGenre() == 1)
        {
            trouve = true;
        }
    }

    if(creatureP(0) == 0 && trouve == false)
    {
        i=0;// si le joueur 1 n'a plus de cartes creature posee ni de cartes dans son deck
    }
    bool trouve2 = false;
    for(const auto& elem : m_jo[1].getDeck().getCartesD())
    {
        if(elem->getGenre() == 1)
        {
            trouve2 = true;
        }
    }
    if(creatureP(1) == 0 && trouve2 == false)
    {
        i = 1;
    }
    else i = 2;
    return i;
}


/*
On assigne deux joueurs qui vont s'affronter au match
Parametres : les deux joueurs qui vont s'affronter
pas de retour
*/
void Match::ajouterJoueurs(Joueur joueur1, Joueur joueur2)
{
    std::vector<Joueur> joueurs=getJoueurs();

    joueurs.push_back(joueur1);
    joueurs.push_back(joueur2);

    setJoueurs(joueurs);
}


///Accesseurs

void Match::setJoueurs(std::vector<Joueur> joueurs)
{
    m_jo=joueurs;
}

std::vector <Joueur> Match::getJoueurs()
{
    return m_jo;
}


/*
Retire les joueurs du match du jeu (utilisee lorsque le match est termine)
pas de parametre, pas de retour
*/
void Match::supprimerJoueurs()
{
    std::vector<Joueur> joueurs = getJoueurs();

    joueurs.pop_back();
    joueurs.pop_back();

    setJoueurs(joueurs);
}

void Match::attaque(int j, Creature* crea)
{
    Sleep(2000);
    system("cls");

    int energia= 0; //Nombre de cartes energie du type dont la creature selectionnee a besoin

    //On parcourt le vecteur d'energies

    ///METTRE BLINDAGE SI ON A PAS D ENERGIE
    for(unsigned int k=0; k<m_energie[j].size(); k++)
    {
        //a chaque fois au'on trouve la carte energie on ajoute le gain de la carte a energia
        if(m_energie[j][k]->getDomaine() == crea->getEnergie())
        {
            energia+=m_energie[j][k]->getGain();
        }
    }

    int nAttaque=0; //Choix d'attaque
    int atq = 0; //permet de savoir si joueur veut attaquer ou pas
    bool self_hit = false, defense = false; //Variables pour actions des cartes speciales : defense est l'immunite


    //Si l'adversaire n'a pas de creature
    if(m_creature[(j+1)%2].size() == 0)
    {
        if(j==0)
        {
            afficherVideTable(5,2);
            gotoligcol(5,2);
            std::cout << "Vous ne pouvez pas encore attaquer, l'adversaire n'a pas pose de creature";
            Sleep(3000);
            afficherVideTable(5,2);

        }
        if(j==1)
        {
            afficherVideTable(5,85);
            gotoligcol(5,85);
            std::cout << "Vous ne pouvez pas encore attaquer, l'adversaire n'a pas pose de creature";
            Sleep(3000);
            afficherVideTable(5,85);

        }
    }


    //On propose d'attaquer que si le joueur a assez de cartes energies
    else if(energia >= crea->getAttaque()[0]->getCoupPE() || energia >= crea->getAttaque()[1]->getCoupPE())
    {

        ///AFFICHAGE ATTAQUES///

        //Affichage des attaques
        int lig(5), col(2),lig2(5),col2(85);
        for(unsigned int l=0; l<crea->getAttaque().size(); l++)
        {
            //On affiche les attaques pour lequelles on a assez de points energie pour les utiliser
            if(energia >= crea->getAttaque()[l]->getCoupPE())
            {
                if(j==0)
                {
                    afficherVideTable(5,2);
                    gotoligcol(lig,col);
                    std::cout << "Attaque " << l+1 << " : ";
                    crea->getAttaque()[l]->afficherAttaque(lig+2,col);
                    lig+=5;

                }
                if(j==1)
                {
                    afficherVideTable(5,85);
                    gotoligcol(lig2,col2);
                    std::cout << "Attaque " << l+1 << " : ";
                    crea->getAttaque()[l]->afficherAttaque(lig2+2,col2);
                    lig2+=5;

                }

            }
        }



        ///CHOIX ATTAQUE OU PAS///

        //Saisie attaque blindee
        do
        {
            if(j==0)
            {

                gotoligcol(5,50);
                std::cout<< "Que voulez vous faire : 1. Attaquer ou 2. Ne rien faire"<<std::endl;
                gotoligcol(7,50);
                std::cin>> atq;

                if(std::cin.fail())
                {
                    //Sleep(2000);
                    //system("cls");
                    gotoligcol(6,50);
                    std::cout<<"                              ";
                    gotoligcol(6,50);
                    std::cerr << "Erreur, saisie incorrecte.";

                    vider_buffer(); // On remet cin dans un état valide et vide le buffer
                }

                else if(atq < 1 || atq > 2)
                {
                    gotoligcol(6,50);
                    std::cout<<"                              ";
                    gotoligcol(6,50);
                    std::cout << "Rentrez 1 ou 2 svp." << std::endl;
                }
            }
            if(j==1)
            {

                gotoligcol(5,133);
                std::cout<< "Que voulez vous faire : 1. Attaquer ou 2. Ne rien faire"<<std::endl;
                gotoligcol(7,133);
                std::cin>> atq;

                if(std::cin.fail())
                {
                    //Sleep(2000);
                    //system("cls");
                    gotoligcol(6,133);
                    std::cout<<"                              ";
                    gotoligcol(6,133);
                    std::cerr << "Erreur, saisie incorrecte.";

                    vider_buffer(); // On remet cin dans un état valide et vide le buffer
                }

                else if(atq < 1 || atq > 2)
                {
                    gotoligcol(6,133);
                    std::cout<<"                              ";
                    gotoligcol(6,133);
                    std::cout << "Rentrez 1 ou 2 svp." << std::endl;
                }
            }

        }

        while(atq<1 || atq > 2);


        int energie_utilisee=0;

        ///Si le joueur decide d'attaquer
        if(atq==1)
        {

            ///CHECK CARTE SPE ADV///

            //Recupere la carte spe de l'adversaire
            if(m_speciale[(j+1)%2].size() > 0)
            {
                Speciale* speAdv = (Speciale *) m_speciale[(j+1)%2][0];

                //Si l'adversaire a pose la carte qui retourne l'attaque contre l'attaquant
                if(speAdv->getTypeSpe()==1)
                {
                    self_hit = true;
                }

                //Si l'adversaire a pose la carte d'immunite
                if(speAdv->getTypeSpe()==5)
                {
                    defense = true;
                }


            }



            ///CHOIX NUMERO ATTAQUE///

            do
            {
                if(j==0)
                {

                    gotoligcol(5,50);
                    std::cout<<"                                                     ";
                    gotoligcol(5,50);
                    std::cout<< "Quelle attaque voulez vous faire? (1/2) : "<<std::endl;
                    gotoligcol(7,50);
                    std::cin>> nAttaque;

                    if(std::cin.fail())
                    {
                        //Sleep(2000);
                        //system("cls");
                        gotoligcol(6,50);
                        std::cout<<"                              ";
                        gotoligcol(6,50);
                        std::cerr << "Erreur, saisie incorrecte.";

                        vider_buffer(); // On remet cin dans un état valide et vide le buffer
                    }

                    else if(nAttaque > 2 || nAttaque < 1)
                    {
                        gotoligcol(6,50);
                        std::cout<<"                              ";
                        gotoligcol(6,50);
                        std::cout << "Rentrez 1 ou 2 svp." << std::endl;
                    }
                }
                if(j==1)
                {

                    gotoligcol(5,133);
                    std::cout<<"                                                     ";
                    gotoligcol(5,133);
                    std::cout<< "Quelle attaque voulez vous faire? (1/2) : ";
                    gotoligcol(7,133);
                    std::cin>> nAttaque;

                    if(std::cin.fail())
                    {
                        //Sleep(2000);
                        //system("cls");
                        gotoligcol(6,133);
                        std::cout<<"                              ";
                        gotoligcol(6,133);
                        std::cerr << "Erreur, saisie incorrecte.";

                        vider_buffer(); // On remet cin dans un état valide et vide le buffer
                    }

                    else if(nAttaque > 2 || nAttaque < 1)
                    {
                        gotoligcol(6,133);
                        std::cout<<"                              ";
                        gotoligcol(6,133);
                        std::cout << "Rentrez 1 ou 2 svp." << std::endl;
                    }
                }





            }
            while(nAttaque > 2 || nAttaque < 1);




            ///SWITCH DU CHOIX DE L'ATTAQUE///

            switch(nAttaque)
            {

            //attaque 1
            case 1:
            {


                //si on a carte speciale 1
                if(self_hit)
                {
                    //si on a assez d'energies

                    //On recupere le nb de pt energie dont on a besoin
                    energie_utilisee = crea->getAttaque()[0]->getCoupPE();

                    //Si la crea a toujours des pt de vie
                    if((crea->getLP() - crea->getAttaque()[0]->getHp()) >0)
                    {
                        crea->setLP(crea->getLP() - crea->getAttaque()[0]->getHp());
                        if(j==0)
                        {
                            afficherVideTable(5,2);
                            gotoligcol(5,2);
                            std::cout <<"L'attaque de votre creature vient de se retourner contre elle...";
                            Sleep(3000);
                            afficherVideTable(5,2);
                            afficherVide(21,2);
                            crea->afficher(21,2);

                        }
                        if(j==1)
                        {
                            afficherVideTable(5,85);
                            gotoligcol(5,85);
                            std::cout <<"L'attaque de votre creature vient de se retourner contre elle...";
                            Sleep(3000);
                            afficherVideTable(5,85);
                            afficherVide(21,85);
                            crea->afficher(21,85);

                        }


                    }
                    else //SI creature morte
                    {

                        crea->setLP(0);
                        m_cimitiere.ajouter(crea); //La creature est morte, elle va dans le cimetiere
                        if(j==0)
                        {
                            afficherVideTable(5,2);
                            gotoligcol(5,2);
                            std::cout <<"L'attaque de votre creature vient de se retourner contre elle...Elle vient de mourir";
                            Sleep(3000);
                            afficherVideTable(5,2);
                            afficherVide(21,2);
                            gotoligcol(37,78);
                            std::cout<<"Nombre de cartes : "<<m_cimitiere.getCimetiere().size();

                        }
                        if(j==1)
                        {
                            afficherVideTable(5,85);
                            gotoligcol(5,85);
                            std::cout <<"L'attaque de votre creature vient de se retourner contre elle...Elle vient de mourir";
                            Sleep(3000);
                            afficherVideTable(5,85);
                            afficherVide(21,85);
                            gotoligcol(37,78);
                            std::cout<<"Nombre de cartes : "<<m_cimitiere.getCimetiere().size();

                        }

                        ///AFFICHAGE POUR DIRE QUE LA CARTE PARS AU CIMETIERE


                        //On efface la creature
                        m_creature[j].erase(m_creature[j].begin());
                    }



                }

                //Si on a une carte immunite
                else if(defense)
                {
                    if(j==0)
                    {
                        afficherVideTable(5,2);
                        gotoligcol(5,2);
                        std::cout << m_jo[1].getNom() << " est immunise ! Vous ne pouvez donc pas l'attaquer ";
                        Sleep(3000);
                        afficherVideTable(5,2);

                    }
                    if(j==1)
                    {
                        afficherVideTable(5,85);
                        gotoligcol(5,85);
                        std::cout << m_jo[0].getNom() << " est immunise ! Vous ne pouvez donc pas l'attaquer ";
                        Sleep(3000);
                        afficherVideTable(5,85);

                    }

                }

                //Si pas de carte speciale
                else
                {
                    //Si assez d'energies pour cette attaque
                    if(energia >= crea->getAttaque()[0]->getCoupPE())
                    {
                        //on recup le nb de pt energie necessaire
                        energie_utilisee = crea->getAttaque()[0]->getCoupPE();

                        //On attaque si la creature du joueur adverse a toujours des points de vie
                        if((m_creature[(j+1)%2][0]->getLP()-crea->getAttaque()[0]->getHp())>0)
                        {
                            m_creature[(j+1)%2][0]->setLP(m_creature[(j+1)%2][0]->getLP()-crea->getAttaque()[0]->getHp()); //On attaque
                            if(j==0)
                            {
                                afficherVide(21,85);
                                m_creature[1][0]->afficher(21,85);

                            }
                            if(j==1)
                            {
                                afficherVide(21,2);
                                m_creature[1][0]->afficher(21,2);

                            }


                        }
                        ///AFFICHAGE DES LP DE LA CREATURE QUI VIENT D ETRE ATTAQUEE

                        //Si la creature adv est morte
                        else
                        {

                            m_creature[(j+1)%2][0]->setLP(0);
                            m_cimitiere.ajouter(m_creature[(j+1)%2][0]); //On ajoute la creature de l'adv au cimetiere
                            m_creature[(j+1)%2].erase(m_creature[(j+1)%2].begin()); // on supprime la creature de l'adversaire

                            std::cout<< "La carte creature de " << m_jo[(j-1)%2].getNom() << "est morte et va au cimetiere."<<std::endl;

                            //S'il reste des pts d'attaque a utiliser, c'est le joueur adv qui perd les pv
                            m_jo[(j+1)%2].setLP(m_jo[(j+1)%2].getLP() + m_creature[(j+1)%2][0]->getLP() - crea->getAttaque()[0]->getHp());
                            ///AFFICHAGE DES LP DU JOUEUR
                            if(j==0)
                            {
                                afficherVide(21,85);
                                afficherVideTable(5,2);
                                gotoligcol(5,2);
                                std::cout<<"La creature de l'adversaire est morte";
                                afficherVideLP(2,112);
                                gotoligcol(2,112);
                                std::cout<<m_jo[1].getLP();
                                Sleep(3000);
                                afficherVideTable(5,2);


                            }
                            if(j==1)
                            {
                                afficherVide(21,2);
                                afficherVideTable(5,85);
                                gotoligcol(5,85);
                                std::cout<<"La creature de l'adversaire est morte";
                                afficherVideLP(2,29);
                                gotoligcol(2,29);
                                std::cout<<m_jo[0].getLP();
                                Sleep(3000);
                                afficherVideTable(5,85);

                            }

                            ///AJOUTER DES POINTS AU JOUEUR QUI A TUE LA CREATURE
                        }
                    }

                    else //si pas assez d'energie
                    {
                        if(j==0)
                        {
                            //afficherVideTable(5,2);
                            gotoligcol(5,50);
                            std::cout<<"Vous n'avez pas assez d energie pour attaquer";
                            Sleep(3000);
                            afficherVideTable(5,2);
                        }
                        if(j==1)
                        {
                            //afficherVideTable(5,2);
                            gotoligcol(5,133);
                            std::cout<<"Vous n'avez pas assez d energie pour attaquer";
                            Sleep(3000);
                            afficherVideTable(5,85);
                        }
                        nAttaque=0;
                    }
                }

                break;
            }


            //Attaque 2
            case 2:
            {

                //Si carte speciale 1
                if(self_hit)
                {

                    //On recupere le nb de pt energie dont on a besoin
                    energie_utilisee = crea->getAttaque()[1]->getCoupPE();

                    //Si la crea a toujours des pt de vie
                    if((crea->getLP() - crea->getAttaque()[1]->getHp()) >0)
                    {
                        crea->setLP(crea->getLP()-crea->getAttaque()[1]->getHp());
                        ///affichage des LP de la creature adversaire
                        if(j==0)
                        {
                            afficherVideTable(5,2);
                            gotoligcol(5,2);
                            std::cout <<"L'attaque de votre creature vient de se retourner contre elle...";
                            Sleep(3000);
                            afficherVideTable(5,2);
                            afficherVide(21,2);
                            crea->afficher(21,2);

                        }
                        if(j==1)
                        {
                            afficherVideTable(5,85);
                            gotoligcol(5,85);
                            std::cout <<"L'attaque de votre creature vient de se retourner contre elle...";
                            Sleep(3000);
                            afficherVideTable(5,85);
                            afficherVide(21,85);
                            crea->afficher(21,85);

                        }

                    }

                    else //SI creature morte
                    {
                        crea->setLP(0);
                        ///afficher que la creature part au cimetiere
                        m_cimitiere.ajouter(crea); //La creature est morte, elle va dans le cimetiere
                        if(j==0)
                        {
                            afficherVideTable(5,2);
                            gotoligcol(5,2);
                            std::cout <<"L'attaque de votre creature vient de se retourner contre elle...Elle vient de mourir";
                            Sleep(3000);
                            afficherVideTable(5,2);
                            afficherVide(21,2);
                            gotoligcol(37,78);
                            std::cout<<"Nombre de cartes : "<<m_cimitiere.getCimetiere().size();

                        }
                        if(j==1)
                        {
                            afficherVideTable(5,85);
                            gotoligcol(5,85);
                            std::cout <<"L'attaque de votre creature vient de se retourner contre elle...Elle vient de mourir";
                            Sleep(3000);
                            afficherVideTable(5,85);
                            afficherVide(21,85);
                            gotoligcol(37,78);
                            std::cout<<"Nombre de cartes : "<<m_cimitiere.getCimetiere().size();

                        }


                        //On efface la creature
                        m_creature[j].erase(m_creature[j].begin());
                    }



                }

                //Si carte spe 2
                else if(defense)
                {
                   if(j==0)
                    {
                        afficherVideTable(5,2);
                        gotoligcol(5,2);
                        std::cout << m_jo[1].getNom() << " est immunise ! Vous ne pouvez donc pas l'attaquer ";
                        Sleep(3000);
                        afficherVideTable(5,2);

                    }
                    if(j==1)
                    {
                        afficherVideTable(5,85);
                        gotoligcol(5,85);
                        std::cout << m_jo[0].getNom() << " est immunise ! Vous ne pouvez donc pas l'attaquer ";
                        Sleep(3000);
                        afficherVideTable(5,85);

                    }

                }

                //Si pas de carte spe ou une autre
                else
                {

                    //on recup le nb de pt energie necessaire
                    energie_utilisee = crea->getAttaque()[0]->getCoupPE();

                    //On attaque
                    if((m_creature[(j+1)%2][0]->getLP() - crea->getAttaque()[1]->getHp()) > 0)
                    {

                        m_creature[(j+1)%2][0]->setLP(m_creature[(j+1)%2][0]->getLP() - crea->getAttaque()[1]->getHp()); //On attaque
                        if(j==0)
                            {
                                afficherVide(21,85);
                                m_creature[1][0]->afficher(21,85);

                            }
                            if(j==1)
                            {
                                afficherVide(21,2);
                                m_creature[1][0]->afficher(21,2);

                            }
                        ///affichage des LP de la creature adversaire

                    }

                    //Si la creature adv est morte
                    else
                    {

                        m_creature[(j+1)%2][0]->setLP(0);
                        m_cimitiere.ajouter(m_creature[(j+1)%2][0]); //On ajoute la creature de l'adv au cimetiere
                        m_creature[(j+1)%2].erase(m_creature[(j+1)%2].begin()); // on supprime la creature de l'adversaire

                        //S'il reste des pts d'attaque a utiliser, c'est le joueur adv qui perd les pv
                        m_jo[(j+1)%2].setLP(m_jo[(j+1)%2].getLP() + (m_creature[(j+1)%2][0]->getLP() - crea->getAttaque()[0]->getHp()));
                        ///affichage des LP du joueur
                        if(j==0)
                            {
                                afficherVide(21,85);
                                afficherVideTable(5,2);
                                gotoligcol(5,2);
                                std::cout<<"La creature de l'adversaire est morte";
                                afficherVideLP(2,112);
                                gotoligcol(2,112);
                                std::cout<<m_jo[1].getLP();
                                Sleep(3000);
                                afficherVideTable(5,2);


                            }
                            if(j==1)
                            {
                                afficherVide(21,2);
                                afficherVideTable(5,85);
                                gotoligcol(5,85);
                                std::cout<<"La creature de l'adversaire est morte";
                                afficherVideLP(2,29);
                                gotoligcol(2,29);
                                std::cout<<m_jo[0].getLP();
                                Sleep(3000);
                                afficherVideTable(5,85);

                            }
                        ///AJOUTER POINTS AU JOUEUR QUI A LANCE L'ATTAQUE
                    }

                }
                break;
            }

            default:
                break;
            }


            ///GESTION POINTS ENERGIE///

            bool fini = false;
            //Si on a utilise des points energies
            if(energie_utilisee > 0)
            {

                if(!m_energie[j].empty())
                {
                    for(unsigned int k = 0; k < m_energie[j].size(); k++)
                    {
                        //Si domaine de la carte j-k correspond au domaine de la creature
                        if(m_energie[j][k]->getDomaine() == crea->getEnergie()&& fini==false)
                        {
                            //On utilise la carte : met le gain a 0 et retourne bool si carte pas deja utilisee
                            m_energie[j].erase(m_energie[j].begin() + k);
                            //la carte est utilisee
                            //On decremente pour savoir jusqu'a quand on continue de supp des cartes E
                            energie_utilisee--;

                        }
                        if(energie_utilisee == 0) fini =true;
                    }
                }
            }


            ///SUPPRESSION CARTE SPE DE L'ADEVERSAIRE///

            //Si on a une carte speciale 1
            if(self_hit)
            {
                m_cimitiere.ajouter(m_speciale[(j+1)%2][0]); //On met la carte spe au cimetiere
                m_speciale[(j+1)%2].erase(m_speciale[(j+1)%2].begin()); //on efface la carte spe des cartes du joueur adverse
                self_hit = false;


            }

            //Si carte spe 5
            else if(defense)
            {
                //On supprime carte
                m_cimitiere.ajouter(m_speciale[(j+1)%2][0]);
                m_speciale[(j+1)%2].erase(m_speciale[(j+1)%2].begin());
                defense = false;


            }
            else
            {

            }
        }
        else
        {
                if(j==0)
                        {
                            afficherVideTable(5,2);
                            gotoligcol(5,50);
                            std::cout<<"Vous avez decide de ne pas attaquer";
                            Sleep(3000);
                            afficherVideTable(5,2);
                        }
                        if(j==1)
                        {
                            afficherVideTable(5,2);
                            gotoligcol(5,133);
                            std::cout<<"Vous avez decide de ne pas attaquer";
                            Sleep(3000);
                            afficherVideTable(5,85);
                        }

        }
    }
    else
    {
        if(j==0)
                        {
                            //afficherVideTable(5,2);
                            gotoligcol(5,50);
                            std::cout<<"Vous n'avez pas assez d energie pour attaquer";
                            Sleep(3000);
                            afficherVideTable(5,2);
                        }
                        if(j==1)
                        {
                            //afficherVideTable(5,2);
                            gotoligcol(5,133);
                            std::cout<<"Vous n'avez pas assez d energie pour attaquer";
                            Sleep(3000);
                            afficherVideTable(5,85);
                        }
    }


    std::vector<Carte*> deck = m_jo[j].getDeck().getCartesD();

    int compteurCrea = 0;
    for(const auto& elem : deck){
        if(elem->getGenre() == 1){
            compteurCrea++;
        }
    }


    if(m_creature[j].size() > 0 && compteurCrea == 0 && energia == 0)
    {
        //Joueur j est out
         std::cout<<"Je suis apres la derniere boucle d'attaque"<<std::endl;

        m_jo[j].setOut(true);
        std::cout<<m_jo[j].getNom()<<" est out!"<<std::endl;

    }



}

Cimetiere Match::getCimetiere()const
{
    return m_cimitiere;
}

