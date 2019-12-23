#include <stdlib.h>
#include<graph.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include "jeu.h"



Pixel genererPixel(int minX, int maxX,int minY, int maxY){
  Pixel p;

  
  
  p.x=(rand() % (maxX - minX +1)+minX);

  p.y=(rand() % (maxY - minY +1)+minY);

  return p;


}

Pixel* genererPastilles(Niveau niveau,int n){

  Pixel*  tab=(Pixel*)malloc(n*sizeof(Pixel));

  int i;

  for(i=0;i<n;i++){

   Pixel p= genererPixel(0,nombreColonnes-1,0,nombreLignes-1);
  
   int j=0,trouve=1;

   while(trouve){
     trouve=0;
   
  
     while(j<i && trouve==0){
     
       j++;
       if(tab[j].x==p.x && tab[j].y==p.y){//vérifie que la place est libre 
	 trouve=1;
       }
     }

     if(!trouve){
       j=0;
       while(j<niveau.snake.taille && trouve==0){
	 if((niveau.snake.corps+j)->x==p.x && (niveau.snake.corps+j)->y==p.y){//vérifie que la place est libre 
	 trouve=1;
       }
       j++;
     }
     }

     if(trouve){
   
       p= genererPixel(0,nombreColonnes,0,nombreLignes);
     }


   }
   tab[i]=p;

  }

  return tab;


}


int isGameOver(Niveau niveau){
  int gameOver=0;
  int i;
  Pixel teteSerpent=niveau.snake.corps[0];

  for(i=0;i<niveau.numero-1;i++){
   
    if(teteSerpent.x==(niveau.obstacles+i)->x && teteSerpent.y==(niveau.obstacles+i)->y){
      gameOver=1;
    }

  }

  for(i=1;i<niveau.snake.taille;i++){
    if(teteSerpent.x==(niveau.snake.corps+i)->x && teteSerpent.y==(niveau.snake.corps+i)->y){
      gameOver=1;
    }

  }



 if(teteSerpent.x<0 || teteSerpent.x>=nombreColonnes || teteSerpent.y<0 || teteSerpent.y>=nombreLignes){
   gameOver=1;
 }

 return gameOver;

}




Niveau verifierManger(Niveau niveau){

  
  int i=0;
  Pixel teteSerpent=niveau.snake.corps[0];
  Pixel teteSerpent1=niveau.snake.corps[1];
  while(i<niveau.nombrePastilles){
   
    if(teteSerpent.x==(niveau.pastilles+i)->x && teteSerpent.y==(niveau.pastilles+i)->y){
      
  

      Pixel pastilleAManger=niveau.pastilles[i];//on sauvegarde la pastilles qui vas etre manger 

     
      int j;
     
      niveau.nombrePastilles-=1;
      for(j=i;j<niveau.nombrePastilles;j++){
	niveau.pastilles[j]=niveau.pastilles[j+1];//on décale toutes les pastilles apres celle manger pour liberer la dernière case 

      }

      

      niveau.score=niveau.score+5;


// niveau.pastilles=(Pixel*)realloc(niveau.pastilles,  niveau.nombrePastilles*sizeof(Pixel));


      mangerPixel(&(niveau.snake), pastilleAManger);

    
    }
      i++;

  }



  return niveau;


}

