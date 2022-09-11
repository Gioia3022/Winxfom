#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <windows.h>
#include <iostream>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <ctime>

//fichier pour ecrire les fonctions predefinies dont on a besoin
/////////// PROTOTYPES DES SOUS-PROGRAMMES/////////

void gotoligcol( int lig, int col );
void Color(int couleurDuTexte,int couleurDeFond);
void vider_buffer();
void nomJeu();

#endif // FONCTIONS_H_INCLUDED
