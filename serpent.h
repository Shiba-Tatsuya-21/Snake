#ifndef SERPENT_H_
#define SERPENT_H_

#include "jeu.h"

extern enum Direction directionParDefaut;

void initialSnake(Snake* snake);//iniatilise le snake

void mangerPixel(Snake* snake, Pixel pastille);//faire manger pastille au snake

void deplacerSnake(Snake* snake);//déplace le snake 


#endif
