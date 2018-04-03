#ifndef Calcul_hpp
#define Calcul_hpp
#include "Sommet.hpp"
#include "Graphe.hpp"
#include <vector>

class Graphe;
class Calcul
{
  friend class Graphe;
public:
  vector<vector<Sommet *>> forte_connex(Graphe& graphique);
  /* marque les sommets pour les compo conn
  retourner un vector<vector<int/Somemts>> pour savoir les sommet qui font partie
  des compo connexes. */
  int k_con(Graphe& graphique); // retourne le mini d'arêtes à déco pour casser la connexité
  void evol_n1_gene(int tps, Graphe& graphique); /* exécuté toute les fonctions permettant de trouver un+1 en
  fonction de un.  tps correspond à la durée sur laquelle on fait la simulation



  fonction de un.  tps correspond à la durée sur laquelle on fait la simulation*/

};


#endif // Calcul_hpp
