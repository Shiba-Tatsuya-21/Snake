#ifndef GRAPHIQUE_H_
#define GRAPHIQUE_H_
//#include "serpent.h"
#include "jeu.h"
#include "serpent.h"

//#include<graph.h>
//#include<unistd.h>

//#include "serpent.c"

char* inttostr();

int length();
extern int tailleCarreauEnPixels;
int largeurGrilleJeu;
int hauteurGrilleJeu;
int largeurFenetre;
int hauteurFenetre;

extern int tailleSerpentParDefaut;
extern int nombrePastillesParDefaut;
extern int vitesseJeu;

 Niveau niveau;

int creerFenetreJeu();// a actualiser
void actualiserleNiveau(int niveauActuel);
void actualiserleScore(int score);
int actualiserNiveau(Niveau niveauActuel);
int length(int entier);
char* inttostr(int entier);
int menu();
void options();
int actualiserOptions(int x,int y,int xMoins,int yMoins, int xPlus, int yPlus, int variable);
int jouer();

#endif
