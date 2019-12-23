// s'occupe juste du serpent niveau 
#include "serpent.h"
#include <stdio.h>
#include <stdlib.h>
#include<graph.h>
#include<unistd.h>


void initialSnake(Snake* snake){

  snake->taille=0;
  snake->direction=directionParDefaut;
  snake->corps=NULL;

}


void mangerPixel(Snake* snake, Pixel pastille){




 snake->corps= (Pixel*)realloc(snake->corps,sizeof(Pixel)*(snake->taille+2));
 snake->taille +=2 ;
 int i;

 for(i=snake->taille-1;i>=2;i--){
   snake->corps[i]=snake->corps[i-2];// décale l'interieur du corps du serpent de 2 case pour mettre les nouvelle valeurs pres de la tete du serpent 
 }
 snake->corps[1]=pastille;
 snake->corps[0]=pastille;

 if(snake->direction==gauche){
   (snake->corps[0]).x-=1;
 }

 else if(snake->direction==droite){
(snake->corps[0]).x+=1;
 }

else if(snake->direction==haut){
(snake->corps[0]).y-=1;
 }
 else 
   {
(snake->corps[0]).y+=1;

   }
}

void deplacerSnake(Snake* snake){

 int i;

 for(i=snake->taille-1;i>=1;i--){
   snake->corps[i]=snake->corps[i-1];// supprime la derniere case du serpent. décale de la tete jusqua la queue de 1 case et on ajoute une nouvelle case a la tete.
 }

 

 if(snake->direction==gauche){
   (snake->corps[0]).x-=1; 
 }

 else if(snake->direction==droite){
(snake->corps[0]).x+=1;
  }

else if(snake->direction==haut){
(snake->corps[0]).y-=1;
 }
 else 
   {
(snake->corps[0]).y+=1;
   }

 //appel a la fonction game over 


}

