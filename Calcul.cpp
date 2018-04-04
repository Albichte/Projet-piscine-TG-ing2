#include "Calcul.hpp"

void Calcul:: evol_n1_gene(int tps, Graphe& graphique)
{
  for(int i=0;i<graphique.m_sommets.size();i++)
  {
    graphique.m_sommets[i].evol_n1_som();
  }
}

void Sommet::marq_vois(Sommet& s)
{
  for(int i=0;i<s.m_succe.size();i++)
  {
    s.m_succe[i].m_marque=true;
  }
}

bool compo_con_inv(Graphe& graphique, Sommet& s_deb, Sommet& s_atrouv)
{
  // fonction qui permet de savoir si il existe un chemin d'un sommet
  // à un autre
  //on garde les anciencs marquages en mémoire
  vector<vector<int>> histo_marquage;
  for(int i=0; i<graphique.m_sommets.size();i++)
  {
    histo_marquage.resize(graphique.m_sommets.size());
    histo_marquage[i].push_back(graphique.m_sommets[i].m_num_sommet);
    if(graphique.m_sommets[i].m_marque)
    {
      histo_marquage[i].push_back(1);
    }
    else
    {
      histo_marquage[i].push_back(0);
    }
  }
  // on reset les marquages pour pouvoir faire le BFS sur le graph
  graphique.reset_marquages_som();

  //variables qui sont nescessaires au BFS
  queue<Sommet*> queue_som;
  queue_som.push_back(&s_deb);
  queue_som[0].m_marque=true;
  while (queue_som.size()!=0 and queue.front()!=s_atrouv)
  {
    for(int i=0;i<queue_som.front().m_succe.size();i++)
    {
      if(queue_som.front().m_succe[i].m_marque==false)
      {
        queue_som.front().m_succe[i].m_marque=true;
        queue_som.push(queue_som.front().m_succe[i]);
      }
    }

  }
  if(queue_som.size()==0)
  {
    return false;
  }
  else
  {
    return true;
  }
}






vector<vector<Sommet *>> Calcul:: forte_connex(Graphe& graphique)
{


}
