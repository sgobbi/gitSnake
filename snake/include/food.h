#pragma once

//#ifndef DEF_FOOD
//#define DEF_FOOD



#include "../include/background.h"
#include "../include/snake.h"

class Food
{
public:
Food(); //constructeur 
void createFood(Background &bg, Snake &sk);
bool eatFood(Snake &sk);

private:
int food[2];
};




