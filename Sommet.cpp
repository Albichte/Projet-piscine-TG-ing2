#include"Sommet.h"
#include"Arc.h"

Sommet :: Sommet(string nom_im, int num_sommet, int deg, int x, int y, int k, int n, float r)
{
  m_nom_im=nom_im;
  m_num_sommet= num_sommet;
  m_deg= deg;
  m_x= x;
  m_y= y;
  m_stable= k;
  m_N= n;
  m_rythme= r;
  m_N_histo.push_back(m_N);
}


Sommet ::~Sommet(){};

void Sommet::reset_N_histo()
{
  m_N_histo.clear();
  m_N_histo.push_back(m_N);
}


void Sommet:: evol_n1_som()
{
  float N_temp_voisins=0.0;
  float N_temp_rythme=0.0;
  for(unsigned int i=0; i<m_arc_adj.size();i++)
  {
    N_temp_voisins+=m_arc_adj[i]->m_som_debut->m_N*m_arc_adj[i]->m_weight;
  }
  N_temp_rythme= m_N + m_rythme*m_N*(1-(float)m_N/(float)m_stable);
  m_N=N_temp_rythme-N_temp_voisins;
  m_N_histo.push_back(m_N);

}
