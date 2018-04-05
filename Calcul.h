#ifndef CALCUL_H_INCLUDED
#define CALCUL_H_INCLUDED
#include "Sommet.h"
//#include "Graphe.h"
#include <vector>
#include <queue>
#include "Graphe.h"

class Graphe;
class Calcul
{
    friend class Graphe;
public:
    vector<vector<Sommet *>> forte_connex(Graphe* graphique); /*marque les sommets pour les compo conn
  retourner un vector<vector<int* Somemts>> pour savoir les sommet qui font partie
  des compo connexes.*/
    int k_con(Graphe* graphique); // retourne le mini d'arêtes à déco pour casser la connexité
    void evol_n1_gene(int tps, Graphe* graphique);  /* exécuté toute les fonctions permettant de trouver un+1 en
  fonction de un.  tps correspond à la durée sur laquelle on fait la simulation */
    bool compo_con_inv(Graphe* graphique, Sommet* s_deb, Sommet* s_atrouv);
    void marq_vois(Sommet* s);
    vector<Sommet*>  compo_f_con_som(Graphe* graphique, Sommet* s1);
    bool connexe(Graphe* graphique);
    bool tt_possi(Graphe* graphique, int i);

};


#endif // CALCUL_H_INCLUDED
