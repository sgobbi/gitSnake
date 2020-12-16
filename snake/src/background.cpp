#include "../include/background.h"
#include <iostream>

Background::Background() 
{
        for (int i = 0; i<bg_nx*bg_ny; i++)
    {
        bgTab[i] = -1;
    }

}

void Background::modif(int i, int val)
{
bgTab[i] = val;
} 

int Background::get_x()
{
    return bg_nx;
}

int Background::get_y()
{
    return bg_ny;
}


void Background::setup()
{
    for(int x=0; x<bg_nx; x++)
    {
        bgTab[x] = 1;   //bordure haute
        bgTab[x + (bg_ny-1)*bg_nx] = 1; //bordure basse
    }
    for(int y=0; y<bg_ny ; y++)
    {
        bgTab[y*bg_nx] = 1; //bordure gauche
        bgTab[bg_nx-1 + y*bg_nx] = 1;  //bordure droite
    }
}

void Background::clear()
{
    int out = system("clear");
    if( out != 0){
        std::cerr << "clear command failed" << std::endl;
        exit(1);
    }
}

void Background::print(int score)
{
    for(int j=0; j<bg_ny ; j++)
    {
        for(int i = 0; i<bg_nx ; i++)
        {
            if(bgTab[i+j*bg_nx]==1)
            {
                std::cout << "#";
            }
            else if(bgTab[i+j*bg_nx]==2)
            {
                std::cout << "o";
            }
            else if(bgTab[i+j*bg_nx]==3)
            {
                std::cout << "$";
            }
            else
            {
                std::cout << " ";
            }
            

        }
        std::cout<< std::endl;

    }

std::cout<<std::endl;
std::cout<< "Longueur du ton snake: " << score << std::endl;

}