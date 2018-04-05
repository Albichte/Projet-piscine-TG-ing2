#include "grman/grman.h"
#include <iostream>

#include "test.h"

#include <iostream>
#include "Graphe.h"
#include "Calcul.h"
#include "Sommet.h"
#include "Arc.h"
#include "Menu.h"
using namespace std;

int main()
{

    //intialisation grman
    grman::init();
    //identification du fichier images
    grman::set_pictures_path("images");


    //creer objet menu principal
    Menup *acceuil;
    acceuil=new Menup();

    acceuil->menuprincipal();

    grman::fermer_allegro();

    delete acceuil;

    return 0;
}
END_OF_MAIN();
