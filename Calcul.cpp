#include "Calcul.hpp"

void Calcul:: evol_n1_gene(int tps, Graphe& graphique)
{
  for(int i=0;i<graphique.m_sommets.size();i++)
  {
    graphique.m_sommets[i].evol_n1_som();
  }
}
