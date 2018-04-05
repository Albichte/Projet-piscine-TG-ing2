#ifndef ARC_H_INCLUDED
#define ARC_H_INCLUDED
#include "grman/grman.h"
#include "Sommet.h"
#include <iostream>

using namespace std;

class Sommet;
class Arc
{
  friend class Graphe;
  friend class Sommet;
private:
  Sommet* m_som_debut;
  Sommet* m_som_fin;
  float m_weight;
  int m_num_arc;
  bool m_actif;
  bool m_marque;
  //widgets pour allegro
  // Le WidgetEdge qui "contient" toute l'interface d'un arc
    grman::WidgetEdge m_arc;//top edge

    // Une boite pour englober les widgets de réglage associés
    grman::WidgetBox m_case;//boxedge

    // Un slider de visualisation/modification du poids valeur de l'arc
    grman::WidgetVSlider m_slider;//sliderweight

    // Un label de visualisation du poids de l'arc
    grman::WidgetText m_valeur;//labelweight

    grman::WidgetButton m_supprimer;//supprimer arc
public :
  Arc();//constructeur par defaut
  Arc(Sommet* s1, Sommet* s2, float weight, int num_arc,Graphe*graph); // constructeur surcharge
  Arc(Arc*copie);//constructeur par copie pour les widgets
  ~Arc(); // destruction des pointeurs de sommets

};

#endif // ARC_H_INCLUDED
