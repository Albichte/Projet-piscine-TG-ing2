#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "grman/grman.h"
#include "Sommet.h"
using namespace std;

class Sommet;
class Arc;

class Graphe
{
  friend class Calcul;
private:
  vector<Sommet> m_sommets;
  vector<Arc> m_arcs;
  int m_ordre;
  string m_nom;
  //widgets pour allegro
  grman::WidgetBox cadre;//element contenant tous les autres
  grman::WidgetBox barreoutil;//barre d'outils

  grman::WidgetButton chargerg;//charger un graphe
  grman::WidgetImage chargerg_im;//image correspondante

  grman::WidgetButton nouveaug;//nouveau graphe
  grman::WidgetImage nouveaug_im;//image correspondante

  grman::WidgetButton sauvegarder;//sauvegarder le graphe
  grman::WidgetImage sauvegarder_im;//image correspondante

  grman::WidgetButton connexite;//etudier la forte connexite
  grman::WidgetImage connexite_im;//image correspondante

  grman::WidgetButton kconnexite;//etudier la k connexite
  grman::WidgetImage kconnexite_im;//image correspondante

  grman::WidgetButton simulation;//lancer la simulation de l'evolution
  grman::WidgetImage simulation_im;//image correspondante

  grman::WidgetButton nouveaus;//nouveau sommet
  grman::WidgetImage nouveaus_im;//image correspondante

  grman::WidgetButton supprimers;//supprimer sommet
  grman::WidgetImage supprimers_im;//image correspondante

  grman::WidgetButton nouveaua;//nouvel arc
  grman::WidgetImage nouveaua_im;//image correspondante

  grman::WidgetButton supprimera;//supprimer arc
  grman::WidgetImage supprimera_im;//image correspondante

public:
  Graphe(); /* par d�faut lors de l'impl�mentation d'un nouveau graphe par un utilisateur */
  Graphe(string nom_fich); // ouverture graphe
  ~Graphe(); // destruteur des vecteurs d'arcs et de sommets. Penser � appeler la sauvegarde.
  void reset_marquages_som();// fait un reset de marquages des sommets � false
  void reset_actif_som(); // fait un reset des valeur de actif de tous les sommets � true
  void reset_marquages_arc();// fait un reset de marquages des arcs � false
  void reset_actif_arc(); // fait un reset des valeur de actif de tous les arcs � true
  void sauvegarde(string nom_fich);
  // ces 4 fonctions ajoutent et suppriment des arcs et des sommets
  void ajout_som(string m_nom_im, int m_num_sommet, int x, int y, int k, int n, float r);
  void supr_som(Sommet& s);
  void ajout_arc(Sommet& s1, Sommet& s2, float weight, int num_arc);
  void supr_arc(Arc& a);

};

#endif // GRAPHE_H_INCLUDED
