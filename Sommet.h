#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include "grman/grman.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Arc;
class Graphe;
class Sommet
{
  friend class Graphe;
  friend class Arc;
  friend class Calcul;
  friend class Simulateur;
private:
  string m_nom_im;
  int m_num_sommet;
  vector <Sommet *>  m_prede;
  vector <Sommet *> m_succe;
  vector<Arc *> m_arc_adj;
  int m_deg; // = nb_succe + sb_prede
  bool m_actif;
  bool m_marque;
  int m_x , m_y; // coord allegro
  int m_stable; // stabilité de la population ou K
  int m_newstable;
  float m_N; // population ou biomasse
  float m_rythme; // correspond à r
  vector <float> m_N_histo; /* sauvegarde les valeurs de m_N lors d'une simulation */
  //widgets pour allegro
  grman::WidgetBox m_case;//boite qui bouge contenant tout
  grman::WidgetButton m_sommet_bt;//options du sommet
  grman::WidgetImage m_sommet_im;//image correspondante
  grman::WidgetVSlider m_slider;//slider associé slidervalue
  grman::WidgetText m_valeur;//valeur du slider labelvalue
  grman::WidgetButton m_supprimer;//supprimer sommet
  grman::WidgetText m_numero;//indice du sommet


public:
  Sommet();//constructeur par defaut
  Sommet(string m_nom_im, int m_num_sommet, int deg, int x, int y, int k, int n, float r,Graphe*graph);
  Sommet(Sommet*copie);//constructeur par copie pour les widgets
  ~Sommet(); // destruction pointeurs voisins
  void evol_n1_som();  /*retourne la val de un+1, et stoque dans l'historique
  un et un+1 (pas grave si on stoque la même val 2* au même endroit */
  void reset_N_histo(); // on vide l'historique des valeurs de m_N


};


#endif // SOMMET_H_INCLUDED
