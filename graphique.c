#include<graph.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include "graphique.h"



int length(int entier) {
   int res = 0;
   if (entier == 0)
      return 1;
      
   for (; entier > 0; entier /= 10)
      ++res;

   return res;
}


char* inttostr(int entier) {
   int neg = 0;
   if (entier < 0) {
      neg = 1;
      entier = -entier;
   }
     
   int l = length(entier);
   char* res = (char*) malloc(sizeof(char) * (l + 1 + neg));
   char* tmp = res + l + neg;
   *tmp = '\0';
   tmp--;
   
   if (entier == 0) {
      *tmp = '0';
   } else {
      for (; entier > 0; entier /= 10) {
         *tmp = '0' + entier % 10;
         tmp--;
      }
   }
   
   if (neg)
      *tmp = '-';

   return res;
}

int menu(){

 


  int a=1;
  int premierAffichage=1;
  int gameOver=0;

 
 int x,y;

  while(a==1){

    if( SourisCliquee()){

      x=_X;
      y=_Y;
     
      if(x>=(largeurGrilleJeu/2)-175 && x<=(largeurGrilleJeu/2)+275 && y>=(hauteurGrilleJeu/3) +300 && y<=(hauteurGrilleJeu/3)+375){//quitter
	FermerGraphique();
      }
      if(x>=(largeurGrilleJeu/2)-175 && x<=(largeurGrilleJeu/2)+275 && y>=(hauteurGrilleJeu/3) && y<=(hauteurGrilleJeu/3)+75){//jouer
	ChoisirCouleurDessin(CouleurParNom("White"));
	RemplirRectangle(0,0,1.1*(largeurGrilleJeu),1.05*(hauteurGrilleJeu)+100);
	gameOver=jouer();
	premierAffichage=1;
      }
     
      if(x>=(largeurGrilleJeu/2)-175 && x<=(largeurGrilleJeu/2)+275 && y>=(hauteurGrilleJeu/3)+150 && y<=(hauteurGrilleJeu/3)+225){//option 
	options();
	premierAffichage=1;
      } 


    }

    if(premierAffichage){
      premierAffichage=0;
     

    }

 ChoisirCouleurDessin(CouleurParNom("Black"));
      RemplirRectangle(0,0,1.1*(largeurGrilleJeu),1.05*(hauteurGrilleJeu)+100);
      ChoisirCouleurDessin(CouleurParNom("Gray"));
      RemplirRectangle((largeurGrilleJeu/2)-175,(hauteurGrilleJeu/3),450,75);

      RemplirRectangle((largeurGrilleJeu/2)-175,(hauteurGrilleJeu/3) +150,450,75);

      RemplirRectangle((largeurGrilleJeu/2)-175,(hauteurGrilleJeu/3) +300,450,75); 
 
      ChoisirCouleurDessin(CouleurParNom("Yellow"));
      EcrireTexte((largeurGrilleJeu/2)-50,(hauteurGrilleJeu/3)-100,"JEU DE SNAKE :",2);
      if(gameOver){
	ChoisirCouleurDessin(CouleurParNom("Red"));
	EcrireTexte((largeurGrilleJeu/2)-150,(hauteurGrilleJeu/3)-40,"Perdu niveau:",2);
	EcrireTexte((largeurGrilleJeu/2)+20,(hauteurGrilleJeu/3)-40,inttostr(niveau.numero),2);
	EcrireTexte((largeurGrilleJeu/2)+90,(hauteurGrilleJeu/3)-40,"score de:",2);
	EcrireTexte((largeurGrilleJeu/2)+210,(hauteurGrilleJeu/3)-40,inttostr(niveau.score),2);
      }

      ChoisirCouleurDessin(CouleurParNom("Blue"));
      EcrireTexte((largeurGrilleJeu/2),(hauteurGrilleJeu/3)+50,"JOUER",2);

      EcrireTexte((largeurGrilleJeu/2),(hauteurGrilleJeu/3)+200,"OPTIONS",2);
      EcrireTexte((largeurGrilleJeu/2),(hauteurGrilleJeu/3)+350,"QUITTER",2);

      CopierZone(1,0,0,0,largeurFenetre,hauteurFenetre,0,0);
       usleep(100000);
  }


 
  return a;
}

void options(){

nombrePastillesParDefaut+=1;
 
  int b=1;
 

 int x,y;

  while(b==1){
    
    if(SourisCliquee()){
      x=_X;
      y=_Y;
   
    tailleSerpentParDefaut=actualiserOptions(x,y,(largeurGrilleJeu/2)-20,(hauteurGrilleJeu/3)+200,(largeurGrilleJeu/2)+35,(hauteurGrilleJeu/3)+200,tailleSerpentParDefaut);

   nombreLignes=actualiserOptions(x,y,(largeurGrilleJeu/2)-20,(hauteurGrilleJeu/3)+50,(largeurGrilleJeu/2)+35,(hauteurGrilleJeu/3)+50,nombreLignes);

 nombreColonnes=actualiserOptions(x,y,(largeurGrilleJeu/2)+180,(hauteurGrilleJeu/3)+50,(largeurGrilleJeu/2)+250,(hauteurGrilleJeu/3)+50,nombreColonnes);

 nombrePastillesParDefaut=actualiserOptions(x,y,(largeurGrilleJeu/2)-20,(hauteurGrilleJeu/3)+350,(largeurGrilleJeu/2)+35,(hauteurGrilleJeu/3)+350,nombrePastillesParDefaut);


    
  
 



 if(10<=x && x<= 110 && 10<=y && y<=60){
  nombrePastillesParDefaut-=1;
   largeurGrilleJeu=nombreColonnes*tailleCarreauEnPixels;
  hauteurGrilleJeu=nombreLignes*tailleCarreauEnPixels;
  largeurFenetre=largeurGrilleJeu*1.1;
  hauteurFenetre=hauteurGrilleJeu*1.05+100;
  niveau.nombrePastilles=niveau.numero+nombrePastillesParDefaut;
  FermerGraphique();
  creerFenetreJeu();




  b=2;
 
 }


    }

  ChoisirCouleurDessin(CouleurParNom("Black"));
  RemplirRectangle(0,0,1.1*(largeurGrilleJeu),1.05*(hauteurGrilleJeu)+100);
    ChoisirCouleurDessin(CouleurParNom("Gray"));
    RemplirRectangle(10,10,100,50);
    RemplirRectangle(0,(hauteurGrilleJeu/3),1.1*largeurGrilleJeu,75);
    RemplirRectangle(0,(hauteurGrilleJeu/3) +150,1.1*largeurFenetre,75);
    RemplirRectangle(0,(hauteurGrilleJeu/3) +300,1.1*largeurFenetre,75); 
 
  ChoisirCouleurDessin(CouleurParNom("Yellow"));
 EcrireTexte((largeurGrilleJeu/2)-50,(hauteurGrilleJeu/3)-100,"OPTIONS :",2);

  ChoisirCouleurDessin(CouleurParNom("Blue"));
 EcrireTexte(10,(hauteurGrilleJeu/3)+50,"TAILLE GRILLE :",2);
 EcrireTexte(20,45,"Retour",2);
 EcrireTexte(10,(hauteurGrilleJeu/3)+200,"TAILLE SNAKE :",2);
 EcrireTexte(10,(hauteurGrilleJeu/3)+350,"PASTILLES :",2);


  EcrireTexte((largeurGrilleJeu/2),(hauteurGrilleJeu/3)+200,inttostr(tailleSerpentParDefaut),2); 
  EcrireTexte((largeurGrilleJeu/2)-20,(hauteurGrilleJeu/3)+200,"-",2); 
  EcrireTexte((largeurGrilleJeu/2)+35,(hauteurGrilleJeu/3)+200,"+",2); 

  EcrireTexte((largeurGrilleJeu/2),(hauteurGrilleJeu/3)+350,inttostr(nombrePastillesParDefaut),2); 
 EcrireTexte((largeurGrilleJeu/2)-20,(hauteurGrilleJeu/3)+350,"-",2);
 EcrireTexte((largeurGrilleJeu/2)+35,(hauteurGrilleJeu/3)+350,"+",2);


 EcrireTexte((largeurGrilleJeu/2),(hauteurGrilleJeu/3)+50,inttostr(nombreLignes),2); 

 EcrireTexte((largeurGrilleJeu/2)-20,(hauteurGrilleJeu/3)+50,"-",2); 
 EcrireTexte((largeurGrilleJeu/2)+35,(hauteurGrilleJeu/3)+50,"+",2); 


 EcrireTexte((largeurGrilleJeu/2)+200,(hauteurGrilleJeu/3)+50,inttostr(nombreColonnes),2);
 EcrireTexte((largeurGrilleJeu/2)+180,(hauteurGrilleJeu/3)+50,"-",2);
 EcrireTexte((largeurGrilleJeu/2)+250,(hauteurGrilleJeu/3)+50,"+",2);


 CopierZone(1,0,0,0,largeurFenetre,hauteurFenetre,0,0);
  usleep(100000);
  }
  
  //ChoisirCouleurDessin(CouleurParNom("White"));
  //RemplirRectangle(0,0,1.1*(largeurGrilleJeu),1.05*(hauteurGrilleJeu)+100);
 

}

int actualiserOptions(int x,int y,int xMoins,int yMoins, int xPlus, int yPlus, int variable){
 
  int marge=15;
  int boutonClique=0;
 
  if((xMoins-marge<=x && x<=xMoins+marge) && (yMoins-marge<=y && y<=yMoins+marge)){//Si on clique sur le bouton -
    variable--;
    boutonClique=1;
  }
  else if((xPlus-marge<=x && x<=xPlus+marge) && (yPlus-marge<=y && y<=yPlus+marge)){//Si on clique sur le bouton +

    variable++;
    boutonClique=1;

  }
  if(boutonClique==1){
    ChoisirCouleurDessin(CouleurParNom("Gray"));
    RemplirRectangle(xMoins-marge,yMoins-1.5*marge,80,40);
    ChoisirCouleurDessin(CouleurParNom("Blue"));
    EcrireTexte(xMoins+20,yMoins,inttostr(variable),2); 
    EcrireTexte(xMoins,yMoins,"-",2); 
    EcrireTexte(xPlus,yPlus,"+",2);


  }


  return variable;


}

int creerFenetreJeu(){
  
  InitialiserGraphique();
  CreerFenetre(0,0,largeurFenetre,hauteurFenetre);
 
  // ChoisirCouleurDessin(CouleurParNom("Black"));
  // RemplirRectangle(0,0,largeurFenetre,hauteurFenetre);

}

int actualiserNiveau(Niveau niveauActuel){
  //pour créer le bon nombre de pastille faire nombre de pastilleniveauActuel+4
  //pour créer le bon nombre d'obsctacle utiliser simplement niveauActuel
  
  couleur c;
  int i;


ChoisirCouleurDessin(CouleurParNom("Green"));
 RemplirRectangle(0.05*largeurFenetre,0.05*hauteurFenetre,largeurGrilleJeu,hauteurGrilleJeu);

ChoisirCouleurDessin(CouleurParNom("Red"));
  for(i=0;i<niveauActuel.nombrePastilles;i++){
  
    RemplirRectangle(0.05*largeurFenetre+tailleCarreauEnPixels*(niveauActuel.pastilles+i)->x,0.05*hauteurFenetre+tailleCarreauEnPixels*(niveauActuel.pastilles+i)->y,tailleCarreauEnPixels,tailleCarreauEnPixels);// dessin des pastilles 

 

  }




ChoisirCouleurDessin(CouleurParNom("Gray"));
  for(i=0;i<niveauActuel.numero-1;i++){
  
    RemplirRectangle(0.05*largeurFenetre+tailleCarreauEnPixels*(niveauActuel.obstacles+i)->x,0.05*hauteurFenetre+tailleCarreauEnPixels*(niveauActuel.obstacles+i)->y,tailleCarreauEnPixels,tailleCarreauEnPixels);// dessin des obstacles 
 
 

  }










ChoisirCouleurDessin(CouleurParNom("Yellow"));
  for(i=0;i<niveauActuel.snake.taille;i++){

  RemplirRectangle(0.05*largeurFenetre+tailleCarreauEnPixels*(niveauActuel.snake.corps+i)->x,0.05*hauteurFenetre+tailleCarreauEnPixels*(niveauActuel.snake.corps+i)->y,tailleCarreauEnPixels,tailleCarreauEnPixels);// dessin du serpent 

  }

  //probleme le serpent ne bouge plus car le programme attend a chaque fois 59 min avant de faire bouger le serpent
  /*  c=CouleurParNom("Black");
   ChoisirCouleurDessin(c);
   RemplirRectangle(30,440,80,480);
   actualiserTemps();

  */
 CopierZone(1,0,0,0,largeurFenetre,hauteurFenetre,0,0);
  return 1;

}

void actualiserleNiveau(int niveauActuel){

 
 ChoisirCouleurDessin(CouleurParNom("White"));
 RemplirRectangle((0.333+0.05)*largeurGrilleJeu-120,1.05*hauteurGrilleJeu+33,170,600);
 
  couleur d;
  d=CouleurParNom("Black");
    ChoisirCouleurDessin(d);
    EcrireTexte((0.333+0.05)*largeurGrilleJeu-100,1.05*hauteurGrilleJeu+66,"Niveau :",2);
 EcrireTexte((0.333+0.05)*largeurGrilleJeu,1.05*hauteurGrilleJeu+66,inttostr(niveauActuel),2);


}


void actualiserleScore(int score){

 ChoisirCouleurDessin(CouleurParNom("White"));
 RemplirRectangle((0.666+0.05)*largeurGrilleJeu-70,1.05*hauteurGrilleJeu+33,440,600);
 
  couleur d;
  d=CouleurParNom("Black");
    ChoisirCouleurDessin(d);
 EcrireTexte((0.666+0.05)*largeurGrilleJeu-50,1.05*hauteurGrilleJeu+66,"Score :",2);
 EcrireTexte((0.666+0.05)*largeurGrilleJeu+40,1.05*hauteurGrilleJeu+66,inttostr(score),2);


}







int jouer(){



  niveau.score=0;
  niveau.numero=1;
int gameOver=0;
 int quitterPause;
 // int page=0;
 //ChoisirEcran(0);
 do{
    //  setactivepage(page);
    // setvisualpage(1 - page);



actualiserleNiveau(niveau.numero);
  Snake snake;
  initialSnake(&snake);
  snake.direction=gauche;

  int i;
  for(i=0;i<tailleSerpentParDefaut;i++){
    Pixel p;
    p.y=nombreLignes/2;
    p.x=(nombreColonnes-tailleSerpentParDefaut)/2+i;

     snake.corps= (Pixel*)realloc(snake.corps,sizeof(Pixel)*(snake.taille+1));
     snake.taille +=1 ;
     snake.corps[snake.taille-1]=p;


  }

   
  
   niveau.nombrePastilles=niveau.numero+nombrePastillesParDefaut;
   niveau.snake=snake;
   niveau.pastilles=genererPastilles(niveau,niveau.nombrePastilles);
   niveau.obstacles=genererPastilles(niveau,niveau.numero-1);
   

 actualiserNiveau(niveau);

  if(niveau.numero>1){
       quitterPause=0;
    
       while(!quitterPause){
	 if(ToucheEnAttente()){
	   if( Touche()==XK_space){
	     quitterPause=1;
	   }
	   
	 }
       }

   }

 
 while(!gameOver && niveau.nombrePastilles>0){
   

   if(ToucheEnAttente()){

     int touche=Touche();
     if(touche == XK_Left){
       if( niveau.snake.direction != droite){
	  niveau.snake.direction = gauche;
       }

     }
     else if(touche == XK_Right){
       if( niveau.snake.direction != gauche){
	  niveau.snake.direction = droite;
       }
     }
     else if(touche == XK_Up){
       if( niveau.snake.direction != bas){
	  niveau.snake.direction = haut;
       }
     }
     else if(touche == XK_Down){
       if( niveau.snake.direction != haut){
	  niveau.snake.direction = bas;
       }
     }
     else if(touche == XK_space){
       quitterPause=0;
       while(!quitterPause){
	 if(ToucheEnAttente()){
	   if( Touche()==XK_space){
	     quitterPause=1;
	   }
	   
	 }
       }
     
     }
     else if(touche == XK_Escape){

       return gameOver;
     }

    }  

  deplacerSnake(&niveau.snake);
  niveau=verifierManger(niveau);
  
  actualiserleScore(niveau.score);
  gameOver=isGameOver(niveau);



  if(!gameOver){//utile pour ne pas que le snake sorte de 1 case avant de mourrir
    actualiserNiveau(niveau);
   
   usleep(vitesseJeu);// utiliser plutot la fonction usleep c'est en microseconde s


  }
 
  CopierZone(1,0,0,0,largeurFenetre,hauteurFenetre,0,0);
 
 }

 if(!gameOver){ //Si on a complété le niveau actuel, on doit passer au niveau suivant
   niveau.numero+=1;
   vitesseJeu*=0.9;


 }
 // page = 1- page; double buffer 

 }while(!gameOver);
	



 return gameOver;

}
