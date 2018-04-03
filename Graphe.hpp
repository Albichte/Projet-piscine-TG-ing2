#ifndef Graphe_hpp
#define Graphe_hpp
#include "Sommet.hpp"
#include "Arc.hpp"
#include "Calcul.hpp"
#include <vector>
using namespace std;

class Sommet;
class Arc;

class Graphe
{
private:
  vector<Sommet> m_sommets;
  vector<Arc> m_arcs;
  int m_ordre;
  string m_nom;
public:
  Graphe(); /* par défaut lors de l'implémentation d'un nouveau graphe par un utilisateur */
  Graphe(string no_fich); // ouverture graphe
  ~Graphe(); // destruteur des vecteurs d'arcs et de sommets. Penser à appeler la sauvegarde.
  void reset_marquages_som();// fait un reset de marquages des sommets à false
  void reset_actif_som(); // fait un reset des valeur de actif de tous les sommets à true
  void reset_marquages_arc();// fait un reset de marquages des arcs à false
  void reset_actif_arc(); // fait un reset des valeur de actif de tous les arcs à true
  void sauvegarde();

};

#endif /* Graphe */
