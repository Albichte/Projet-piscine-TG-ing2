#include<Sommet.hpp>

Sommet(string nom_im, int num_sommet, int deg, int x, int y, int k, int n, int r)
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


~Sommet(){};

void reset_N_histo()
{
  n_M_histo.clear();
  n_M_histo.push_back(m_N);
}


int Sommet:: evol_n1_som()
{
  
}
