#include "stdlib.h"
#include "../include/food.h"



Food::Food(): food[0]=0, food[1]=0
{
}

void Food::createFood(Background &bg, Snake &sk){
    if( food[0] == 0)
    {
        int nx = bg.get_x();
        int ny = bg.get_y();
        bool valid = false; //pour faire en sorte que le food il est pas sur le snake 
        while(!valid)
        {
            food[0] = rand()%(nx-2) + 2;
            food[1] = rand()%(ny-2) + 2;

            int len = sk.getLen();
            int lenMax = sk.getLenMax();

            int compteur = 0;

            for(int i=0;i<=len;i++)
            {
                int posX = sk.getPos(i);
                int posY = sk.getPos(lenMax + i);
                if (posX==food[0] && posY==food[1])
                {
                    compteur++
                }
            }
            if (compteur==0)
            {
                valid = true;
            }
           
        }
        bg.modif(food[0]+nx*food[1], 2);
        
    }
}

bool Food::eatFood(Snake sk){
    int lenMax = sk.getLenMax();
    int posX = sk.getPos(0);
    int posY = sk.getPos(lenMax)
    if( (food[0]== posX) && (food[1] == posY) ){
        food[0] = 0;
        food[1] = 0;
        return true;
    }
    return false;
}