//#ifndef DEF_SNAKE
//#define DEF_SNAKE

#include "include/background.h"

class Snake
{
public: 

Snake(); //constructeur
~Snake(); //destructeur
void add(Background &bg;
void remove(Background &bg);
void move(char key);
void setup();
void update();
bool in(Background &bg);
int getPos(int pos);
int getLen();
int getLenMax();
void grow();

private:

int s_len; //Taille snake
static const int s_lenMax;
int snakePos[2 * s_lenMax]; //Création tableau position snake avec taille maximale
int dxdy[2]; //Déplacement unitaire snake




};