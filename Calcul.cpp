#include "Calcul.hpp"

void Calcul:: evol_n1_gene(int tps, Graphe& graphique)
{
  for(int i=0;i<graphique.m_sommets.size();i++)
  {
    graphique.m_sommets[i].evol_n1_som();
  }
}

void Sommet::marq_vois(Graphe& graphique, Sommet& s)
{
  for(int i=0;i<s.m_succe.size();i++)
  {
    s.m_succe[i].m_marque=true;
  }
}

bool compo_con_inv(Graphe& graphique, Sommet& s_deb, Sommet& s_atrouv)
{
  return false;
}






vector<vector<Sommet *>> Calcul:: forte_connex(Graphe& graphique)
{

}
