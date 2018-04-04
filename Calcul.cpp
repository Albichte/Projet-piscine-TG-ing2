#include "Calcul.h"
/*
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
  while (queue_som.size()!=0 and queue_som.front()!=s_atrouv)
  {
    for(int i=0;i<queue_som.front().m_succe.size();i++)
    {
      if(queue_som.front().m_succe[i].m_marque==false)
      {
        queue_som.front().m_succe[i].m_marque=true;
        queue_som.push(queue_som.front().m_succe[i]);
      }
    }
    queue_so.pop();
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

vector<Sommet*>  Calcul::compo_f_con_som(Graphe& graphique, Sommet& s1)
{
  //Reset des marquages
  graphique.reset_marquages_som();
  //on déclare la file d'attente et le vecteur pour la composante
  // fortement connexe
  vector<Sommet*> compo_f_con;
  queue<Sommet*> file_attente;
  file_attente.push(&s1);
  while(file_attente.size()!=0)
  {
    for(int i=0;i<file_attente.front().m_succe.size();i++)
    {
      if(file_attente.front().m_succe[i].m_marque==false)
      {
        file_attente.front().m_succe[i].m_marque=true;
        file_attente.push(queue_som.front().m_succe[i]);
      }
    }
    if(file_attente.front()!=s1)
    {
      if(compo_con_inv(graphique, file_attente.fron(),s1))
      {
        compo_f_con.push_back(file_attente.front());
      }
    }
    file_attente.pop();
  }
return compo_f_con;
}

//fonction retournant toutes les composantes connexes
vector<vector<Sommet *>> Calcul:: forte_connex(Graphe& graphique)
{
  vector<vector<Sommet*>> tt_compo_con;
  for(int i=0;i<graphique.m_sommets.size();i++)
  {
    push_back(compo_f_con(graphique,graphique.m_sommets[i]));
  }
  for(int i=0; i<compo_f_con.size();i++)
  {
    tt_compo_con[i].sort(tt_compo_con[i].begin(),tt_compo_con[i].end());
  }
  tt_compo_con.unique();
  return tt_compo_con;

}
*/
