#include<Sommet.hpp>

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
  n_M_histo.push_back(m_N);
}


Sommet ::~Sommet(){};

void reset_N_histo()
{
  n_M_histo.clear();
  n_M_histo.push_back(m_N);
}


int Sommet:: evol_n1_som()
{
  float N_temp_voisins=0.0;
  float N_temp_rythme=0.0;
  for(int i=0; i<m_arc_adj.size();i++)
  {
    N_temp_voisins+=m_arc_adj[i].m_som_debut.m_N*m_arc_adj[i].m_weight;
  }
  N_temp_rythme= m_N + r*m_N*(1-(float)m_N/(float)m_stable);
  m_N=N_temp_rythme-N_temp_voisins;
  n_M_histo.push_back(m_N);

}
