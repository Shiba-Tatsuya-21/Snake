
/* TEST INITSNAKE,MOVESNAKE,MANGERPASTILLE
#include "serpent.c"


int main(){

  Snake snakeTest;
  initialSnake(&snakeTest);


  Pixel p1,p2,p3,p4;

  p1.x=2;p1.y=1;
  p2.x=1;p2.y=1;
  p3.x=1;p3.y=2;
  p4.x=1;p4.y=3;

  mangerPixel(&snakeTest,p1);
  // mangerPixel(&snakeTest,p2);
  snakeTest.direction=bas;
   mangerPixel(&snakeTest,p3);
  //mangerPixel(&snakeTest,p4);



  printf("Taille du serpent: %d\n",snakeTest.taille);

  int i;
  for(i=0;i<snakeTest.taille;i++){
    printf("{%d,%d}, ",(snakeTest.corps[i]).x,(snakeTest.corps[i]).y);

  }

  printf("\n\nDéplacement du serpent:\n\n");

  deplacerSnake(&snakeTest);

  for(i=0;i<snakeTest.taille;i++){
    printf("{%d,%d}, ",(snakeTest.corps[i]).x,(snakeTest.corps[i]).y);

  }
  
  return 0;
}
*/
/* //test generation 1 pastille 
#include "jeu.c"

int main(){
  
  srand(time(NULL));
  Pixel pTest;

  pTest=genererPixel(0,40,0,20);
  printf("%d %d\n",pTest.x,pTest.y);

  pTest=genererPixel(0,40,0,20);
  printf("%d %d\n",pTest.x,pTest.y);

  pTest=genererPixel(0,40,0,20);
  printf("%d %d\n",pTest.x,pTest.y);


}
*/
/*
#include "jeu.c"

int main(){
  
  srand(time(NULL));
  int n=10;
  Pixel* tab;

  tab=genererPastilles(n);

  int i;

  for(i=0;i<n;i++){

    printf("%d, %d\n",(tab[i]).x,(tab[i]).y);


  }


  return 0;
}
*/

/*
Test de la fenêtre graphique, dessin des pastilles et du serpent

*/


#include<graph.h>
#include<unistd.h>

#include "graphique.h"


int nombreLignes=40;
int nombreColonnes=60;
int tailleCarreauEnPixels=10;
int tailleSerpentParDefaut=10;
int nombrePastillesParDefaut=4;
int vitesseJeu=300000;
 enum Direction directionParDefaut=gauche;

int main(){
 largeurGrilleJeu=nombreColonnes*tailleCarreauEnPixels;
  hauteurGrilleJeu=nombreLignes*tailleCarreauEnPixels;
  largeurFenetre=largeurGrilleJeu*1.1;
  hauteurFenetre=hauteurGrilleJeu*1.05+100;

 srand(time(NULL));
 creerFenetreJeu();
 ChoisirEcran(1);
 menu();
 
  return 0;
}
