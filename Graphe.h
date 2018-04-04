#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "Sommet.h"
#include "Arc.h"
#include "Calcul.h"
#include <vector>
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
public:
  Graphe(); /* par d�faut lors de l'impl�mentation d'un nouveau graphe par un utilisateur */
  Graphe(string nom_fich); // ouverture graphe
  ~Graphe(); // destruteur des vecteurs d'arcs et de sommets. Penser � appeler la sauvegarde.
  void reset_marquages_som();// fait un reset de marquages des sommets � false
  void reset_actif_som(); // fait un reset des valeur de actif de tous les sommets � true
  void reset_marquages_arc();// fait un reset de marquages des arcs � false
  void reset_actif_arc(); // fait un reset des valeur de actif de tous les arcs � true
  void sauvegarde(string nom_fich);

};

#endif // GRAPHE_H_INCLUDED
