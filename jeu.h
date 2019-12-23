#ifndef JEU_H_
#define JEU_H_

extern int nombreLignes;
extern int nombreColonnes;



enum Direction {gauche,droite,haut,bas};

typedef struct Pixel {//définition du pixel
  int x,y;
} Pixel;

typedef struct Snake{// définition  du snake 
  int taille;
  enum Direction direction;
  Pixel* corps;

}Snake;

typedef struct Niveau{
  int numero;
  int score;
  int nombrePastilles;
  Pixel* pastilles;
  Pixel* obstacles;
  Snake snake;

}Niveau;

Pixel genererPixel(int minX, int maxX,int minY, int maxY);


Pixel* genererPastilles(Niveau niveau,int n);//n=nombre de pastilles à générer

int isGameOver(Niveau niveau);



Niveau verifierManger(Niveau niveau);

#endif
