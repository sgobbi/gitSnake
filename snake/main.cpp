#include <iostream>
#include "sys/ioctl.h"

#include "stdlib.h"

#include "include/internals.h"
#include "include/food.h"




void startGame(const int& lap, Snake sk, Background bg){
    
     /*
  Fonction principale de la gestion du jeu et de l'affichage.
  Entrées :
    - lap : temps de rafraichissement
    - snake : serpent
    - bg : terrain de jeu
  */

    char key;  // detection touche 
    Food food;

    food.createFood(bg, sk);

    while( true ){
        internal::frameSleep(lap);
        if( internal::keyEvent() ){
            std::cin >> key; 
            sk.move(key);
        }
        bg.clear();
        sk.add(bg);
        bg.setup();
        
        int score = sk.getLen();
        int lenMax = sk.getLenMax();
        bg.print(score);
        sk.remove(bg);

        
        bool in =  sk.in(bg);
        if(in == false){
            std::cout << std::endl << std::endl<< "PERDU!!"<< std::endl;
            std::cerr<<""<< std::endl;
            exit(1);
        }

        if (score==lenMax)
        {
          std::cout << std::endl << std::endl << "GAGNE!!"<< std::endl;
          std::cerr << ""<< std::endl;
        }

        bool eat = food.eatFood(sk);
        if(eat){
            food.createFood(bg, sk);
            sk.grow();
        }
        sk.update();

    }
}



int main(){
    
    const int lap=200;

    Background bg;
    Snake sk;
    
   bg.clear();
   bg.setup();
   sk.setup()


    startGame(lap, sk,bg);

}



