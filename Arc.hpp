#ifndef Arc_hpp
#define Arc_hpp
#include "Sommet"
using namespace std;

class Arc
{
private:
  Sommet* m_som_debut;
  Sommet* m_som_fin;
  float m_weight;
  int m_num_arc;
  bool m_actif;
  bool m_marque;



};

#endif
