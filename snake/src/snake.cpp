#include "../include/snake.h"


Snake::Snake() 
{
s_len = 3;
dxdy[0] = 1;
dxdy[1] = 0;
}


void Snake::add(Background &bg)  // ajoute le snake sur le bg 
{ 
    for (int i=0; i<s_len; i++)
    {
        int s_x = snakePos[i];
        int s_y = snakePos[s_lenMax + i];
        int ind = s_x + bg.get_x()*s_y;
        bg.modif(ind, 2);
    }
}

void Snake::remove(Background &bg)
{
    for (int i=0; i<s_len; i++) 
    {
        int s_x = snakePos[i];
        int s_y = snakePos[s_lenMax + i];
        int ind = s_x + bg.get_x()*s_y;
        bg.modif(ind, -1);
    }
}

void Snake::move(char key)
{
    if ( (key=='w') and (dxdy[1]!=1) ) { //Haut
            dxdy[0] = 0; dxdy[1] = -1;
        }
        if ( (key=='s') and (dxdy[1]!=-1) ) { //Bas
            dxdy[0] = 0; dxdy[1] = 1;
        }
        if ( (key=='d') and (dxdy[0]!=-1) ) { //Droite
            dxdy[0] = 1; dxdy[1] = 0;
        }
        if ( (key=='a') and (dxdy[0]!=1) ) { //Gauche
            dxdy[0] = -1; dxdy[1] = 0;
        }
}

void Snake::setup()
{
     int yi = 5; //Ligne de départ
        int xi = 5; //Colonne de départ

        for (int i=0; i<s_len; i++)  //Départ vertical
        {
            snakePos[i] = xi - i;
            snakePos[s_lenMax + i] = yi;
        }
}

void Snake::update()
{
    for(int i=s_len-1; i>0; i--)
    {
        snakePos[i] = snakePos[i-1];
        snakePos[s_lenMax + i] = snakePos[s_lenMax + i - 1];
    }
    // ajout de la nouvelle tete
    snakePos[0] = snakePos[0] + dxdy[0];
    snakePos[s_lenMax] = snakePos[s_lenMax] + dxdy[1];
    
}

bool Snake::in(Background &bg) //verifie si sorti ou si il a mangé sa queue
{
bool verif = true;
int nx = bg.get_x();
int ny = bg.get_y();

if((snakePos[0]<=0) or (snakePos[0]>= nx - 1) or (snakePos[s_len]<=0) or (snakePos[s_len]>ny) )
{
    verif = false;
}
/*for (int i=0; i<s_len; i++)
{
    if((snakePos[0]==snakePos[i]) && (snakePos[s_lenMax]==snakePos[s_lenMax+i]))
    {
        verif = false;
    }

} */
return verif;
}

int Snake::getPos(int pos)
{
    return snakePos[pos];
}

int Snake::getLen()
{
    return s_len;
}

int Snake::getLenMax()
{
    return s_lenMax;
}

void Snake::grow()
{
    s_len++;
}

void Snake::modif(int i, int val)
{
    snakePos[i] = val;
}