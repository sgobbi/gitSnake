//#ifndef DEF_BG
//#define DEF_BG

class Background
{
public:

Background(); //constructeur
~Background(); //destructeur 
void modif(int i, int val); //modifier une valeur dans le bg
void setup(); //initialisation des bordures
void clear(); // nettoyage complet de la console
void print(int score); // affiche tout dans la console 
int get_x(); // renvoie bg_nx
int get_y(); // renvoie bg_ny

 

private:
static const int bg_nx;
static const int bg_ny;
int bgTab[bg_nx*bg_ny];



};