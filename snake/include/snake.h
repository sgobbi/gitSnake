#pragma once 

//#ifndef DEF_SNAKE
//#define DEF_SNAKE

#include "background.h"
#include "food.h"

class Snake
{
public: 

Snake(); //constructeur
void add(Background &bg);
void remove(Background &bg);
void move(char key);
void setup();
void update();
bool in(Background &bg);
int getPos(int pos);
int getLen();
int getLenMax();
void grow();
void modif(int i, int val);

private:

int s_len; //Taille snake
static const int s_lenMax = 50;
int snakePos[2 * s_lenMax]; //Création tableau position snake avec taille maximale
int dxdy[2]; //Déplacement unitaire snake




};