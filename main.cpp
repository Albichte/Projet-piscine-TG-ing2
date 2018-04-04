#include "grman/grman.h"
#include <iostream>

#include "test.h"

#include <iostream>
#include "Graphe.h"
#include "Calcul.h"
#include "Sommet.h"
#include "Arc.h"
using namespace std;

int main()
{
    Graphe* a;
    a=new Graphe ("prem.txt");
    delete a;
    /*
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        a->update();

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    a->sauvegarde("deux.txt");
    */
    return 0;
}
END_OF_MAIN();
