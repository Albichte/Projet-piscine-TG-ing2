#ifndef Calcul_hpp
#define Calcul_hpp
#include "Sommet.hpp"
#incude <vector>

class Calcul
{
public:
  vector<vector<Sommet *>> forte_connex(Graphe graphique);
  /* marque les sommets pour les compo conn
  retourner un vector<vector<int/Somemts>> pour savoir les sommet qui font partie
  des compo connexes. */
  int k_con(); // retourne le mini d'arêtes à déco pour casser la connexité
  void évolue_n1_gene(int tps); /* exécuté toute les fonctions permettant de trouver un+1 en
  fonction de un.  tps correspond à la durée sur laquelle on fait la simulation



  fonction de un.  tps correspond à la durée sur laquelle on fait la simulation*/

};


#endif // Calcul_hpp
