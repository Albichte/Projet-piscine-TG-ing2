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
}
~Sommet(){};
