#include "Arc.hpp"
#include "Sommet.hpp"

Arc::Arc(Sommet& s1, Sommet& s2, float weight, int num_arc)
{
  *m_som_debut= &s1;
  *m_som_fin= &s2;
  m_weight=weight;
  m_num_arc=num_arc;
}

Arc::~Arc(){} // demander prof si destruction pointeur
