#include "speciales.h"
#include "energie.h"
#include "boutique.h"
#include "deck.h"
#include "Cimetiere.h"
#include "collection.h"
#include "attaque.h"
#include "carte.h"
#include "creature.h"
#include "jeu.h"
#include "joueur.h"

int main()
{


    nomJeu();
    system("cls");
    Jeu game;

    game.deroulement();

   /* int choix;
    do
    {
        gotoligcol(5,33);
        std::cout<<"________________________________________________";//affichage du menu centré sur l'écran
        gotoligcol(8,43);
        std::cout<<"* Bienvenue dans WINXMON *";
        gotoligcol(11,45);
        std::cout <<"Que voulez vous faire : ";
        gotoligcol(13,45);
        std::cout << "1. Afficher les regles";
        gotoligcol(15,45);
        std::cout<< "2. Commencer un nouveau match";
        gotoligcol(17,45);
        std::cout<< "3. Ouvrir la boutique";
        gotoligcol(19,45);
        std::cout<< "4. Quitter le jeu";
        gotoligcol(22,33);
        std::cout<<"________________________________________________";
        gotoligcol(26,5);
        std::cin >> choix;
        if(std::cin.fail())
        {
            system("cls");
            gotoligcol(24,5);
            std::cerr << "Erreur, saisie incorrecte." << std::endl;

            vider_buffer(); // On remet cin dans un état valide et vide le buffer
        }
        else if(choix > 4 || choix < 1)
        {
            gotoligcol(24,5);
            std::cout << "Veuillez rentrer une valeur entre 1 et 4 svp";
        }

    }while(choix>4 || choix<1);*/

    /*Creature c1("nom","des",2,2,"lumiere",2,45);
    c1.ajouter("attaque",20,"lum",54,0);
    c1.afficher(1,1);
    //std::cout<<c1.getLP();
    Spe1 c2;
    c2.afficher(15,1);
    Energie e("nom","ernergie",2,4,5,"techno",2,3);
    e.afficher(1,30);*/
    return 0;
}
