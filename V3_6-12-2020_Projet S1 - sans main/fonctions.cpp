#include "fonctions.h"

///////////////////////////////////////
// Nom du sous-programme : gotolicol
// Rôle : manipulation du curseur
// Source : Campus
///////////////////////////////////////
void gotoligcol( int lig, int col )
{
// ressources
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

///////////////////////////////////////
// Nom du sous-programme : COLOR
// Rôle : change la couleur du texte dans la console, ainsi que la couleur du fond pour la ligne
// Source : Campus
///////////////////////////////////////
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

///////////////////////////////////////////////////////////////////////
//SOURCE :https://pub.phyks.me/sdz/sdz/la-saisie-securisee-en-c.html///
//Sous programme permettant le blindage de saisie                   ///
///////////////////////////////////////////////////////////////////////

void vider_buffer()
{
    std::cin.clear();
    std::cin.seekg(0, std::ios::end);

    if(!std::cin.fail())
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
    }

    else
    {
        std::cin.clear(); // Le flux est dasn un état invalide donc on le remet en état valide
    }
}


////////////////////
/////AFFICHAGE//////
////////////////////

void nomJeu()
{
    gotoligcol(20,60);//position de l'affichage
    Color(15,0);//code couleur blanc
    Sleep(200);
    std::cout<<"**********************************************";
    gotoligcol(26,60);
    Color(15,0);
    std::cout<<"**********************************************";
    gotoligcol(23,60);
    std::cout<<"*";
    gotoligcol(23,105);
    std::cout<<"*";
    gotoligcol(23,73);
    Color(12,0);
    std::cout<<"W  ";
    Sleep(200);//pause entre les mots
    Color(14,0);
    std::cout<<"I  ";
    Sleep(200);
    Color(5,0);
    std::cout<<"N  ";
    Sleep(200);
    Color(2,0);
    std::cout<<"X  ";
    Sleep(200);
    Color(4,0);
    std::cout<<"M  ";
    Sleep(200);
    Color(9,0);
    std::cout<<"O  ";
    Sleep(200);
    Color(10,0);
    std::cout<<"N  ";
    //Sleep(300);
    gotoligcol(25,33);
    Color(7,0);//repasse en blanc
    Sleep(2000);//attente de 2s
    //system("cls");//efface la console
}
