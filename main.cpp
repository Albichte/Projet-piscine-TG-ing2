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

    /// Le nom du r�pertoire o� se trouvent les images � charger
    grman::set_pictures_path("pics");

    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
    while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
        a->update();

        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    a->sauvegarde("deux.txt");
    */
    return 0;
}
END_OF_MAIN();
