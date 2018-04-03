#ifndef Arc_hpp
#define Arc_hpp
#include "Sommet.hpp"
using namespace std;

class Arc
{
  friend class Graphe;
  friend class Sommet
private:
  Sommet* m_som_debut;
  Sommet* m_som_fin;
  float m_weight;
  int m_num_arc;
  bool m_actif;
  bool m_marque;



public :
  Arc(Sommet& s1, Sommet& s2, float weight, int num_arc); // constructeur
  ~Arc(); // destruction des pointeurs de sommets
};

#endif
