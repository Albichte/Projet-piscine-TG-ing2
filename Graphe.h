#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "grman/grman.h"
#include "Sommet.h"
using namespace std;

class Sommet;
class Arc;
class Menup;

class Graphe
{
    friend class Calcul;
    friend class Sommet;
    friend class Arc;
    friend class Menup;
    friend class Simulateur;

private:
    vector<Sommet *> m_sommets;
    vector<Arc *> m_arcs;
    int m_ordre;
    string m_nom;
    //widgets pour allegro
    grman::WidgetBox m_cadre;//element contenant tous les autres
    grman::WidgetBox m_barreoutil;//barre d'outils

    grman::WidgetButton m_menu;//retour au menu
    grman::WidgetImage m_menu_im;//image correspondante

    grman::WidgetButton m_sauvegarder;//sauvegarder le graphe
    grman::WidgetImage m_sauvegarder_im;//image correspondante

    grman::WidgetButton m_connexite;//etudier la forte connexite
    grman::WidgetImage m_connexite_im;//image correspondante

    grman::WidgetButton m_kconnexite;//etudier la k connexite
    grman::WidgetImage m_kconnexite_im;//image correspondante

    grman::WidgetButton m_simulation;//lancer la simulation de l'evolution
    grman::WidgetImage m_simulation_im;//image correspondante

    grman::WidgetButton m_nouveaus;//nouveau sommet
    grman::WidgetImage m_nouveaus_im;//image correspondante


    grman::WidgetButton m_nouveaua;//nouvel arc
    grman::WidgetImage m_nouveaua_im;//image correspondante

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
  void ajout_som();
  void supr_som(Sommet* s);
  void ajout_arc();
  void supr_arc(Arc* a);
  //actualiser les widgets
  int update();

  //fonctions de calcul
  vector<vector<Sommet *>> forte_connex(Graphe* graphique); /*marque les sommets pour les compo conn
  retourner un vector<vector<int* Somemts>> pour savoir les sommet qui font partie
  des compo connexes.*/
    int k_con(Graphe* graphique); // retourne le mini d'arêtes à déco pour casser la connexité
    void evol_n1_gene(int tps, Graphe* graphique);  /* exécuté toute les fonctions permettant de trouver un+1 en
  fonction de un.  tps correspond à la durée sur laquelle on fait la simulation */
    bool compo_con_inv(Graphe* graphique, Sommet* s_deb, Sommet* s_atrouv);
    void marq_vois(Sommet* s);
    vector<Sommet*>  compo_f_con_som(Graphe* graphique, Sommet* s1);
    bool connexe(Graphe* graphique);
    bool tt_possi(Graphe* graphique, int i);

};

#endif // GRAPHE_H_INCLUDED
